#include "game.h"
#include <algorithm>

Game::Game(int numberOfCards, Deck& deck)
{
    cards.reserve(numberOfCards);

    for (int i=0; i<numberOfCards;++i)
    {
        cards.push_back(deck.drawCard());
    }
}

void Game::selectCardI(int index)
{
//    std::for_each(cards.begin(), cards.end(), [](CardPtr c) {
//        if (c->isFlipped())
//            c->flip();
//    });
//
//    if (index < cards.size())
//    {
//        cards[index]->flip();
//    }
    if(index < cards.size())
    {
    cards[index]->flip();
    }
}

CardPtr Game::getCardI(int index)
{
    return cards.at(index);
}
