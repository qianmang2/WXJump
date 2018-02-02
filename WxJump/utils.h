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
	void drawCharater(Mat &inputImage, Point point);
	void displayResult(QLabel *resultImageLabel, Mat &image);
	void edge(Mat inputImage, Mat &outputImage);
	void cut(Mat &inputImage, Mat &outputImage, Range  &startRange, Range endRange = Range::all());
	void findTopPoint(Mat &inputImage, Point &potion, int minThreshold = 127, int offset = 0);
	unsigned int distance(Point p1, Point p2);
	void longClick(int time);

private:
	QProcess *process ;
};