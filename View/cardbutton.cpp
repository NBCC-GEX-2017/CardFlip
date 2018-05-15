#include "cardbutton.h"

CardButton::CardButton(int idx, QWidget* parent) :
    QPushButton(parent),
    index(idx)
{
    QFont font;
    font.setPixelSize(40);
    setFont(font);

    setMinimumSize(QSize(128,192));
    setMaximumSize(QSize(128,192));
    setText("");
    setStyleSheet("border-image:url(:/media/Media/cardback.png)");
}

int CardButton::getIndex() const
{
    return index;
}
