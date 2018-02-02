#include "utils.h"
#include "QDebug"
#include "cmath"
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;


Utils::Utils() {
	
}
//执行命令
void Utils::exeCmd(QString cmd) {
	QProcess process;
	process.start(cmd);
	process.waitForStarted();
	process.waitForFinished();
}

//裁剪图片
void Utils::cut(Mat &inputImage, Mat &outputImage, Range  &startRange, Range endRange) {
	outputImage = Mat::Mat(inputImage, startRange, endRange);
}


void Utils::drawCharater(Mat &inputImage, Point point) {
	qDebug() << point.x << " " << point.y;
	//画圆形
	circle(inputImage, point, 2, Scalar(0, 0, 255), 2, LINE_AA);
}

//长按跳跃
void Utils::longClick(int time) {
	RNG rng = RNG(222);
	int x1 = rng.uniform(200, 600);
	int y1 = rng.uniform(500, 700);

	int x2 = x1 + rng.uniform(10, 30);
	int y2 = y1 + rng.uniform(10, 30);
	QString cmd = "adb shell input swipe ";
	cmd.append(QString::number(x1)).append(" ").append(QString::number(y1)).append(" ").append(QString::number(x2)).append(" ").append(QString::number(y2)).append(" ").append(QString::number(time));
	qDebug() << cmd;
	exeCmd(cmd);
}

void Utils::edge(Mat inputImage, Mat &outputImage) {
	Mat temp;
	GaussianBlur(inputImage, temp, Size(3, 3), 1);
	Canny(temp, outputImage, 58, 50);
}

//查找最顶端的点 offset为竖直方向上的矫正
void Utils::findTopPoint(Mat &inputImage, Point &potion, int minThreshold, int offset) {
	Mat temp;
	edge(inputImage, temp);
	for (unsigned int row = temp.rows * 0.25; row < temp.rows; row++ ) {
		for (unsigned int col = 5; col < temp.cols - 5; col++ ) {
			int pix = temp.at<uchar>(row,col);
			if (pix > minThreshold) {
				potion.x = col;
				potion.y = row + offset;
				qDebug() << potion.x << "--" << potion.y;
				drawCharater(inputImage, potion);
				return;
			}
		}
	}
}

unsigned int Utils::distance(Point p1, Point p2) {
	float dX = (p1.x - p2.x) * (p1.x - p2.x);
	float dY = (p1.y - p2.y) *(p1.y - p2.y);
	return (int)sqrt(dX + dY);
}

//将Mat显示到QLabel中
void Utils::displayResult(QLabel *resultImageLabel, Mat &image) {   //show the resultImage in result area;
	Mat rgb;
	QImage scaledImg;
	QImage img;
	if (image.channels() == 3)    // RGB image
	{
		cvtColor(image, rgb, CV_BGR2RGB);
		img = QImage((const uchar*)(rgb.data),  //(const unsigned char*)
			rgb.cols, rgb.rows,
			rgb.cols*rgb.channels(),   //解决Mat图像与QImage图像不对齐问题
			QImage::Format_RGB888);
		scaledImg = img.scaled(resultImageLabel->size(), Qt::IgnoreAspectRatio);

	}
	else {                     // gray imag  
		img = QImage((const uchar*)(image.data),
			image.cols, image.rows,
			image.cols*image.channels(),    //解决Mat图像与QImage图像不对齐问题
			QImage::Format_Indexed8);
		scaledImg = img.scaled(resultImageLabel->size(), Qt::IgnoreAspectRatio);
	}
	resultImageLabel->setPixmap(QPixmap::fromImage(scaledImg));
	resultImageLabel->show();
}

Utils::~Utils() {
	if (process != NULL) {
		process = NULL;
		delete process;
	}
}
