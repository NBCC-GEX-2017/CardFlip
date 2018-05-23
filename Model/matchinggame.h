#ifndef MATCHINGGAME_H
#define MATCHINGGAME_H
#include <vector>
#include "Model/Card.h"
#include "Model/Deck.h"
#include <QString>
#include "View/cardqpushbutton.h"
#include <QCoreApplication>
#include <QTime>

class MatchingGame
{
public:
    MatchingGame();

    void setCardN(int f);
    void insertCardAtN(CardPtr n);
    CardColor getCardColor(int n) const;
    std::string getText(int t);
    bool isFlipped(int f);
    int getScore() const;
    void setScore(int scr);
    void cardNotMatched();


    void delay(int millisecondsToWait);

    CardPtr getCardAtN(int n);


private:
    std::vector<CardPtr> cards;
    int _score;
    bool _cardNotMatched;
};

#endif // MATCHINGGAME_H
