/**
 * @file gaussianBlur.cpp
 * @compile g++ -o gaussianBlur gaussianBlur.cpp -I/usr/include/opencv2 -I/usr/inlcude/opencv -L/usr/lib -lopencv_core -lopencv_highgui -lopencv_imgproc
 */

/*
  ガウシアン平滑化を行う。トラックバーでパラメータの調整が可能
*/
#include <iostream>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#define WINDOW_NAME ("image")
string _path;
int _kernel_size = 0; 

/**
 * @brief トラックバーのスライダー動作時に呼ばれるコールバック関数
 */
void onChangeTrackBar(int /*arg*/, void *) {
	int kernel_size = (_kernel_size * 2) + 1;

	// load image
	cv::Mat src = cv::imread(_path, 1);
	if (!src.data) throw "cannot find image file";

	cv::Mat dst(src.size(), src.type());

	// ガウシアン平滑化をかける
	cv::GaussianBlur(src, dst, cv::Size(kernel_size, kernel_size), 0.0f, 0.0f);

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
		cv::createTrackbar("kernel size", WINDOW_NAME, &_kernel_size, 100, onChangeTrackBar);

		onChangeTrackBar(0, 0);
		cv::waitKey(0);
	} catch (const char* message) {
		cout << message << endl;
	}
	return 0;
}


