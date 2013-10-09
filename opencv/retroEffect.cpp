/**
 * @file retroEffect.cpp
 * @compile g++ -o retoroEffect retroEffect.cpp -I/usr/include/opencv2 -I/usr/inlcude/opencv -L/usr/lib -lopencv_core -lopencv_highgui -lopencv_imgproc
 */

/*
  輝度チャネルにノイズを加え、彩度チャネルの値を減らすことで
  かんたんなレトロ風の写真効果を与える。
*/

#include <iostream>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

string _path;

int main(int argc, const char* argv[]) {
	// parse arguments
	const char* keys = {
		"{1|||path of image file}"
	};
	cv::CommandLineParser parser(argc, argv, keys);
	if (argc == 1) {
		parser.printParams();
		return -1;
	}
	_path = parser.get<string>("1");

	// load image file
	cv::Mat src = cv::imread(_path, 1);
	if (!src.data) throw "cannot find image file";

	// YCrCb変換しプレーン分解
	cv::Mat yuv;
	cvtColor(src, yuv, CV_BGR2YCrCb);
	vector<cv::Mat> planes;
	split(yuv, planes);

	// 正規分布する乱数値で埋めたMatrixを生成
	cv::Mat noise(src.size(), CV_8U);
	cv::randn(noise, cv::Scalar::all(128), cv::Scalar::all(20));

	// ノイズを少し平滑化 (カーネルサイズは3x3、シグマは0.5に設定)
	cv::GaussianBlur(noise, noise, cv::Size(3,3), 0.5, 0.5);

	//  cv::addWeighted(src1, alpha, src2, beta, gammna, dst)
	//  を使いノイズを付与する.
	//  計算式は、dst(i) = saturate(src1(i)*alpha + src2(i)*beta + gamma)
	//  iは行列要素の多次元インデックス
	const double constrastGain = 1.7f;
	const double brightnessGain = 0.0f;
	cv::addWeighted(planes[0], constrastGain, noise, 1, -128+brightnessGain, planes[0]);

	// 彩度の値を[0..128]の範囲に減らす
	//  comvertToはスケーリングを行うためのメソッド
	//  comvertTo(m, rtype, alpha, beta) で
	//    m(x,y) = saturate_cast<rtype>(α(*this)(x,y)+β) 
	//  となる
	const double colorScale = 0.5f;
	planes[1].convertTo(planes[1], planes[1].type(),
						colorScale, 128 * (1-colorScale));
	planes[2].convertTo(planes[1], planes[2].type(),
						colorScale, 128 * (1-colorScale));

	// 結果をマージする
	cv::Mat dst(src.size(), src.type());
	cv::merge(planes, yuv);
	cvtColor(yuv, dst, CV_YCrCb2BGR);

	cv::namedWindow("source", 1);
	cv::namedWindow("destination", 1);
	cv::imshow("source", src);
	cv::imshow("destination", dst);
	cv::waitKey(0);
	return 0;
}
