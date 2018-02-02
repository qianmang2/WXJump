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
	Mat inputImage; //ԭͼ��
	Mat character; //С�˵�ģ��
	Mat cutImage;
	Point characterPosition; //С�˵�λֵ
	Point topPosition; //��˵�����

};