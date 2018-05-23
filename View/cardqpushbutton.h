#ifndef CARDQPUSHBUTTON_H
#define CARDQPUSHBUTTON_H
#include <QPushButton>
#include "Model/game.h"

class CardQPushButton : public QPushButton
{
public:
    CardQPushButton(int i): QPushButton(), index(i){}

    int getIndex() const{return index;}

private:
    int index;
};

#endif // CARDQPUSHBUTTON_H
