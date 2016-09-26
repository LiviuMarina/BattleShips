#include "stdafx.h"
#include "PlayerBoard.h"

PlayerBoard::PlayerBoard()
    :m_Ships()
{}

PlayerBoard::~PlayerBoard()
{}

bool PlayerBoard::AddShip(Cell & startPosition, Cell & endPosition)
{
    Ship ship;

    if (!ship.GenerateShip(startPosition, endPosition, *m_boardCells))
    {
        return false;
    }

    return true;
   // m_Ships.push_back(ship);
}

std::vector<Ship> PlayerBoard::GetShips() const
{
    return m_Ships;
}
