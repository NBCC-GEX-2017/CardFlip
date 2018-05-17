#include "matchinggame.h"
#include "Model/Deck.h"

MatchingGame::MatchingGame()
{
    Deck* deck = new Deck();

    deck->shuffle();
    for(int i=0;i<32;i++){
        cards.push_back(deck->drawCard());
    }
}

CardPtr MatchingGame::getSquareN(int i)
{
    return cards.at(i);
}

void MatchingGame::flipCard(int i)
{
    cards[i]->flip();
}
