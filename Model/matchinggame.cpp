#include "matchinggame.h"

matchingGame::matchingGame(int numberOfCards, Deck &deck)
{
    cards.reserve(numberOfCards);
    for(int i=0; i < numberOfCards; i++){
        if(!deck.isEmpty())
            cards.push_back(deck.drawCard());
    }

}

CardPtr matchingGame::getCardN(int index)
{
    return cards.at(index);
}

void matchingGame::selectCardN(int index)
{
    if(index < cards.size()){
        cards[index]->flip();
        for(int i = 0; i < cards.size(); i++)
        {
            if(cards[i]->isFlipped()&&i!=index)
                cards[i]->flip();
        }
    }
}

