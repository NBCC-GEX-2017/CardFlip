#include "matchinggame.h"



MatchingGame::MatchingGame(int numberOfCards, Deck &deck)
{
    cards.reserve(numberOfCards);

    for(int i =0; i < numberOfCards; i++)
    {
        if(!deck.isEmpty())
        {
            cards.push_back(deck.drawCard());
        }
    }
}

void MatchingGame::selectCard(int index)
{
    if(index < cards.size())
    {
        cards[index]->flip();
    }
}
CardPtr MatchingGame::getCard(int index)
{
    return cards.at(index);
}
