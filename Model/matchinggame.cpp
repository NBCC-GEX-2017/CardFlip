#include "matchinggame.h"
#include <algorithm>


MatchingGame::MatchingGame(int numberOfCards, Deck &deck) : score(0)
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
                if(c->suit == cards.at(index)->suit)score+=1;
                else score+=4;
            }
            else{
                if(!c->isMathced()){
                    c->flip();
                    //deduct point
                    score-=1;
                }

            }
        }

    });


    if(index<cards.size())
    {
        //deduct point
        if(cards.at(index)->isFlipped())score-=1;

        cards[index]->flip();
    }





/*
    if(index<cards.size())
    {
        cards[index]->flip();
    }
*/



}

int MatchingGame::getScore()
{
    return score;
}
