#include "stdafx.h"
#include "Ship.h"
#include <vector>
#include <iostream>

namespace ship
{
    Ship::Ship(const cell::Cell& begin, const cell::Cell& end, helper::Orientation shipOrientation)
        :m_begin(begin),
        m_end(end),
        m_shipOrientation(shipOrientation)
    {}

    Ship::~Ship()
    {}

    bool Ship::Sunk(const std::vector<std::vector<cell::CellProperties>> & boardCells) const
    {
        if (m_shipOrientation == helper::horizontally)
        {
            for (int columnNumber = m_begin.GetColumn(); columnNumber <= m_end.GetColumn(); ++columnNumber)
            {
                std::vector<cell::CellProperties> columnsCells = boardCells[m_begin.GetRow()];
                cell::CellProperties boardCell = columnsCells[columnNumber];

                if (boardCell.GetHitState() != true)
                {
                    return false;
                }
            }
        }

        else
        {
            for (int rowNumber = m_begin.GetRow(); rowNumber <= m_end.GetRow(); ++ rowNumber)
            {
                std::vector<cell::CellProperties> rowCells = boardCells[rowNumber];
                cell::CellProperties boardCell = rowCells[m_begin.GetColumn()];

                if (boardCell.GetHitState() != true)
                {
                    return false;
                }
            }
        }

        return true;
    }
}

