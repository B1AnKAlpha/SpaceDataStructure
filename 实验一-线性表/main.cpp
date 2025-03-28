#include "widget.h"
#include <QProcess>
#include <QApplication>
#define MAX 100
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();

}
