#ifndef MATCHINGGAME_H
#define MATCHINGGAME_H
#include <vector>
#include "Model/Card.h"
#include "Model/Deck.h"
#include <QString>
#include "View/cardqpushbutton.h"


class MatchingGame
{
public:
    MatchingGame();

    void setFlip(int f);
    void setCardAtN(CardPtr n);
    CardColor getCardColor(int n) const;
    std::string getText(int t);
    bool isFlipped(int f);


private:
    std::vector<CardPtr> cards;
};

#endif // MATCHINGGAME_H
