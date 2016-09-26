#ifndef SHIP_H
#define SHIP_H

#include "Cell.h"
#include <array>

enum Orientation
{
    orizontal,
    vertical
};

class Ship
{
public:
    Ship();
    ~Ship();

    //Generate a new ship, taking in consideration start and end positions
    bool GenerateShip(Cell & startPosition, Cell & endPosition, std::array<std::array<CellProperties, 10>, 10> & boardCells);
};

#endif //SHIP_H