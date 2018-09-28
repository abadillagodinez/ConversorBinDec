#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    operacion = false; //Se inicializa de binario a decimal
    ui->lblBitsPrecision->setVisible(false);
    ui->sbxBitsPrecision->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnInvertirES_clicked()
{
    operacion = !operacion;
    if(operacion)
    {
        ui->lblTipoEntrada->setText("Decimal");
        ui->lblTipoSalida->setText("Binario");
        ui->lblBitsPrecision->setVisible(true);
        ui->sbxBitsPrecision->setVisible(true);
    }
    else
    {
        ui->lblTipoEntrada->setText("Binario");
        ui->lblTipoSalida->setText("Decimal");
        ui->lblBitsPrecision->setVisible(false);
        ui->sbxBitsPrecision->setVisible(false);
    }
}

void MainWindow::on_btnConvertir_clicked()
{
    if(ui->txfEntrada->text() != "")
    {
        Expression *ex = new Expression(ui->txfEntrada->text().toStdString());
        if(!operacion)
        {
            double result = ex->convertToDec();
            ui->txfSalida->setText(QString::number(result));
        }
        else
        {
            string result = ex->convertToBin(ui->sbxBitsPrecision->value());
            ui->txfSalida->setText(QString::fromStdString(result));

        }
    }
    else
    {
        QMessageBox::information(this, tr("Error"), tr("Tiene que ingresar un numero"));
    }
}
