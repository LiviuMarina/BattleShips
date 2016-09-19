#include "stdafx.h"
#include "PlayerBoard.h"

PlayerBoard::PlayerBoard()
    :m_Ships()
{}

PlayerBoard::~PlayerBoard()
{}

void PlayerBoard::AddShip(CellProperties & startPosition, CellProperties & endPosition)
{}

std::vector<Ship> PlayerBoard::GetShips() const
{
    return m_Ships;
}
