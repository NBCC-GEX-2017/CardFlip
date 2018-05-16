#ifndef CARDQPUSHBUTTON_H
#define CARDQPUSHBUTTON_H

#include <QPushButton>

class CardQPushButton : public QPushButton
{
public:
    CardQPushButton(int idx) : QPushButton(nullptr), index(idx){}

    int getIndex() const {return index;}

private:
    int index;
};

#endif // CARDQPUSHBUTTON_H
