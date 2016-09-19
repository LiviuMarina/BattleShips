#include "stdafx.h"
#include "Game.h"
#include "Player.h"

Game::Game()
{
}

Game::~Game()
{

}

void Game::CreateGame()
{
    OpponentBoard opponentBoard;
    opponentBoard.InitBoard();

    PlayerBoard playerBoard;
    playerBoard.InitBoard();

    //create players
    m_computerPlayer = std::make_shared<Player>(computerStrategy);
    m_computerPlayer->SelectStrategy();

    m_humanPlayer = std::make_shared<Player>(humanStrategy);
    m_humanPlayer->SelectStrategy();

}

void Game::ExitGame()
{
}