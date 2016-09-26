#include "stdafx.h"
#include "Player.h"
#include "HumanStrategy.h"
#include "ComputerStrategy.h"

Player::Player(PlayerStrategy playerStrategy)
    :m_strategy(NULL),
    m_playerBoard(std::make_shared<PlayerBoard>()),
    m_opponentBoard(std::make_shared<OpponentBoard>()),
    m_playerStrategy(playerStrategy)
{
    m_opponentBoard->InitBoard();

    m_playerBoard->InitBoard();
}

Player::~Player()
{
}

void Player::SelectStrategy()
{
    if (m_playerStrategy == humanStrategy)
    {
        m_strategy = std::make_shared<HumanStrategy>(*m_opponentBoard, *m_playerBoard);
    }
    else
    {
        m_strategy = std::make_shared<ComputerStrategy>(*m_opponentBoard, *m_playerBoard);
    }
}