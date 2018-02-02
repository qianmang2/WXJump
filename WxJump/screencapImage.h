#pragma once
#include "QThread"
#include "QProcess"
#include "utils.h"
class ScreencapImage :public QThread{

	Q_OBJECT
public:
	ScreencapImage();
	~ScreencapImage();
	void getCharacter();
	void run();

signals:
	void screencapfinish();
	void picInitFinish(Mat &image);

private:
	Utils *utils;
	Mat inputImage; //原图像
	Mat character; //小人的模版
	Mat cutImage;
	Point characterPosition; //小人的位值
	Point topPosition; //最顶端的坐标

};