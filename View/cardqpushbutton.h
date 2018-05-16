#ifndef CARDQPUSHBUTTON_H
#define CARDQPUSHBUTTON_H
#include <QPushButton>

class CardQPushButton : public QPushButton
{
public:
    CardQPushButton(int index) : QPushButton(), _index(index) {}
    int getIndex() const {return _index;}
private:
    int _index;
};

#endif // CARDQPUSHBUTTON_H
