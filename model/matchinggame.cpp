#include "matchinggame.h"



MatchingGame::MatchingGame(int numberOfCards, Deck& deck)
{
    for(int i = 0; i < numberOfCards; i++)
    {
        cards.push_back(deck.drawCard());
    }
}

CardPtr MatchingGame::getCardAt(int i)
{
    return cards[i];
}

void MatchingGame::flipCardAt(int i)
{
    cards[i]->flip();
}
