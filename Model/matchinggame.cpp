#include "matchinggame.h"

MatchingGame::MatchingGame()
{

}

void MatchingGame::setFlip(int f)
{
    cards[f]->flip();
}

void MatchingGame::setCardAtN(CardPtr c)
{
    cards.push_back(c);
}

void MatchingGame::getCardAtN(int n)
{
    cards.at(n);
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
