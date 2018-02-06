#include "utils.h"
#include "QDebug"
#include "cmath"
#include "opencv2/opencv.hpp"
#include "iostream"

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


void Utils::drawCharater(Mat &inputImage, Point point, Scalar color) {
	//画圆形
	circle(inputImage, point, 2, color, 2, LINE_AA);
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

//获取图像边缘
void Utils::edge(Mat inputImage, Mat &outputImage) {
	Mat temp;
	
	//imshow("temp1", temp);
	cvtColor(inputImage, temp, CV_BGR2HSV_FULL);
	for (int row = 0; row < temp.rows; row++) {
		for (int col = 0; col < temp.cols; col++) {
			int h = temp.at<Vec3b>(row, col)[0];
			int s = temp.at<Vec3b>(row, col)[1];
			int v = temp.at<Vec3b>(row, col)[2];

				//qDebug() << "h=" << h << "s=" << s << "v=" << v;
			
	/*			if (v >= 255) {
				temp.at<Vec3b>(row, col)[0] = 0;
				temp.at<Vec3b>(row, col)[1] = 0;
				temp.at<Vec3b>(row, col)[2] = 0;
			}*/

			if ( h >= 36 && h <= 240) {
				if (10 <= s && s <= 127) {
					if ( (232 <= v && v <= 255) || 165 <= v && v <= 178) {
						temp.at<Vec3b>(row, col)[0] = 0;
						temp.at<Vec3b>(row, col)[1] = 0;
						temp.at<Vec3b>(row, col)[2] = 0;
					}
				}
			}




		}
	}
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	morphologyEx(temp, temp, CV_MOP_OPEN, kernel);

	imshow("temp1" ,temp);
	medianBlur(temp, temp, 5);
	Canny(temp, outputImage, 58, 50);
	imshow("temp2", outputImage);

}

//判断目标位置是否在左边
bool Utils::isLeftDst(int characterPointX, int dstPointX) {
	return dstPointX < characterPointX ? true : false;
}


//查找最顶端的点
void Utils::findTopPoint(Mat &inputImage, Point &potion, Rect subtracArea, uchar minThreshold) {
	Mat temp;
	edge(inputImage, temp);

	qDebug() << subtracArea.br().x << " -------------- " << temp.cols;
	for (unsigned int row = temp.rows * 0.25; row < subtracArea.br().y; row++) {
		//subtracArea.tl().x 为小人的左上方的x坐标   subtracArea.br().x
		for (unsigned int col = 10; col < temp.cols - 10;) {

			uchar pix = temp.at<uchar>(row, col);
			if (pix > minThreshold) {
				potion.x = col;
				potion.y = row;
				
				return;
			}

			//不查找小人位值在竖直方向上的最高点
			if (col > subtracArea.tl().x - 10 && col < subtracArea.br().x + 10) {
				col += subtracArea.width;
			}
			col++;
		}
	}
}

//参数2下一目标位置的另一个边缘坐标点， 参数三：小人的坐标点， 参数四： 目标位置的顶点
void Utils::findAnotherPoint(Mat &inputImage, Point &potion, Point characterBottomCenter, Point dstTopPoint, uchar minThreshold) {

	Mat edgeImage;
	edge(inputImage, edgeImage);

	if (isLeftDst(characterBottomCenter.x, dstTopPoint.x)) { //如果下一目标位值在小人左边

		//取2是因为最左边的点不可能小于2，提高效率
		for (int col = 2; col < dstTopPoint.x; col++) { //只需遍历10 到最高点的x点坐标范围内

			for (int row = dstTopPoint.y + 5; row < characterBottomCenter.y - 5; row++) { //只需遍历 最高点的y坐标到 小人的最低坐标

				uchar pix = edgeImage.at<uchar>(row, col);
				if (pix > minThreshold) {
					potion.x = col;
					potion.y = row;
					return;
				}
			}
		}
	}
	else {  //如果下一目标位值在小人右边
		//取2是因为最左边的点不可能小于2，提高效率
		for (int col = inputImage.cols -5 ; col > dstTopPoint.x + 5; col--) { //只需遍历10 到最高点的x点坐标范围内

			for (int row = dstTopPoint.y + 5; row < characterBottomCenter.y - 5; row++) { //只需遍历 最高点的y坐标到 小人的最低坐标
				
				uchar pix = edgeImage.at<uchar>(row, col);
				if (pix > minThreshold) {
					potion.x = col;
					potion.y = row;
					qDebug() << "next_dst_in_right=" << potion.x << "--" << potion.y;
					drawCharater(inputImage, potion, Scalar(0, 255, 0));
					return;
				}
			}
		}

		//cvtColor(outputImage, outputImage, CV_HSV2BGR);
		//Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		//morphologyEx(outputImage, outputImage, CV_MOP_CLOSE, kernel, Point(-1, -1));
		//medianBlur(outputImage, outputImage, 5);
		//Canny(outputImage, cannyImage, 34, 162);
		//vector<vector<Point>> contours;
		//vector<Vec4i> hierarchy;
		//findContours(cannyImage, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point());

		//Mat temp = Mat::zeros(inputImage.size(), CV_8UC1);

		//RNG rng = RNG(222);
		//for (int i = 0; i < contours.size(); i++) {
		//	Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		//	drawContours(temp, contours, i, Scalar(255, 255, 255), 2, LINE_AA);
		//}
		//erode(temp, temp, kernel);
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
