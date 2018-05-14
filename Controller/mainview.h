#ifndef MAINVIEW_H
#define MAINVIEW_H
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QFont>
//#include "Model/Deck.h"

#include <QMainWindow>

namespace Ui {
class MainView;
}

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

private slots:
    void changeCard();

private:
    Ui::MainView *ui;
   //Deck deck;
    QPushButton* shuffleButton;
    QPushButton* card;
    int currentCard{0};
    void drawView();
};

#endif // MAINVIEW_H
