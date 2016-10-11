#include "stdafx.h"
#include "Ship.h"
#include <vector>
#include <iostream>


namespace{

    // Get the ship orientation
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

    // Check if the ship will not be generated in an occupied cell
    bool CheckFreeSpaceForShip(int row, int column, const CellPropertiesArray & boardCells)
    {
        bool result = false;

        if (!boardCells[row][column].GetShipMembership())
        {
            result = true;
        }

        return result;
    }

    //Check if the ship of specific type was already added
    //details: Is not used in this moment
    bool ShipTypeOccurence(ShipType shipType)
    {
        std::vector <ShipType> addedShipTypes;
        int occurence = 0;
        for (auto item : addedShipTypes)
        {
            if (shipType == item)
            {
                ++occurence;
            }

            if (shipType == destroyer || shipType == submarine)
            {  
                if (occurence >= 2)
                {
                    return false;
                }
            }
            else
            {
                if (occurence >= 1)
                {
                    return false;
                }
            }
        }        
        return true;
    }
}

Ship::Ship()
{}

Ship::~Ship()
{}

bool Ship::GenerateShip(Cell & startPosition, Cell & endPosition, CellPropertiesArray & boardCells)
{
    if (startPosition == endPosition)
    {
        std::cout << "Start and End position are the same. Please enter different values" << std::endl;
        return false;
    }

    Orientation orientation = CheckShipOrientation(startPosition, endPosition);

    if (orientation == orizontal)
    {     
        int rowNumber = (int)startPosition.GetRow();
        std::vector<CellProperties *> shipCells;

        //int shipNumberOfCells = startPosition.GetColumn() - endPosition.GetColumn();
        //ShipTypeOccurence(static_cast<ShipType>(shipNumberOfCells));

        for (int i = startPosition.GetColumn(); i < (endPosition.GetColumn() + 1); ++i)
        {  
            if (CheckFreeSpaceForShip(rowNumber, i, boardCells))
            {
                shipCells.push_back(&boardCells.data()[rowNumber][i]);
            }
            else
            {
                std::cout << "One or more cells belongs to another ship. Please enter other positions" << std::endl;
                shipCells.clear();
                break;
            }           
        }
        if (!shipCells.empty())
        {
            for (int vectIncr = 0; vectIncr < (int)shipCells.size(); ++vectIncr)
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
        std::vector<CellProperties *> shipCells;

        for (int i = startPosition.GetRow(); i < (endPosition.GetRow() + 1); ++i)
        {
            if (CheckFreeSpaceForShip(i, startPosition.GetColumn(), boardCells))
            {
                shipCells.push_back(&boardCells.data()[i][startPosition.GetColumn()]);
            }
            else
            {
                std::cout << "One or more cells belongs to another ship. Please enter other positions" << std::endl;
                shipCells.clear();
                break;
            }
        }
        if (!shipCells.empty())
        {   
            std::vector<CellProperties *>::const_iterator vectInter = shipCells.begin();
            for (; vectInter != shipCells.end(); ++vectInter)
            {
                (*vectInter)->SetShipMembership(true);
            }
        }
        else
        {
            return false;
        }
    }
      
    return true;
}