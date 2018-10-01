#ifndef Expression_H
#define Expression_H
#include "DoubleList.h"
#include "DobleNode.h"
#include <iostream>
#include <string.h>
#include <cmath>
#include <sstream>

using namespace std;

class Expression
{
public:
    Expression(string expresion);
    void PosicionarComa();
    long double convertToDec();
    string convertToBin(int bitsPrecision);
    string binToString(DobleList<char>* list);
    int getEntire();
    double getFract();
    DobleList<int>* getDigitos();
    DobleNode<int>* getComa();
private:
    DobleNode<int>* coma = 0; //puntero al nodo que contendra el separador de la parte entera de la fraccionaria
    DobleList<int>* digitos;

};

#endif // BinaryExpression_H
