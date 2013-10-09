/**
 * @file exposureCompensation.cpp
 * @compile g++ -o exposureCompensation exposureCompensation.cpp -I/usr/include/opencv2 -I/usr/inlcude/opencv -L/usr/lib -lopencv_core -lopencv_highgui -lopencv_imgproc
 */

/*
  輝度と[min,max]を[0,nsmax]になるように補完することで、
  自動で露出補正(レベル補正)を行う
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

#if 1
	// ヒストグラムの均一化
	cv::equalizeHist(planes[0], planes[0]);
#else
	// 輝度の最小・最大値を取得
	double minValue, maxValue;
	cv::minMaxLoc(planes[0], &minValue, &maxValue);
	cout << "min=" << minValue << ",max=" << maxValue << endl;
	if (minValue == maxValue) throw "unexpected image data";

	// 補正する
	// (1) 輝度がminから5%未満のものはminに丸める
	const double minThresh = minValue + 0.05f * (maxValue - minValue); 
	for (int y = 0; y < planes[0].rows; ++y) {
		for (int x = 0; x < planes[0].cols; ++x) {
			if (planes[0].at<uchar>(y,x) < (uchar)minThresh) {
				planes[0].at<uchar>(y,x) = cv::saturate_cast<uchar>(minValue);
			}
		}
	}

	// (2) 輝度範囲を[min..max]→[0..nsmax]に変更
	//  計算式は m(x,y) = (m(x,y)-min) * nsmax / (max-min) 
	const double nsmax = 255.0f;
	const double scaling = nsmax / (maxValue-minValue);
	const double delta = -nsmax * minValue / (maxValue-minValue);
	planes[0].convertTo(planes[0], planes[0].type(), scaling, delta);
#endif

	// 結果をマージする
	cv::Mat dst(src.size(), src.type());
	cv::merge(planes, yuv);
	cvtColor(yuv, dst, CV_YCrCb2BGR);

	cv::namedWindow("source", 0);
	cv::namedWindow("destination", 0);
	cv::imshow("source", src);
	cv::imshow("destination", dst);
	cv::waitKey(0);

#if 1
	vector<int> params = vector<int>(2);
	params[0] = CV_IMWRITE_JPEG_QUALITY;
	params[1] = 95;
	cv::imwrite("result.jpg", dst, params);
#endif
	return 0;
}
