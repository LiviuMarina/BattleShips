#include "stdafx.h"
#include "ShipBoard.h"

namespace{

    /**
    *  \brief Get the ship orientation.
    *  \param[in] startPosition Ship start position.
    *  \param[in] endPosition Ship end position.
    *  \return Ship orientation (horizontally or vertical).
    */
    helper::Orientation CheckShipOrientation(const cell::Cell & startPosition, const cell::Cell & endPosition)
    {
        helper::Orientation orientation;

        if (startPosition.GetRow() != endPosition.GetRow())
        {
            orientation = helper::Orientation::vertical;
        }

        else
        {
            orientation = helper::Orientation::horizontally;
        }

        return orientation;
    }

    /**
    *  \brief Check if the cell is not already into a ship.
    *  \param[in] row Cell row.
    *  \param[in] column Cell column.
    *  \param[in] boardCells A reference to the board.
    *  \return True if the cell is free, false otherwise.
    */
    bool CheckFreeSpaceForShip(int row, int column, const std::vector<std::vector<cell::CellProperties>> & boardCells)
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
    bool ShipTypeOccurence(helper::ShipType shipType)
    {
        std::vector <helper::ShipType> addedShipTypes;
        int occurence = 0;
        for (auto item : addedShipTypes)
        {
            if (shipType == item)
            {
                ++occurence;
            }

            if (shipType == helper::destroyer || shipType == helper::submarine)
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

namespace shipboard
{
    ShipBoard::ShipBoard()
        :m_Ships()
    {}

    ShipBoard::~ShipBoard()
    {}

    bool ShipBoard::AddShip(const cell::Cell & startPosition, const cell::Cell & endPosition)
    {
        helper::Orientation orientation = CheckShipOrientation(startPosition, endPosition);

        if (orientation == helper::horizontally)
        {
            int rowNumber = (int)startPosition.GetRow();
            std::vector<cell::CellProperties *> shipCells;

            //int shipNumberOfCells = startPosition.GetColumn() - endPosition.GetColumn();
            //ShipTypeOccurence(static_cast<ShipType>(shipNumberOfCells));

            for (int i = startPosition.GetColumn() ; i < (endPosition.GetColumn()+1); ++i)
            {
                if (CheckFreeSpaceForShip(rowNumber, i, m_boardCells))
                {
                    shipCells.push_back(&m_boardCells.data()[rowNumber][i]);
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

        else if (orientation == helper::vertical)
        {
            std::vector<cell::CellProperties *> shipCells;

            for (int i = startPosition.GetRow(); i < (endPosition.GetRow() + 1); ++i)
            {
                if (CheckFreeSpaceForShip(i, startPosition.GetColumn(), m_boardCells))
                {
                    shipCells.push_back(&m_boardCells.data()[i][(startPosition.GetColumn())]);
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
                std::vector<cell::CellProperties *>::const_iterator vectInter = shipCells.begin();
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

        ship::Ship ship(startPosition, endPosition, orientation);
        m_Ships.push_back(ship);
        return true;
    }

    const std::vector<ship::Ship> & ShipBoard::GetShips() const
    {
        return m_Ships;
    }

    bool ShipBoard::Defeated() const
    {
        for (auto ship : m_Ships)
        {
            if (!ship.Sunk(m_boardCells))
            {
                return false;
            }
        }
        return true;
    }

    bool ShipBoard::Mark(const cell::Cell & hitCell, bool & intoShip)
    {
        std::vector<std::vector<cell::CellProperties>>::iterator boardIter = m_boardCells.begin();
        for (; boardIter != m_boardCells.end(); ++boardIter)
        {
            std::vector<cell::CellProperties > ::iterator cellIter =
                std::find_if(boardIter->begin(), boardIter->end(),
                [&](const cell::Cell & cell)
            {
                return ((cell.GetColumn() == hitCell.GetColumn()) && (cell.GetRow() == hitCell.GetRow()));
            });

            if (cellIter != boardIter->end())
            {
                if (cellIter->GetHitState())
                {
                    return false;
                    std::cout << "Cell was already hit" << std::endl;
                }

                intoShip = cellIter->GetShipMembership();
                cellIter->SetHitState(true);

                break;
            }            
        }        

        return true;
    }
}

