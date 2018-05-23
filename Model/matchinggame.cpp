#include "matchinggame.h"
#include <algorithm>


MatchingGame::MatchingGame(int numberOfCards, Deck &deck)
{
    cards.reserve(numberOfCards);

    for(int i=0;i<numberOfCards;++i)
    {
        if(!deck.isEmpty())
            cards.push_back(deck.drawcard());
    }
}

CardPtr MatchingGame::getCard(int index)
{
    return cards.at(index);
}

void MatchingGame::selectCard(int index)
{


    /*std::for_each(cards.begin(),cards.end(),[](CardPtr c){
        if(c->isFlipped())
            c->flip();
    });*/




    std::for_each(cards.begin(),cards.end(),[this, index](CardPtr c){
        if(c->isFlipped()&&c!=cards.at(index))
        {
            if(((c->suit == cards.at(index)->suit)||(c->face == cards.at(index)->face)) && !c->isMathced()){
                c->setMatched(true);
                cards.at(index)->setMatched(true);
                //score point
            }
            else{
                if(!c->isMathced())
                    c->flip();
                    //deduct point
            }
        }

    });


    if(index<cards.size())
    {
        cards[index]->flip();
    }





/*
    if(index<cards.size())
    {
        cards[index]->flip();
    }
*/



}
