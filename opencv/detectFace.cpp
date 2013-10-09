/**
 * @file detectFace.cpp
 * g++ -o detectFace detectFace.cpp -I/usr/include/opencv2 -I/usr/inlcude/opencv -L/usr/lib -lopencv_highgui -lopencv_imgproc -lopencv_objdetect -lopencv_core
 */
#include <iostream>
#include <stdexcept>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

static void detectFace() {
	// create window
	cv::namedWindow("detect face", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);

	// load image, convert grayscale and scaling
	cv::Mat img = cv::imread("./data/lenna.jpg", 1);
	if (!img.data) throw "image not opened";
		
	cv::Mat gray;
	cv::cvtColor(img, gray, CV_RGB2GRAY);
	const double scale = 4.0f;
	cv::Mat simg(cv::saturate_cast<int>(img.rows/scale),
				 cv::saturate_cast<int>(img.cols/scale), CV_8UC1);
	cv::resize(gray, simg, simg.size(), 0, 0, cv::INTER_LINEAR);
	cv::equalizeHist(simg, simg);
		
	// load cascade classfier
	cv::CascadeClassifier cc;
	if (!cc.load("./data/haarcascade_frontalface_alt2.xml"))
		throw "cascade classifier not opened";

	// detect face
	std::vector<cv::Rect> faces(10);
	cc.detectMultiScale(simg, faces, 1.1, 3, CV_HAAR_SCALE_IMAGE, cv::Size(30,30));

	// draw detected region
	std::vector<cv::Rect>::iterator face = faces.begin();
	for (int no = 1; face != faces.end(); ++face, ++no) {
		face->x *= cv::saturate_cast<int>(scale);
		face->y *= cv::saturate_cast<int>(scale);
		face->width *= cv::saturate_cast<int>(scale);
		face->height *= cv::saturate_cast<int>(scale);

		cout << "no #" << no << " = " << face->x << "," << face->y << ","
			 << face->width << "," << face->height << endl;

		cv::rectangle(img, face->tl(), face->br(), cv::Scalar(0,0,255), 2);
	}

	cv::imshow("detect face", img);
	cv::waitKey(0);
	return;
}

int main() {
	try {
		detectFace();
	} catch (const char* message) {
		cout << message << endl;
	}

	return 0;
}
