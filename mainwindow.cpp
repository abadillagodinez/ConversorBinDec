#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <sstream>

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
            if(validarBin(ex))
            {
                if(validarFracBin(ex))
                {
                    stringstream ss;
                    string res;
                    long double result = ex->convertToDec();
                    ss << result;
                    ss >> res;
                    ui->txfSalida->setText(QString::fromStdString(res));
                }
                else
                    QMessageBox::information(this, tr("Error"), tr("Contiene más de 4 digitos fraccionarios\nesto puede generar fallas de precision."));
            }
            else
                QMessageBox::information(this, tr("Error"), tr("Este numero no es binario"));
        }/*if operacion*/
        else
        {
            if(validarDec(ex))
            {
                string result = ex->convertToBin(ui->sbxBitsPrecision->value());
                if(ui->sbxBitsPrecision->value() == 0) /*verificacion si la cantidad de bits de precision es 0*/
                    result.pop_back();
                ui->txfSalida->setText(QString::fromStdString(result));
            }
            else
                QMessageBox::information(this, tr("Error"), tr("Ese dato no es un numero"));
        }
    }/*if*/
    else
        QMessageBox::information(this, tr("Error"), tr("Tiene que ingresar un numero"));
}

bool MainWindow::validarBin(Expression *ex)
{
    DobleNode<int>* aux = ex->getComa()->getPrev();
    for(;aux; aux = aux->getPrev())
        if(aux->getDato() != 1 && aux->getDato() != 0)
            return false;
    aux = ex->getComa()->getNext();
    for(;aux; aux = aux->getNext())
        if(aux->getDato() != 1 && aux->getDato() != 0)
            return false;
    return true;
}


bool MainWindow::validarDec(Expression *ex)
{
    DobleNode<int>* aux = ex->getComa()->getPrev();
    for(;aux; aux = aux->getPrev())
        if(aux->getDato() > 9 || aux->getDato() < 0)
            return false;
    aux = ex->getComa()->getNext();
    for(;aux; aux = aux->getNext())
        if(aux->getDato() > 9 || aux->getDato() < 0)
            return false;
    return true;
}

bool MainWindow::validarFracBin(Expression *ex)
{
    int cont = 0;
    DobleNode<int>* aux = ex->getComa()->getNext();
    while(aux)
    {
        cont++;
        aux = aux->getNext();
    }
    return cont <= 4;
}
