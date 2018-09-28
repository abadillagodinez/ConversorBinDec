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
    double convertToDec();
    string convertToBin(int bitsPrecision);
    string binToString(DobleList<char>* list);
    int getEntire();
    double getFract();
    DobleList<int>* digitos;
private:
    DobleNode<int>* coma; //puntero al nodo que contendra el separador de la parte entera de la fraccionaria

};

#endif // BinaryExpression_H
