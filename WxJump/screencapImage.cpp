#include "screencapImage.h"
#include "QThread"
#include "QDebug"
ScreencapImage::ScreencapImage(QLabel *qLabel) {
	utils = new Utils();
	imageLabel = qLabel;

	connect(this, &ScreencapImage::screencapfinish, [=]() {
		inputImage = imread("gamescreenshot.png");
		character = imread("character.png"); //获取小人
		initcharacterLocation(); //获取小人的坐标
		utils->drawCharater(inputImage, characterBottomCenter); //在小人的坐标出打点
		utils->findTopPoint(inputImage, topPosition, characterLocation); //获取目标顶点坐标
		utils->findAnotherPoint(inputImage, anotherPoint, characterBottomCenter,topPosition ); //获取下一目标位置的另一个边缘坐标

		qDebug() << "characterBottomCenter: x =" << characterBottomCenter.x << " y=" << characterBottomCenter.y;
		qDebug() << "nextCenterPoint: x =" << nextCenterPoint.x << " y=" << nextCenterPoint.y;

		nextCenterPoint = Point(topPosition.x, anotherPoint.y);
		utils->drawCharater(inputImage, nextCenterPoint);
		isLeftDst = utils->isLeftDst(characterBottomCenter.x, topPosition.x);
		utils->displayResult(imageLabel, inputImage);
	});
}

//槽函数
void ScreencapImage::showImage() {
	QThread::msleep(1000);
	utils->exeCmd("adb shell /system/bin/screencap -p /sdcard/screenshot.png");
	utils->exeCmd("adb pull /sdcard/screenshot.png ./gamescreenshot.png");
	emit screencapfinish();
}


//跳跃
void ScreencapImage::jump() {
	float distance = utils->distance(characterBottomCenter, nextCenterPoint);
	qDebug() << "distance" << distance;
	utils->longClick(distance * 2.02);
	emit jumpFinish();
}

//获取小人的底部中心位值 和 小人的左上端位值 characterPosition characterLeftTop
void ScreencapImage::initcharacterLocation() {
	if (inputImage.empty() || character.empty()) {
		return;
	}

	int width = inputImage.cols - character.cols + 1;
	int height = inputImage.rows - character.rows + 1;

	Mat result = Mat(height, width, CV_32FC1);
	int macthMethod = CV_TM_CCORR_NORMED; //匹配方式
	matchTemplate(inputImage, character, result, macthMethod);

	double minVal; double maxVal; Point minLoc; Point maxLoc;
	Point matchLoc;
	minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
	if (macthMethod == CV_TM_SQDIFF || CV_TM_SQDIFF_NORMED) {
		matchLoc = minLoc;
	}
	else {
		matchLoc = maxLoc;
	}

	characterLocation = Rect(matchLoc.x, matchLoc.y, character.cols, character.rows); //获取小人的位置
	int targetX = matchLoc.x + (character.cols >> 1);
	int targetY = matchLoc.y + character.rows;
	characterBottomCenter = Point(targetX, targetY); //小人的底部中心位值
}


ScreencapImage::~ScreencapImage() {

	if (utils != NULL) {
		delete utils;
		utils = NULL;
	}

	if (imageLabel != NULL) {
		delete imageLabel;
		imageLabel = NULL;
	}
}