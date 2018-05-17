#include "game.h"
#include "Model/Card.h"
#include "Model/Deck.h"


Game::Game()
{

}



void Game::setFlipped(int index)
{
    _cards[index]->flip();
}

void Game::setCardAtN(CardPtr card){

    _cards.push_back(card);
}

std::string Game::getText(int index)
{
    return _cards[index]->toString();
}

CardColor Game::getCardColor(int index)
{
    return _cards[index]->getColor();
}


bool Game::isFlipped(int index){
    return _cards[index]->isFlipped();

}



