#include "stdafx.h"
#include "Player.h"
#include "HumanStrategy.h"
#include "ComputerStrategy.h"
#include "Helper.h"

namespace player
{
    Player::Player()
        :m_strategy(NULL),
        m_shipBoard(shipboard::ShipBoard()),
        m_hitBoard(hitboard::HitBoard())
    {
    }

    Player::~Player()
    {
    }

    void Player::SelectStrategy(PlayerStrategy playerStrategy)
    {
        if (playerStrategy == humanStrategy)
        {
            m_strategy = std::make_shared<strategy::HumanStrategy>(m_hitBoard, m_shipBoard);
        }
        else
        {
            m_strategy = std::make_shared<strategy::ComputerStrategy>(m_hitBoard, m_shipBoard);
        }
    }

    void Player::InitBoards()
    {
        //init hit board
        m_hitBoard.SetHeight(helper::NO_OF_COLUMNS);
        m_hitBoard.SetWidth(helper::NO_OF_ROWS);
        m_hitBoard.InitBoard();

        //init ship board
        m_shipBoard.SetHeight(helper::NO_OF_COLUMNS);
        m_shipBoard.SetWidth(helper::NO_OF_ROWS);
        m_shipBoard.InitBoard();
    }

    void Player::Mark(const cell::Cell & cell, bool & intoSHip)
    {
        m_shipBoard.Mark(cell, intoSHip);
    }

    cell::Cell Player::Fire()
    {
        cell::Cell attackedCell = m_strategy->Fire();
        return attackedCell;
    }

    bool Player::Defeated()
    {
        return m_shipBoard.Defeated();
    }

    void Player::FillHitBoard(const cell::Cell & cell, bool intoShip)
    {
        m_hitBoard.Mark(cell, intoShip);
    }
}
