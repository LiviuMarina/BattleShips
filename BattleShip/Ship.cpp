#include "stdafx.h"
#include "Ship.h"
#include <vector>


namespace{

    Orientation CheckShipOrientation(Cell & startPosition, Cell & endPosition)
    {
        Orientation orientation;

        if (startPosition.GetRow() != endPosition.GetRow())
        {
            orientation = Orientation::vertical;
        }

        else
        {
            orientation = Orientation::orizontal;
        }

        return orientation;
    }

    bool CheckFreeSpaceForShip(int row, int column, const std::array<std::array<CellProperties, 10>, 10> & boardCells)
    {
        bool result = false;

        if (!boardCells[row][column].GetShipMembership())
        {
            result = true;
        }

        return result;

    }
}

Ship::Ship()
{}

Ship::~Ship()
{}

bool Ship::GenerateShip(Cell & startPosition, Cell & endPosition, std::array<std::array<CellProperties, 10>, 10> & boardCells)
{
    Orientation orientation = CheckShipOrientation(startPosition, endPosition);

    if (orientation == orizontal)
    {     
        int rowNumber = (int)startPosition.GetRow() - DEC_TO_ASCII;
        std::vector<CellProperties *> shipCells;

        for (int i = startPosition.GetColumn(); i < (endPosition.GetColumn() + 1); ++i)
        {  
            if (CheckFreeSpaceForShip(rowNumber, i, boardCells))
            {
                shipCells.push_back(&boardCells.data()[rowNumber][i]);
            }
            else
            {
                shipCells.clear();
            }           
        }
        if (!shipCells.empty())
        {
            for (int vectIncr = 0; vectIncr < shipCells.size(); ++vectIncr)
            {
                shipCells[vectIncr]->SetShipMembership(true);
            }
        }
        else
        {
            return false;
        }
    }

    else if (orientation == vertical)
    {
        int startRowNumber = (int)startPosition.GetRow() - DEC_TO_ASCII;
        int endRowNumber = (int)endPosition.GetRow() - DEC_TO_ASCII;
        std::vector<CellProperties *> shipCells;

        for (int i = startRowNumber; i < (endRowNumber + 1); ++i)
        {
            if (CheckFreeSpaceForShip(i, startPosition.GetColumn(), boardCells))
            {
                shipCells.push_back(&boardCells.data()[i][startPosition.GetColumn()]);
            }
            else
            {
                shipCells.clear();
            }
        }
        if (!shipCells.empty())
        {
            for (int vectIncr = 0; vectIncr < shipCells.size(); ++vectIncr)
            {
                shipCells[vectIncr]->SetShipMembership(true);
            }
        }
        else
        {
            return false;
        }
    }
      
    return true;
}