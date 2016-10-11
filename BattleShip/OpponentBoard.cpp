#include "stdafx.h"
#include "OpponentBoard.h"
#include <stdlib.h>
#include <string>

OpponentBoard::OpponentBoard()
{}

OpponentBoard::~OpponentBoard()
{
    delete m_boardCells;
}

void OpponentBoard::Mark(CellProperties & hitCell)
{}

bool OpponentBoard::Defeated()
{
    return false;
}

void OpponentBoard::InitBoard()
{
    m_boardCells = new CellPropertiesArray();

    for (auto i = 0; i < NO_OF_ROWS; ++i)
    {
        for (auto j = 0; j < NO_OF_COLUMNS; ++j)
        {
            m_boardCells->data()[i][j].SetRow(i);
            m_boardCells->data()[i][j].SetCol(j);
        }
    }
}

const CellPropertiesArray * OpponentBoard::GetInitializedBoard() const
{
    return m_boardCells;
}