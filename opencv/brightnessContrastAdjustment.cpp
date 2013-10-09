/**
 * @file brightnessContrastAdjustment.cpp
 * @compile g++ -o brightnessContrastAdjustment brightnessContrastAdjustment.cpp -I/usr/include/opencv2 -I/usr/inlcude/opencv -L/usr/lib -lopencv_core -lopencv_highgui -lopencv_imgproc
 */

/*
  トラックバーで明るさ(brightness)・コントラスト(contrast)を調整する
*/

#include <iostream>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#define IMAGE_WINDOW_NAME ("image")
#define HIST_WINDOW_NAME ("histogram")

string _path;
int _brightness = 100;
int _contrast = 100;

/**
 * @brief トラックバーのスライダー動作時に呼ばれるコールバック関数
 * アルゴリズムは http://visca.com/ffactory/archives/5-99/msg00021.html を参照
 */
void onChangeTrackBar(int /*arg*/, void *) {
	int brightness = _brightness - 100;
	int contrast = _contrast - 100;

	// load image file
	cv::Mat src = cv::imread(_path, 1);
	if (!src.data) throw "cannot find image file";

	// RGBをプレーン分解
	vector<cv::Mat> planes;
	split(src, planes);

	double a, b;
	if (contrast > 0) {
		double delta = 127.0f * contrast / 100;
		a = 255.0f / (255.0f - delta * 2);
		b = a * (brightness - delta);
	} else {
		double delta = -128.0f * contrast / 100;
		a = (256.0f - delta * 2) / 255.0f;
		b = a * brightness + delta;
	}
	planes[0].convertTo(planes[0], CV_8U, a, b);
	planes[1].convertTo(planes[1], CV_8U, a, b);
	planes[2].convertTo(planes[2], CV_8U, a, b);

	// 結果をマージする
	cv::Mat dst(src.size(), src.type());
	cv::merge(planes, dst);
	cv::imshow(IMAGE_WINDOW_NAME, dst);

	// ヒストグラム表示用に画像をYCbCrに変換する
	cv::Mat yuv;
	cvtColor(dst, yuv, CV_BGR2YCrCb);
	vector<cv::Mat> yuvPlanes;
	split(yuv, yuvPlanes);

	// ヒストグラムを算出
	cv::Mat hist;
	int dims = 1;
	const int histSize[] = {255};
	const float ranges[] = {0,256};
	const float* histRanges[] = {ranges};
	cv::calcHist(&yuvPlanes[0], 1, 0, cv::Mat(),
				 hist, 1, histSize, histRanges);
	double max;
	cv::minMaxLoc(hist, 0, &max);
	hist *= histSize[0] / max;

	// ヒストグラムを描画
	cv::Mat histImage(histSize[0], histSize[0], CV_8UC3, cv::Scalar::all(255));
	for (int i = 0; i < histSize[0]; ++i) {
		cv::rectangle(histImage,
					  cv::Point(i, (histSize[0]-hist.at<float>(i))),
					  cv::Point(i+1, histSize[0]),
					  cv::Scalar::all(100), -1);
	}
	cv::imshow(HIST_WINDOW_NAME, histImage);
}

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

	// 実処理
	try {
		cv::namedWindow(IMAGE_WINDOW_NAME, 0);
		cv::namedWindow(HIST_WINDOW_NAME, 0);
		cv::createTrackbar("brightness", IMAGE_WINDOW_NAME, &_brightness, 200, onChangeTrackBar);
		cv::createTrackbar("contrast", IMAGE_WINDOW_NAME, &_contrast, 200, onChangeTrackBar);

		onChangeTrackBar(0, 0);
		cv::waitKey(0);
	} catch (const char* message) {
		cout << message << endl;
	}
	return 0;
}

 
