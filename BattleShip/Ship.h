#ifndef SHIP_H
#define SHIP_H

#include "Cell.h"
#include <array>
#include "Helper.h"

class Ship
{
public:
    //default constructor
    Ship();

    //destrctor
    ~Ship();

    //Generate a new ship, taking in consideration start and end positions
    bool GenerateShip(Cell & startPosition, Cell & endPosition, CellPropertiesArray & boardCells);

};

#endif //SHIP_H