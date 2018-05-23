#include "game.h"
#include <algorithm>

Game::Game(int numberOfCards, Deck& deck) : score(0)
{
    cards.reserve(numberOfCards);

    for (int i=0; i<numberOfCards;++i)
    {
        cards.push_back(deck.drawCard());
    }
}

void Game::selectCardI(int index)
{
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

    auto newCard = cards.at(index);

    if (newCard->isMatched())
        return;
    if (newCard->isFlipped())
    {
        newCard->flip(false);
        return;
    }
    auto card = std::find_if(cards.begin(),
                             cards.end(),
                             [](CardPtr c) { return c->isFlipped();});

    if (card == cards.end())
    {
        newCard->flip();
        return;
    }
    else
    {
        auto cardSelected = *card;
        if (cardSelected->suit == newCard->suit || cardSelected->face == newCard->face)
        {
            cardSelected->setMatched(true);
            cardSelected->flip(false);
            newCard->setMatched(true);
            newCard->flip(false);
        }
        else
        {
            cardSelected->flip(false);
            newCard->flip(true);
        }
    }




//    if(index < cards.size())
//    {
//    cards[index]->flip();
//    }
}

CardPtr Game::getCardI(int index)
{
    return cards.at(index);
}
