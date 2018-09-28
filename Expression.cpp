#include "Expression.h"

Expression::Expression(string expresion)
{
    digitos = new DobleList<int>();
    for(int i = 0; i < expresion.size(); i++)
        digitos->insertAtTail(expresion[i] - '0');
    PosicionarComa();
}

void Expression::PosicionarComa()
{
    for(int i = 0; i < digitos->getSize(); i++)
    {
        if(digitos->getPos(i)->getDato() < 0)
            coma = digitos->getPos(i);
    }
    if(coma == 0)
    {
        digitos->insertAtTail(',' - '0');
        coma = digitos->getTail();
        digitos->insertAtTail(0);
        digitos->insertAtTail(0);
    }
}

/*metodo de conversion a decimal*/
double Expression::convertToDec()
{
    double sum = 0;
    DobleNode<int> *aux;
    aux = coma->getPrev();
    int pot = 0;


    /*PRIMERO LA SUMATORIA DE LA PARTE ENTERA*/
    while (aux)
    {
        sum += (aux->getDato() * pow(2,pot));
        pot++;
        aux = aux->getPrev();
    }

    /*SUMA DE LA PARTE FACCIONARIA*/
    aux = coma->getNext();
    pot = -1;
    while (aux)
    {
        sum += (aux->getDato() * pow(2,pot));
        pot--;
        aux = aux->getNext();
    }

    return sum;
}

/*metodo de conversion a binario*/
string Expression::convertToBin(int bitsPrecision)
{
    int entire = getEntire();
    double fractional = getFract();
    double bit = 0;
    DobleList<char>* resList = new DobleList<char>();

    while(entire > 0)
    {
        bit = (entire%2);
        bit == 1? resList->insertAtHead('1') : resList->insertAtHead('0');
        entire = entire/2;
    }
    resList->insertAtTail(',');
    int index = 0;
    while(index < bitsPrecision)
    {
        fractional = fractional*2;
        if(fractional >= 1)
        {
            resList->insertAtTail('1');
            fractional = fractional-1;
        }
        else
            resList->insertAtTail('0');
        index++;
    }


    string res = binToString(resList);
    return res;
}

/*Convierte la lista de caracteres en un string*/
string Expression::binToString(DobleList<char>* list)
{
    string res = "";
    DobleNode<char>* aux;
    for(aux = list->getHead(); aux; aux = aux->getNext())
    {
        res.push_back(aux->getDato());
    }
    return res;
}

/*Retorna la parte entera del numero decimal*/
int Expression::getEntire()
{
    double sum = 0;
    DobleNode<int> *aux = coma->getPrev();
    int pot = 0;

    while (aux)
    {
        sum += (aux->getDato() * pow(10,pot));
        pot++;
        aux = aux->getPrev();
    }

    return sum;
}

/*Retorna la parte fraccionaria del decimal*/
double Expression::getFract()
{
    double sum = 0;
    DobleNode<int> *aux = coma->getNext();
    int pot = -1;
    while (aux)
    {
        sum += (aux->getDato() * pow(10,pot));
        pot--;
        aux = aux->getNext();
    }
}

