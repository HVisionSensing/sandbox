/**
 * @file bilateralFilter.cpp
 * @compile g++ -o bilateralFilter bilateralFilter.cpp -I/usr/include/opencv2 -I/usr/inlcude/opencv -L/usr/lib -lopencv_core -lopencv_highgui -lopencv_imgproc
 */

/*
  バイリテラルフィルタ処理を行う。トラックバーでパラメータの調整が可能
*/
#include <iostream>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#define WINDOW_NAME ("image")
string _path;
int _sigma_color;
int _sigma_space;

/**
 * @brief トラックバーのスライダー動作時に呼ばれるコールバック関数
 */
void onChangeTrackBar(int /*arg*/, void *) {
	double sigma_color = cv::saturate_cast<double>(_sigma_color);
	double sigma_space = cv::saturate_cast<double>(_sigma_space);

	// load image
	cv::Mat src = cv::imread(_path, 1);
	if (!src.data) throw "cannot find image file";

	cv::Mat dst(src.size(), src.type());

	// バイラテラルフィルタをかける
	cv::bilateralFilter(src, dst, 11, sigma_color, sigma_space);

	cv::imshow(WINDOW_NAME, dst);
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
		cv::namedWindow(WINDOW_NAME, 0);
		cv::createTrackbar("color sigma", WINDOW_NAME, &_sigma_color, 100, onChangeTrackBar);
		cv::createTrackbar("space sigma", WINDOW_NAME, &_sigma_space, 100, onChangeTrackBar);

		onChangeTrackBar(0, 0);
		cv::waitKey(0);
	} catch (const char* message) {
		cout << message << endl;
	}
	return 0;
}


