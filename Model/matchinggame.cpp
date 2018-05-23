#include "matchinggame.h"
#include <QDebug>

MatchingGame::MatchingGame() : _score(0)
{

}

void MatchingGame::setCardN(int index)
{
    _cardNotMatched = false;

    cards.at(index)->flip();


    int numUnmatchedFlippedCards = 0;

    for(int i = 0; i < cards.size(); ++i)
    {
        if(cards.at(i)->isFlipped() && !cards.at(i)->isMatched())
        {
            numUnmatchedFlippedCards++;
            _score--;
        }
    }

    if(numUnmatchedFlippedCards == 1)
        return;

    for(int i = 0; i < cards.size(); ++i)
    {
        if(cards.at(i)->isFlipped() && i != index && cards.at(i)->getFace() == cards.at(index)->getFace() &&
            !cards.at(i)->isMatched() && !cards.at(index)->isMatched()  )
        {
            cards.at(i)->setMatched(true);
            cards.at(index)->setMatched(true);
            _cardNotMatched = true;
            _score+= 10;
        }

        if(cards.at(i)->isFlipped() && i != index && cards.at(i)->getSuit() == cards.at(index)->getSuit() &&
            !cards.at(i)->isMatched() && !cards.at(index)->isMatched()  )
        {
            cards.at(i)->setMatched(true);
            cards.at(index)->setMatched(true);
            _cardNotMatched = true;
            _score+= 5;
        }
    }
}

void MatchingGame::insertCardAtN(CardPtr c)
{
    cards.push_back(c);
}


CardColor MatchingGame::getCardColor(int n) const
{
    return cards[n]->getColor();
}

std::string MatchingGame::getText(int t)
{
    return cards[t]->toString();
}

bool MatchingGame::isFlipped(int f)
{
    return cards[f]->isFlipped();
}

int MatchingGame::getScore() const
{
    return _score;
}

void MatchingGame::setScore(int scr)
{
    _score = scr;
}

void MatchingGame::cardNotMatched() // goes with setCardN(), split up into seperate functions to be able to see two cards at a time.
{
    int numUnmatchedFlippedCards = 0;

    for(int i = 0; i < cards.size(); ++i)
    {
        if(cards.at(i)->isFlipped() && !cards.at(i)->isMatched())
            numUnmatchedFlippedCards++;
    }

    if(numUnmatchedFlippedCards == 1)
        return;

    if(!_cardNotMatched)
    {
        for(int i = 0; i < cards.size(); ++i)
        {
            if(cards.at(i)->isFlipped() && !cards.at(i)->isMatched())
            {
                cards.at(i)->flip();
            }
        }
    }
}

void MatchingGame::delay(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

CardPtr MatchingGame::getCardAtN(int n)
{
    return cards.at(n);
}
