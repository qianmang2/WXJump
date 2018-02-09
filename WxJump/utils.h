#pragma once
#include "QProcess"
#include "QString"
#include "opencv2/opencv.hpp"
#include "iostream"
#include "QLabel"
#include "QImage"
using namespace cv;
using namespace std;

class Utils{
public:
	Utils();
	~Utils();
	void exeCmd(QString CMD);
	void drawPoint(Mat &inputImage, Point point, Scalar color = Scalar(0,0,255));
	void displayResult(QLabel *resultImageLabel, Mat &image);
	void edge(Mat inputImage, Mat &outputImage);

	void cut(Mat &inputImage, Mat &outputImage, Range  &startRange, Range endRange = Range::all());

	//获取下一目标位置的顶点坐标
	void findTopPoint(Mat &inputImage, Point &potion, Rect subtracArea = Rect(), uchar minThreshold = 127);

	//获取下一目标位置的最左边或最右边的坐标
	void findAnotherPoint(Mat &inputImage, Point &potion, Point characterTopPoint, Point dstTopPoint, uchar minThreshold = 127);

	bool isLeftDst(int characterPointX, int dstPointX); //判断目标位置是否在左边
	float distance(Point p1, Point p2);

	void longClick(int time);

private:
	QProcess *process ;
};