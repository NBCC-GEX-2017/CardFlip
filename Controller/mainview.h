#ifndef MAINVIEW_H
#define MAINVIEW_H
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QFont>
#include "Model/Deck.h"
#include <memory>
#include <QMainWindow>
#include <vector>
#include "View/cardqpushbutton.h"

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
    void shuffle();

private:
    Ui::MainView *ui;
    std::unique_ptr<Deck> _deck;
    QPushButton* _shuffleButton;
    //QPushButton* _cardBtn;
    std::vector<CardQPushButton*> _cardBtn;
    //homework -> vector of cards -> grid 4 x 8
    int currentCard{0};
    void drawView();
};

#endif // MAINVIEW_H
