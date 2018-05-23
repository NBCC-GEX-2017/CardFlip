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
    {
        cards[i]->flip();
        score--;
    }
    else{
        if(card->get()->suit == cards[i]->suit && card->get()->face == cards[i]->face){
            cards[i]->flip();
         }
        else
        if(card->get()->face == cards[i]->face)
        {
            card->get()->flip();
            card->get()->setMatched(true);
            cards[i]->setMatched(true);
            score += 5;
        }
        else
        if(card->get()->suit == cards[i]->suit){
            card->get()->flip();
            card->get()->setMatched(true);
            cards[i]->setMatched(true);
            score += 1;
        }
        else
        {
            card->get()->flip();
            cards[i]->flip();

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

//function that returns true or false based on if there is a match possible in game
bool MatchingGame::testDuplicates()
{
    for(int i = 0; i < cards.size(); i++)
    {
        if(!cards[i]->isMatched())
        {
            for(int j = i+1; j < cards.size(); j++)
            {
                if(cards[i]->face == cards[j]->face && !cards[j]->isMatched() || cards[i]->suit == cards[j]->suit && !cards[j]->isMatched())
                {
                    return true;
                }
            }
        }
    }
    return false;
}
