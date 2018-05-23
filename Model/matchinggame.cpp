#include "matchinggame.h"
#include <algorithm>


MatchingGame::MatchingGame(int numberOfCards, Deck &deck): score(0)
{
    cards.reserve(numberOfCards);

    for (int i=0;i<numberOfCards;++i)
    {
        if (! deck.isEmpty())
            cards.push_back(deck.drawCard());
    }
}

CardPtr MatchingGame::getCardN(int index)
{
    return cards.at(index);
}

void MatchingGame::selectCardN(int index)
{
    if (index < cards.size() )
    {
    //std::find_if (cards.begin(), cards.end(), isFlipped());
    //use find if to find if an object is flipped(have isFlipped as a predicate)

    //if card(index) is flipped()
        if(cards[index]->isFlipped())
        {
            //flip back and return
            cards[index]->flip();
            score = score - 1;
            return;//breaks out of ifs
        }
        else if(cards[index]->isMatched())//if isMatched then return
        {
            return;
        }
        else{
        std::vector<CardPtr>::iterator it = std::find_if (cards.begin(), cards.end(), [](CardPtr &c){return c->isFlipped();});

        if(it != cards.end())//is there a card already flipped
        {
            (*it)->flip();
            cards[index]->flip();
            //if((*it)->isFlipped())
            //if there is does it match the new card at index
            //if(it->get()->getColor() == cards[index]->getColor() || it->get()->toString().substr(0,1) == cards[index]->toString().substr(0,1))//if the two cards match
            if((*it)->suit == cards[index]->suit || (*it)->face == cards[index]->face)//if the two cards match
            {
                //set both to matched
                cards[index]->setMatched(true);
                //set other card to matched
                //it->get()->setMatched(true);
                (*it)->setMatched(true);
                //score some points
                cards[index]->flip();
                if((*it)->face == cards[index]->face)//if it was face matched
                {
                    score = score + 4;
                }
                else{
                    score = score + 1;
                }
            }
            else//if it doesn't match
            {
                 score = score - 1;
                 //deduct points
            }
        }
            else{
                cards[index]->flip();
            }
    }
    }

}
