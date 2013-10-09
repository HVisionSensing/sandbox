/**
 * @file showHistogram.cpp
 */

#include <iostream>
#include <stdexcept>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

static void run() {
	cv::Mat src = cv::imread("./data/lenna.jpg", 1);
	if (!src.data) throw "image not found";

	cv::Mat dst = cv::Mat(cv::saturate_cast<int>(src.rows),
						  cv::saturate_cast<int>(src.cols), src.type());

	
}
