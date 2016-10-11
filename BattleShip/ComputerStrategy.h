#ifndef COMPUTERSTRATEGY_H
#define COMPUTERSTRATEGY_H

#include "Strategy.h"
#include "OpponentBoard.h"
#include "PlayerBoard.h"

class ComputerStrategy :public Strategy
{
public:
    //constructor
    ComputerStrategy(OpponentBoard & opponentBoard, PlayerBoard & playerBoard);

    //virtual destructor
    ~ComputerStrategy();

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

#endif //COMPUTERSTRATEGY_H