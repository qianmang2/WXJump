#include "WxJump.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WxJump w;
	w.setWindowTitle(QString::fromLocal8Bit("��һ������ By:Ǯ��"));
	w.show();
	return a.exec();
}
