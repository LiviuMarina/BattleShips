#include "stdafx.h"
#include "ComputerStrategy.h"

ComputerStrategy::ComputerStrategy(OpponentBoard & opponentBoard, PlayerBoard & playerBoard)
    :m_opponentBoard(opponentBoard),
    m_playerBoard(playerBoard)
{}

ComputerStrategy::~ComputerStrategy()
{}

void ComputerStrategy::Mark(Cell cell)
{}

void ComputerStrategy::Fire(Cell cell)
{}

bool ComputerStrategy::AddShip(Cell startPosition, Cell endPosition)
{
    return false;
}

