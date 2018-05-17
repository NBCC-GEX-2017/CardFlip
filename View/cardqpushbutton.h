#ifndef CARDQPUSHBUTTON_H
#define CARDQPUSHBUTTON_H
#include <QPushButton>

class CardQPushButton : public QPushButton
{
public:
    CardQPushButton(int index) : QPushButton(), _index(index) {
        QFont font;
        font.setPixelSize(40);
        this->setFont(font);
        this->setMinimumSize(QSize(128,192));
        this->setMaximumSize(QSize(128,192));
        this->setText("");
        this->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardback.png)"));
    }
    int getIndex() const {return _index;}
private:
    int _index;
};

#endif // CARDQPUSHBUTTON_H
