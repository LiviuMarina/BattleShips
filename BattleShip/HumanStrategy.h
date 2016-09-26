#ifndef HUMANSTRATEGY_H
#define HUMANSTRATEGY_H

#include "Strategy.h"
#include "OpponentBoard.h"
#include "PlayerBoard.h"

class HumanStrategy:public Strategy
{
public:
    HumanStrategy(OpponentBoard & opponentBoard, PlayerBoard & playerBoard);
    virtual ~HumanStrategy();

    virtual void Mark(Cell cell);
    virtual void Fire(Cell cell);
    virtual bool AddShip(Cell startPosition, Cell endPosition);

private:

    OpponentBoard & m_opponentBoard;
    PlayerBoard & m_playerBoard;
};

#endif //HUMANSTRATEGY_H