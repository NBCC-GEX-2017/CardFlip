#ifndef MATCHINGGAME_H
#define MATCHINGGAME_H
#include "Model/Card.h"
#include "Model/Deck.h"
#include "View/cardqpushbutton.h"
#include <vector>

class MatchingGame
{
public:
    MatchingGame(int numberOfCards, Deck& deck);

    CardPtr getSquareN(int i);          //
    void selectCardN(int index);         //
    Suit getSuit(int i){return cards[i]->suit;}  //
    Face getFace(int i){return cards[i]->face;}  //


private:
    std::vector<CardPtr> cards;

};

#endif // MATCHINGGAME_H
