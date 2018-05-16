#ifndef CARDQPUSHBUTTON_H
#define CARDQPUSHBUTTON_H
#include <QPushButton>


class CardQPushButton : public QPushButton
{
public:
    CardQPushButton(int i): QPushButton(), index(i){}
    int getIntex() const {return index;}

private:
    int index;
};

#endif // CARDQPUSHBUTTON_H
