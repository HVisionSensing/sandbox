/**
 * @file surfKeyPoint.cpp
 * g++ -o surfKeyPoint surfKeyPoint.cpp -I/usr/include/opencv2 -I/usr/inlcude/opencv -I/usr/include/stlport -L/usr/lib -lopencv_highgui -lopencv_imgproc -lopencv_features2d -lopencv_core
 */

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>

/**
 * g++ 4.6.3では引数にconst宣言が必要. vc++はconstなしでもmakeは通る.
 */
static bool compare(const cv::KeyPoint& kp1, const cv::KeyPoint& kp2) {
	return kp1.size > kp2.size;
}

static void surfKeyPoint() {

	// load image file
	const char* fpath = "./data/lenna.jpg";
	cv::Mat orig = cv::imread(fpath, CV_LOAD_IMAGE_COLOR);
	if (orig.empty()) throw "image not opened";

	// resize & convert grayscale 
	cv::Mat color(640, 640*orig.cols/orig.rows, orig.type());
	cv::Mat gray;
	cv::resize(orig, color, color.size());
	cv::cvtColor(color, gray, CV_BGR2GRAY);

	// extract surf features
	vector<cv::KeyPoint> keyPoints;
	vector<float> descriptors;
	cv::SURF surf = cv::SURF();
	surf(gray, cv::Mat(), keyPoints, descriptors);

#if 1
	// sort key points
	sort(keyPoints.begin(), keyPoints.end(), compare);
#endif

	// draw key points
	std::vector<cv::KeyPoint>::const_iterator itr = keyPoints.begin();
	std::vector<cv::KeyPoint>::const_iterator itrEnd = keyPoints.end();
	for (int count = 1; itr != itrEnd; ++itr, ++count) {
		cv::circle(color, cv::Point(itr->pt.x, itr->pt.y),
				   itr->size * 0.25, cv::Scalar(0, 255, 255));
		cout << "count : " << count << " => " << itr->size << endl;
#if 1
		if (count == 100) break;
#endif
	}

	cv::namedWindow("SURF");
	cv::imshow("SURF", color);
	cv::waitKey(0);
}

int main() {
	try {
		surfKeyPoint();
	} catch (const char* message) {
		cout << message << endl;
	}
	return 0;
}
