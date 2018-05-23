#include "game.h"

Game::Game(int numberOfCards, Deck& deck)
{
    cards.resize(numberOfCards);

    for(int i = 0; i < numberOfCards; ++i){
        if(!deck.isEmpty())
            cards.push_back(deck.drawCard());
    }
}

CardPtr Game::getCard(int index)
{
    return cards.at(index);
}

void Game::selectCard(int index)
{
    std::for_each(cards.begin(),
                  cards.end(),
                  [] (CardPtr c)
                  { if(c->isFlipped())
                    {
                        c->flip();
                    }
                    c->setMatched(false);
    });
    if(index < cards.size()){
        cards[index]->flip();
    }
}
