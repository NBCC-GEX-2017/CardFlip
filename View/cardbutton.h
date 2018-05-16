#ifndef CARDBUTTON_H
#define CARDBUTTON_H

#include <QPushButton>

class CardButton : public QPushButton
{
public:
    CardButton(int i) : QPushButton(), index(i) {}

    int getIndex() const {return index;}

private:
    int index;
};

#endif // CARDBUTTON_H
