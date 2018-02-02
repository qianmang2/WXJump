#include "screencapImage.h"
#include "QDebug"
ScreencapImage::ScreencapImage() {
	utils = new Utils();

	connect(this, &ScreencapImage::screencapfinish, [=]() {
		inputImage = imread("gamescreenshot.png");
		character = imread("character.png"); //获取小人
		getCharacter(); //获取小人的坐标
		utils->drawCharater(inputImage, characterPosition); //在小人的坐标出打点
		utils->findTopPoint(inputImage, topPosition, 127, 40); //获取目标点坐标
		emit picInitFinish(inputImage);

		unsigned int distance = utils->distance(topPosition, characterPosition);
		qDebug() << "distance" << distance;
		utils->longClick(distance * 1.9);
	});
}

void ScreencapImage::run() {
	utils->exeCmd("adb shell /system/bin/screencap -p /sdcard/screenshot.png");
	utils->exeCmd("adb pull /sdcard/screenshot.png ./gamescreenshot.png");
	emit screencapfinish();
}

//获取小人的位值
void ScreencapImage::getCharacter() {
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

	int targetX = matchLoc.x + (character.cols >> 1);
	int targetY = matchLoc.y + character.rows;
	characterPosition = Point(targetX, targetY);
}


ScreencapImage::~ScreencapImage() {

	if (utils != NULL) {
		utils = NULL;
		delete utils;
	}
}