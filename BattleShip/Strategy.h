#ifndef STRATEGY_H
#define STRATEGY_H

#include "Cell.h"

class Strategy
{
public:

    //default constructor
    Strategy()
    {}

    //default constructor
    virtual ~Strategy()
    {}
    
    //Mark the Cell that was hit
    virtual void Mark(Cell cell) = 0;

    //Attack opponent
    virtual Cell & Fire() = 0;

    //Add ship
    virtual bool AddShip() = 0;
};

#endif //STRATEGY_H