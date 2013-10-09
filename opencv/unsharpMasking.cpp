/**
 * @brief unsharpMasking.cpp
 * @compile g++ -o unsharpMasking unsharpMasking.cpp -I/usr/include/opencv2 -I/usr/inlcude/opencv -L/usr/lib -lopencv_core -lopencv_highgui -lopencv_imgproc
 */

/*
  アンシャープマスク処理を行う。トラックバーでパラメータの調整が可能
*/
#include <iostream>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#define WINDOW_NAME ("image")
string _path;
int _strength = 1;

static void unsharpMask(cv::Mat& src, cv::Mat& dst, float k) {
	// カーネルボックスの作成
	float data[] =  {
		-k/9.0f, -k/9.0f,      -k/9.0f,
		-k/9.0f, 1+(8*k)/9.0f, -k/9.0f,
		-k/9.0f, -k/9.0f,      -k/9.0f,
	};
	cv::Mat kernel = cv::Mat(3,3,CV_32F,data);

	// 畳込み処理
	cv::filter2D(src, dst, src.depth(), kernel);
}

/**
 * @brief トラックバーのスライダー動作時に呼ばれるコールバック関数
 */
void onChangeTrackBar(int /*arg*/, void *) {
	float strength = (float)_strength / 10.0f;

	// load image file
	cv::Mat src = cv::imread(_path, 1);
	if (!src.data) throw "cannot find image file";

	cv::Mat dst(src.size(), src.type());

	// アンシャープマスクをかける
	unsharpMask(src, dst, strength);

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
		cv::createTrackbar("strength", WINDOW_NAME, &_strength, 100, onChangeTrackBar);

		onChangeTrackBar(0, 0);
		cv::waitKey(0);
	} catch (const char* message) {
		cout << message << endl;
	}
	return 0;
}
