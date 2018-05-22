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
    std::vector<CardPtr>::iterator card = std::find_if(cards.begin(),cards.end(),
             [](CardPtr& c){
        return c->isFlipped();
    });

    if(card == cards.end())
        cards[i]->flip();
    else{
        char char1 = card->get()->toString().at(1);
        char char2 = cards[i]->toString().at(1);
        if(char1 == char2)
        {
            card->get()->flip();
            card->get()->setMatched(true);
            cards[i]->setMatched(true);
            score += 5;
        }
        else
        {
            card->get()->flip();
            cards[i]->flip();
            score--;
        }
    }
}

void MatchingGame::reDealCard(int numberOfCards, Deck& deck)
{
    cards.clear();
    for(int i = 0; i < numberOfCards; i++)
    {
        cards.push_back(deck.drawCard());
    }
    score = 200;
}
