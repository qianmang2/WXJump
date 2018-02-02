#include "screencapImage.h"
#include "QDebug"
ScreencapImage::ScreencapImage() {
	utils = new Utils();

	connect(this, &ScreencapImage::screencapfinish, [=]() {
		inputImage = imread("gamescreenshot.png");
		character = imread("character.png"); //��ȡС��
		getCharacter(); //��ȡС�˵�����
		utils->drawCharater(inputImage, characterPosition); //��С�˵���������
		utils->findTopPoint(inputImage, topPosition, 127, 40); //��ȡĿ�������
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

//��ȡС�˵�λֵ
void ScreencapImage::getCharacter() {
	if (inputImage.empty() || character.empty()) {
		return;
	}

	int width = inputImage.cols - character.cols + 1;
	int height = inputImage.rows - character.rows + 1;

	Mat result = Mat(height, width, CV_32FC1);
	int macthMethod = CV_TM_CCORR_NORMED; //ƥ�䷽ʽ
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