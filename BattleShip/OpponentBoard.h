#ifndef OPPONENTBOARD_H
#define OPPONENTBOARD_H

#include "Cell.h"
#include <array>
#include "Helper.h"

class OpponentBoard
{
public:

    //default constructor
    OpponentBoard();

    //destructor
    ~OpponentBoard();

    //Mark the hit cell
    void Mark(CellProperties & hitCell);

    //Check if the player is defeated
    bool Defeated();

    //Initialize the board
    void InitBoard();

    //Get the board
    const CellPropertiesArray * GetInitializedBoard() const;

protected:

    CellPropertiesArray * m_boardCells;
};

#endif //OPPONENTBOARD_H