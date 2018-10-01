#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Expression.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnInvertirES_clicked();

    void on_btnConvertir_clicked();

private:
    Ui::MainWindow *ui;
    bool operacion; //si es false, es de binario a decimal, true es lo contrario
    bool validarBin(Expression *ex);
    bool validarDec(Expression *ex);
};

#endif // MAINWINDOW_H
