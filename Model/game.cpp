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

    // card(index)
        // isFlipped() -> flip and return
        // isMatched() -> return

    // is there is a card already flipped
        // no -> flip it

        // yes
            // does it match card at index
                // yes
                    // set both to matched
                    // score some points
                // no
                    // deduct some points
                    // flip both cards

    std::vector<CardPtr> card = std::find_if(cards.begin(),
                                             cards.end(),
                                             [](CardPtr c) { return c->isFlipped();});






//    if(index < cards.size())
//    {
//    cards[index]->flip();
//    }
}

CardPtr Game::getCardI(int index)
{
    return cards.at(index);
}
