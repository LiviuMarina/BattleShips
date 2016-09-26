#include "stdafx.h"
#include "HumanStrategy.h"

HumanStrategy::HumanStrategy(OpponentBoard & opponentBoard, PlayerBoard & playerBoard)
    :m_opponentBoard(opponentBoard),
    m_playerBoard(playerBoard)
{}

HumanStrategy::~HumanStrategy()
{}

void HumanStrategy::Mark(Cell cell)
{}

void HumanStrategy::Fire(Cell cell)
{}

bool HumanStrategy ::AddShip(Cell startPosition, Cell endPosition)
{
    if (!m_playerBoard.AddShip(startPosition, endPosition))
    {
        return false;
    }

    return true;
   
}

