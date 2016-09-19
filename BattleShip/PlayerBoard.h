#ifndef PLAYERBOARD_H
#define PLAYERBOARD_H

#include "OpponentBoard.h"
#include "Cell.h"
#include "Ship.h"
#include <vector>

class PlayerBoard :public OpponentBoard
{
public:

    PlayerBoard();
    ~PlayerBoard();


    void AddShip(CellProperties & startPosition, CellProperties & endPosition); //to do : Check if I can use Cell instead of CellProperties

    std::vector<Ship> GetShips() const;
private:
    
    std::vector<Ship> m_Ships;
};

#endif //PLAYERBOARD_H

