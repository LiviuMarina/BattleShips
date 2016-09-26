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
    //create players
    m_computerPlayer = std::make_shared<Player>(computerStrategy);
    m_computerPlayer->SelectStrategy();

    m_humanPlayer = std::make_shared<Player>(humanStrategy);
    m_humanPlayer->SelectStrategy();

}

void Game::ExitGame()
{
}

const std::shared_ptr<Player> Game::GetHumanPlayer() const
{
    return m_humanPlayer;
}