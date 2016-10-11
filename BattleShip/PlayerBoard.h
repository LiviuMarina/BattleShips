#ifndef PLAYERBOARD_H
#define PLAYERBOARD_H

#include "OpponentBoard.h"
#include "Cell.h"
#include "Ship.h"
#include <vector>

class PlayerBoard :public OpponentBoard
{
public:
    //default constructor
    PlayerBoard();

    //destructor
    ~PlayerBoard();

    //Add ship into the board
    bool AddShip(Cell & startPosition, Cell & endPosition); //to do : Check if I can use Cell instead of CellProperties

    //Get ships
    std::vector<Ship> GetShips() const;
private:
    
    std::vector<Ship> m_Ships;
};

#endif //PLAYERBOARD_H

