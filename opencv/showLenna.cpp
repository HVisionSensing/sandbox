/**
 * showLenna.cpp
 */

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
	cv::Mat img = cv::imread("./data/lenna.jpg", 1);

	cv::namedWindow("Lenna", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::imshow("Lenna", img);
	cv::waitKey(0);

	return 0;
}
