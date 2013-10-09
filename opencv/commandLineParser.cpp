/**
 * @file commandLineParser.cpp
 * @compile g++ -o commandLineParser commandLineParser.cpp -I/usr/include/opencv2 -I/usr/inlcude/opencv -L/usr/lib -lopencv_core
 */

#include <iostream>
#include <opencv2/core/core.hpp>
using namespace std;

#define OPENCV_VERSION(a,b,c) (((a) << 16) + ((b) << 8) + (c))
#define OPENCV_VERSION_CODE OPENCV_VERSION(CV_MAJOR_VERSION, CV_MINOR_VERSION, CV_SUBMINOR_VERSION)

int main(int argc, const char* argv[]) {
#if OPENCV_VERSION_CODE < OPENCV_VERSION(2,3,1)
	cout << "cannot support this opencv version : " << CV_VERSION << endl;
	return -1;
#else

	/* { : パーサー文字列の開始
	   } : パーサー文字列の終了
	   | : セパレーター
	  ショートネーム フルネーム デフォルト値 ヘルプ文 */
	const char *keys = {
		"{s|string  |123asd   |string parameter}"
		"{d|digit   |100      |digit parameter}"
		"{c|noCamera|false    |without camera}"
		"{1|        |some text|something of text}"
		"{2|        |3.3      |something of number}"
	};

	cv::CommandLineParser parser(argc, argv, keys);
	if (argc == 1) {
		parser.printParams(); // ヘルプ文が出力
		return 0;
	}

	/* 値を取るパラメーター引数
	   int param_d = parser.get<int>("digit")
	   のようにフルネームで書くこともできます */
	std::string param_s = parser.get<std::string>("string");
	int param_d = parser.get<int>("d");
	bool param_c = parser.get<bool>("c");

	/* 値を取らない引数 */
	std::string arg1 = parser.get<std::string>("1");
	double arg2 = parser.get<double>("2");

	cout << "string   = " << param_s << endl;
	cout << "digit    = " << param_d << endl;
	cout << "noCamera = " << param_c << endl;
	cout << "arg1     = " << arg1 << endl;
	cout << "arg2     = " << arg2 << endl;

	return 0;
#endif
}
