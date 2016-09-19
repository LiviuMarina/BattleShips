#include "stdafx.h"
#include "Player.h"
#include "HumanStrategy.h"
#include "ComputerStrategy.h"

Player::Player(PlayerStrategy playerStrategy)
    :m_strategy(NULL),
    m_playerBoard(NULL),
    m_opponentBoard(NULL),
    m_playerStrategy(playerStrategy)
{
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