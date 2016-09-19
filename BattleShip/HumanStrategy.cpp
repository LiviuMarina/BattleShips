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

void HumanStrategy ::AddShip(Cell startPosition, Cell endPosition)
{}

