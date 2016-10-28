#include "stdafx.h"
#include "HitBoard.h"
#include <stdlib.h>
#include <string>

namespace hitboard
{
    HitBoard::HitBoard()
    {}

    HitBoard::~HitBoard()
    {
    }

    void HitBoard::Mark(const cell::Cell & hitCell, bool intoShip)
    {
        std::vector<std::vector<cell::CellProperties>>::iterator boardIter = m_boardCells.begin();
        for (; boardIter!= m_boardCells.end(); ++boardIter)
        {
            std::vector<cell::CellProperties > ::iterator cellIter =
                std::find_if(boardIter->begin(), boardIter->end(),
                [&](const cell::Cell & cell)
            {
                return ((cell.GetColumn() == hitCell.GetColumn()) && (cell.GetRow() == hitCell.GetRow()));
            });

            if (cellIter != boardIter->end())
            {
                cellIter->SetHitState(true);
                cellIter->SetShipMembership(intoShip);

                break;
            }
        }
    }
}