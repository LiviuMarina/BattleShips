#ifndef OPPONENTBOARD_H
#define OPPONENTBOARD_H

#include "Cell.h"

class OpponentBoard
{
public:

    OpponentBoard();
    ~OpponentBoard();

    void Mark(CellProperties & hitCell);
    bool Defeated();
    void InitBoard();

    const int GetInitializedBoard() const;

private:

    int m_boardCells[10][10];


};

#endif //OPPONENTBOARD_H