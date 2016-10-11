#ifndef HUMANSTRATEGY_H
#define HUMANSTRATEGY_H

#include "Strategy.h"
#include "OpponentBoard.h"
#include "PlayerBoard.h"

class HumanStrategy:public Strategy
{
public:
    //constructor
    HumanStrategy(OpponentBoard & opponentBoard, PlayerBoard & playerBoard);

    //virtual destructor
    ~HumanStrategy();

    //Mark the Cell that was hit
    virtual void Mark(Cell cell);

    //Attack opponent
    virtual Cell & Fire();

    //Add ship
    virtual bool AddShip();

private:

    OpponentBoard & m_opponentBoard;
    PlayerBoard & m_playerBoard;
};

#endif //HUMANSTRATEGY_H