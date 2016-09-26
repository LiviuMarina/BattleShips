#ifndef OPPONENTBOARD_H
#define OPPONENTBOARD_H

#include "Cell.h"
#include <array>

const int NO_OF_ROWS = 10;
const int NO_OF_COLUMNS = 10;
typedef std::array<std::array<CellProperties, NO_OF_ROWS>, NO_OF_COLUMNS> CellPropertiesArray;

class OpponentBoard
{
public:

    OpponentBoard();
    ~OpponentBoard();

    void Mark(CellProperties & hitCell);
    bool Defeated();

    void InitBoard();
    const CellPropertiesArray * GetInitializedBoard() const;

protected:

    CellPropertiesArray * m_boardCells;


};

#endif //OPPONENTBOARD_H