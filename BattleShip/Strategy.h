#ifndef STRATEGY_H
#define STRATEGY_H

#include "Cell.h"

class Strategy
{
public:
    Strategy()
    {}
    virtual ~Strategy()
    {}

    virtual void Mark(Cell cell) = 0;
    virtual void Fire(Cell cell) = 0;
    virtual bool AddShip(Cell startPosition, Cell endPosition) = 0;
};

#endif //STRATEGY_H