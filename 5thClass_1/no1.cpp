#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat kernel=getStructuringElement(MORPH_RECT, Size(3,3), Point(-1, 1));
	Mat dst1;
	Mat dst2;
	Mat dst3;
	Mat dst4;
	Mat srcMat = imread("C:/Users/hp/Desktop/4.jpg", 0);
	threshold(srcMat, dst1, 100, 255, THRESH_BINARY);
	threshold(srcMat, dst2, 100, 255, THRESH_BINARY);
	threshold(srcMat, dst3, 100, 255, THRESH_BINARY);
	threshold(srcMat, dst4, 100, 255, THRESH_BINARY);
	erode(dst1, dst1, kernel,Point(-1, -1),
		       1, BORDER_CONSTANT,
		       morphologyDefaultBorderValue());
	
	dilate(dst2,  dst2,  kernel, Point(-1, -1),
		 1,  BORDER_CONSTANT,
		morphologyDefaultBorderValue());
	
	morphologyEx(dst3,  dst3, 2, kernel,  Point(-1, -1),
		BORDER_CONSTANT);
	
	morphologyEx(dst4, dst4,3,  kernel, Point(-1, -1),
		 BORDER_CONSTANT);
    
	imshow("∏Ø ¥", dst1);
	imshow("≈Ú’Õ", dst2);
	imshow("ø™‘ÀÀ„", dst3);
	imshow("±’‘ÀÀ„", dst4);

	waitKey(0);
	return 0;

}
