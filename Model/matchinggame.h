#ifndef MATCHINGGAME_H
#define MATCHINGGAME_H
#include "Model/Card.h"
#include "Model/Deck.h"
#include "View/cardqpushbutton.h"
#include <vector>
#include <map>
#include <algorithm>

class MatchingGame
{
public:
    MatchingGame(int numberOfCards, Deck& deck);

    CardPtr getSquareN(int i);          //
    void selectCardN(int index);         //
    Suit getSuit(int i){return _cards[i]->suit;}  //
    Face getFace(int i){return _cards[i]->face;}  //
    int getScore();



private:
    std::vector<CardPtr> _cards;
    std::map<CardPtr, int> _count;

    int _score;
};

#endif // MATCHINGGAME_H
