#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <Model/Card.h>
#include <Model/Deck.h>
#include <QMainWindow>
#include <memory>

namespace Ui {
class MainView;
}

class QPushButton;

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

private slots:
    void onCardClick();

//methods
private:

    void drawView();
//members
private:
    Ui::MainView *ui;

    std::unique_ptr<Deck> deck;
    /////////////////////////
    QPushButton* cardDisplayBtn;
 //change to a vector. to deal 32 cards in a grid...refer to demo03 (tic tac toe)



};

#endif // MAINVIEW_H
