#ifndef MATCHINGGAME_H
#define MATCHINGGAME_H
#include "model/Card.h"
#include "model/Deck.h"
#include<vector>
#include<algorithm>


class MatchingGame
{
public:
    MatchingGame(int numberOfCards,Deck& deck);
    CardPtr getCardAt(int i);
    void flipCardAt(int i);
    void reDealCard(int numberOfCards,Deck& deck);
    int getScore(){return score;}
private:
    std::vector<CardPtr> cards;
    int score = 200;
};

#endif // MATCHINGGAME_H
