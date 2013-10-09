/**
 * @file gammaStabilization.cpp
 * @compile g++ -o gammaStabilization gammaStabilization.cpp -I/usr/include/opencv2 -I/usr/inlcude/opencv -I/usr/include/stlport -L/usr/lib -lopencv_highgui -lopencv_core
 */

#include <iostream>
#include <stdexcept>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#define WINDOW_NAME ("Gamma Stabilization")
string _path;
int _gamma = 10;

/**
 * @brief ガンマ補正
 */
static void gammaStabilization(cv::Mat& src, cv::Mat& dst, double gamma) {
	cv::Mat lut = cv::Mat(1, 256, CV_8UC1);
	for (int i = 0; i < 256; ++i) {
		lut.data[i] = (int)(pow(i/255.0f, 1.0f/gamma) * 255.0f);
	}
	cv::LUT(src, lut, dst);
}

/**
 * @brief トラックバーのスライダー動作時に呼ばれるコールバック関数
 */
void onChangeTrackBar(int /*arg*/, void *) {
	double gamma = (double)_gamma / 10.0f;

	cv::Mat src = cv::imread(_path, 1);
	if (!src.data) throw "image not found";

	cv::Mat dst = cv::Mat(cv::saturate_cast<int>(src.rows),
						  cv::saturate_cast<int>(src.cols), src.type());

	gammaStabilization(src, dst, gamma);

	ostringstream gammaStr;
	gammaStr << gamma;
	cv::putText(dst, "gamma = " + gammaStr.str(), cv::Point(10,30),
				cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(0,0,0), 1, CV_AA);
	cv::imshow(WINDOW_NAME, dst);
}

/**
 * @brief main function
 */
int main(int argc, const char* argv[]) {
	// パラメータ解析
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
		cv::namedWindow(WINDOW_NAME, 1);
		cv::createTrackbar("gamma", WINDOW_NAME, &_gamma, 100, onChangeTrackBar);

		onChangeTrackBar(0, 0);
		cv::waitKey(0);
	} catch (const char* message) {
		cout << message << endl;
	}
	return 0;
}
