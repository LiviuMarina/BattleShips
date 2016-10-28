#include "stdafx.h"
#include "Board.h"
#include <algorithm>

namespace board
{
    Board::Board():
        m_width(),
        m_height(),
        m_boardCells(NULL)
    {}

    Board::~Board()
    {
    }

    void Board::InitBoard()
    {

        for (auto i = 0; i < m_width; ++i)
        {
            m_boardCells.push_back(std::vector<cell::CellProperties>());
            for (auto j = 0; j < m_height; ++j)
            {
                cell::CellProperties tempCell;
                tempCell.SetRow(i);
                tempCell.SetCol(j);
                m_boardCells[i].push_back(tempCell);
            }
        }
    }
    
    void Board::Refresh()
    {
    }
    
}

