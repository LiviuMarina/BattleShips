#ifndef SHIP_H
#define SHIP_H

#include "Cell.h"

class Ship
{
public:
    Ship();
    ~Ship();

    //Generate a new ship, taking in consideration start and end positions
    void GenerateShip(CellProperties & startPosition, CellProperties & endPosition);
};

#endif //SHIP_H