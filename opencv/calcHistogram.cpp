/**
 * @file calcHistogram.cpp
 * @compile g++ -o calcHistogram calcHistogram.cpp -I/usr/include/opencv2 -I/usr/inlcude/opencv -I/usr/include/stlport -L/usr/lib -lopencv_core -lopencv_highgui -lopencv_imgproc
 */

#include <iostream>
#include <stdexcept>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

static void run() {
	cv::Mat src = cv::imread("./data/lenna.jpg", 1);
	if (!src.data) throw "image not found";

	cv::Mat hsv;
	cvtColor(src, hsv, CV_BGR2HSV);

    // 色相を30分割レベルで，
    // 彩度を32分割レベルで量子化します
    int hbins = 64, sbins = 64;
    int histSize[] = {hbins, sbins};

    // cvtColorにあるように，色相の範囲は0から179です．
    float hranges[] = {0, 180};

    // 彩度の範囲は0（黒-灰色-白）から
    // 255（純粋なスペクトルカラー）までです．
    float sranges[] = {0, 256};
    const float* ranges[] = {hranges, sranges};
	cv::MatND hist;

    // 0番目と1番目のチャンネルからヒストグラムを求めます．
    int channels[] = {0, 1};

	cv::calcHist(&hsv, 1, channels, cv::Mat(), // マスクは利用しません
				 hist, 2, histSize, ranges,
				 true, // ヒストグラムは一様です
				 false);
	double maxVal = 0;
	cv::minMaxLoc(hist, 0, &maxVal, 0, 0);

    int scale = 10;
	cv::Mat histImg = cv::Mat::zeros(sbins*scale, hbins*10, CV_8UC3);

    for (int h = 0; h < hbins; ++h) {
        for (int s = 0; s < sbins; ++s) {
            float binVal = hist.at<float>(h, s);
            int intensity = cvRound(binVal*255/maxVal);
			cv::rectangle(histImg, cv::Point(h*scale, s*scale),
						  cv::Point( (h+1)*scale - 1, (s+1)*scale - 1),
						  cv::Scalar::all(intensity),
						  CV_FILLED);
        }
	}

	cv::namedWindow("Source", 1);
	cv::imshow("Source", src);

	cv::namedWindow("H-S Histogram", 1);
	cv::imshow("H-S Histogram", histImg);

	cv::waitKey(0);
}

int main() {
	try {
		run();
	} catch (const char* message) {
		cout << message << endl;
	}
	return 0;
}
