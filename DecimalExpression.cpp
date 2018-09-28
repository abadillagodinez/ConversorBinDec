#include "DecimalExpression.h"

DecimalExpression::DecimalExpression()
{

}

void DecimalExpression::PosicionarComa()
{
    for(int i = 0; i < digitos->getSize(); i++)
    {
        if(digitos->getPos(i)->getDato() < 0)
            coma = digitos->getPos(i);
    }
    if(coma = 0)
    {
        digitos->insertAtTail(',' - '0');
        digitos->insertAtTail(0);
        digitos->deleteAtTail(0);
    }
}
