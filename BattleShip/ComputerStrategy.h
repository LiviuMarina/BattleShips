#ifndef COMPUTERSTRATEGY_H
#define COMPUTERSTRATEGY_H

#include "Strategy.h"
#include "OpponentBoard.h"
#include "PlayerBoard.h"

class ComputerStrategy :public Strategy
{
public:
    ComputerStrategy(OpponentBoard & opponentBoard, PlayerBoard & playerBoard);
    virtual ~ComputerStrategy();

    virtual void Mark(Cell cell);
    virtual void Fire(Cell cell);
    virtual bool AddShip(Cell startPosition, Cell endPosition);

private:

    OpponentBoard & m_opponentBoard;
    PlayerBoard & m_playerBoard;
};

#endif //COMPUTERSTRATEGY_H