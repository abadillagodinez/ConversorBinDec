#include "mainwindow.h"
#include "Expression.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Expression *ex = new Expression("12,1268");
    ex->convertToBin(15);

    return a.exec();
}
