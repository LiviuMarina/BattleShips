#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"

class Board
{
public:
    Board()
    {}

    virtual ~Board()
    {}

    //Mark the hit cell
    virtual void Mark(CellProperties & hitCell) = 0;

    //Check if the player is defeated
    virtual bool Defeated() = 0;

    //in the UML diagram there are function that can be added
    //for the moment this is enough
};

#endif //BOARD_H