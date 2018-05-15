#ifndef CARDBUTTON_H
#define CARDBUTTON_H

#include <QPushButton>

class CardButton : public QPushButton
{
public:
    CardButton(int idx, QWidget* parent = 0);

    int getIndex() const;

private:
    int index;
};

#endif // CARDBUTTON_H
