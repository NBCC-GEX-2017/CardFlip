#ifndef CARDBUTTON_H
#define CARDBUTTON_H

#include <QPushButton>

class CardButton : public QPushButton
{
public:
    CardButton(int i) : QPushButton(), index(i) {        QFont font;
                                                         font.setPixelSize(40);setFont(font);
                                                         setMinimumSize(QSize(128,192));
                                                         setMaximumSize(QSize(128,192));
                                                         setText("");
                                                         setStyleSheet("border-image:url(:/media/Media/cardback.png)");}

    int getIndex() const {return index;}

private:
    int index;
};

#endif // CARDBUTTON_H
