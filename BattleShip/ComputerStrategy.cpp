#include "stdafx.h"
#include "ComputerStrategy.h"
#include <vector>
#include <utility>
#include <random>
#include <chrono>
#include <algorithm>
#include "Helper.h"

namespace{

    /**
    *  \brief Generate time-based random vectors of integers.
    *  \param[in/out] rows Vector of rows indexes.
    *  \param[in/out] columns Vector of columns indexes.
    */
    void GenerateRandomVectors(std::vector<int> & rows, std::vector<int> & columns)
    {
        // obtain a time-based seed:
        unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
        std::shuffle(rows.begin(), rows.end(), std::default_random_engine(seed));
        std::shuffle(columns.begin(), columns.end(), std::default_random_engine(seed + 1));
    }

    /**
    *  \brief Search a free column index to add a ship.
    *  \param[in] randomShips Vector of random ships.
    *  \param[in/out] shipCol Column index.
    */
    void searchFreeColumnNumber(const std::vector<std::pair<cell::Cell, cell::Cell>> & randomShips, int & shipCol)
    {
        for (int i = 0; i < randomShips.size(); ++i)
        {
            //search if the column index is already part of a ship
            if ((randomShips[i].first.GetColumn() <= shipCol) && (randomShips[i].second.GetColumn() >= shipCol))
            {
                if (shipCol < helper::NO_OF_COLUMNS - 1)
                {
                    shipCol++;
                }
                else
                {
                    shipCol = 0;
                }

                //call the method with a new value for shipCol
                searchFreeColumnNumber(randomShips, shipCol);
                break;
            }
        }
    }

    /**
    *  \brief Search a free row index to add a ship.
    *  \param[in] randomShips Vector of random ships.
    *  \param[in/out] shipRow Row index.
    */
    void searchFreeRowNumber(const std::vector<std::pair<cell::Cell, cell::Cell>> & randomShips, int & shipRow)
    {
        for (int i = 0; i < randomShips.size(); ++i)
        {
            //search if the row index is already part of a ship
            if ((randomShips[i].first.GetRow() <= shipRow) && (randomShips[i].second.GetRow() >= shipRow))
            {
                if (shipRow < helper::NO_OF_ROWS - 1)
                {
                    shipRow++;
                }
                else 
                {
                    shipRow = 0;
                }

                //call the method with a new value for shipRow
                searchFreeRowNumber(randomShips, shipRow);
                break;
            }
        }
    }
    
    /**
    *  \brief Add random coordinates to generate ships.
    *  \param[in] row A vector of cells row.
    *  \param[in] columns A vector of cells column.
    *  \param[in] shipType Ship type.
    *  \param[out] randomShips Random generated ships coordinates.
    */
    void AddRandomCoord(const std::vector<int> & rows,
        const std::vector<int> & columns, 
        helper::ShipType shipType, 
        std::vector<std::pair<cell::Cell, cell::Cell>> & randomShips)
    {
        std::pair<cell::Cell, cell::Cell>  ship;
        helper::Orientation orientation = helper::horizontally;
        int noOfCells = static_cast<helper::ShipType> (shipType);

        if (noOfCells % 2)
        {
            orientation = helper::vertical;
        }

        int iterations = 1;
        if (shipType == helper::ShipType::destroyer || shipType == helper::ShipType::submarine)
        {
            iterations = 2;
        }

        for (int i = 1; i <= iterations; ++i)
        {
            if (orientation == helper::horizontally)
            {
                int prevStartRow = 0,prevEndRow = 0;
                int shipRow = rows[noOfCells * i];

                if (!randomShips.empty())
                {
                    searchFreeRowNumber(randomShips, shipRow);
                }

                auto startColumn = find_if(columns.begin(),columns.end(),[=](const int column)
                                                                         {
                                                                            return column == noOfCells;
                                                                         });

                auto index = std::distance(columns.begin(), startColumn);
                                
                ship.first.SetRow(shipRow);
                ship.first.SetCol(columns[index]);

                ship.second.SetRow(shipRow);
                ship.second.SetCol((columns[index] + (noOfCells - 1)));
            }

            else
            {
                int prevStartCol = 0, prevEndCol = 0;
                int shipCol = columns[noOfCells * i];

                if (!randomShips.empty())
                {
                    searchFreeColumnNumber(randomShips, shipCol);
                }

                auto startRow = find_if(rows.begin(),rows.end(), [=](const int row)
                                                                 {
                                                                    return row == noOfCells;
                                                                 });

                auto index = std::distance(rows.begin(), startRow);
                
                ship.first.SetRow(rows[index]);
                ship.first.SetCol(shipCol);

                ship.second.SetRow(rows[index] + (noOfCells - 1));
                ship.second.SetCol(shipCol);
            }

            randomShips.push_back(ship);
        }
    }

    /**
    *  \brief Generates random coordinates for ships.
    *  \return A vector filled with random coordinates for ships
    */
    std::vector<std::pair<cell::Cell, cell::Cell>> GenerateRandomCoord()
    {
        std::vector<std::pair<cell::Cell, cell::Cell>>randomCoord;

        std::vector<int> rows = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::vector<int> columns = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        GenerateRandomVectors(rows, columns);

        for (int i = helper::MAX_TYPE - 1; i >= 1; --i)
        {
            helper::ShipType type = static_cast<helper::ShipType> (i);
            (AddRandomCoord(rows, columns, type, randomCoord));
        }      

        return randomCoord;
    }

    /**
    *  \brief Select a cell to be attacked.
    *  \param[in/out] attackedCells reference to a set of attacked cell.
    *  \param[in/out] attackCell Cell to be hit.
    */
    void SearchForShipCell( std::set<cell::Cell> & attackedCells, cell::Cell & attackCell)
    {
        std::vector<int> rows = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        std::vector<int> columns = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        GenerateRandomVectors(rows, columns);

        cell::Cell tempCell;
        for (int i = 0; i < rows.size(); ++i)
        {
            tempCell.SetRow(rows[i]);
            tempCell.SetCol(columns[i]);

            std::pair<std::set<cell::Cell>::iterator, bool> insertPair;
            insertPair = attackedCells.insert(tempCell);

            if(insertPair.second)
            {
                break;
            }
            else
            {
                continue;
            }
        }
        attackCell = tempCell;
    }
}

/**
*  \brief Select a proximity cell.
*  \param[in] lastAttackedCell Last attacked cell.
*  \param[in/out] attackCell Cell to be hit.
*  \param[in/out] attackedCells reference to a set of attacked cell.
*/
void SearchProximityCell(const cell::Cell & lastAttackedCell, cell::Cell & attackCell, std::set<cell::Cell> & attackedCells)
{
    attackCell.SetCol(lastAttackedCell.GetColumn());
    attackCell.SetRow(lastAttackedCell.GetRow());

    int initialSize = attackedCells.size();

    if (lastAttackedCell.GetColumn() < helper::NO_OF_COLUMNS - 1)
    {
        while ((!attackedCells.insert(attackCell).second) && (attackCell.GetColumn() < helper::NO_OF_COLUMNS - 1))
        {
            attackCell.SetCol(attackCell.GetColumn() + 1);
        }        
    }
    else
    {
        if (attackCell.GetColumn() > 0)
        {
            while ((!attackedCells.insert(attackCell).second) || (attackCell.GetColumn() > 0))
            {
                attackCell.SetCol(attackCell.GetColumn() - 1);
            }
        }
    }

    if (initialSize == attackedCells.size()) //no cell was inserted
    {
        attackCell.SetCol(lastAttackedCell.GetColumn());

        if (lastAttackedCell.GetRow() < helper::NO_OF_ROWS - 1)
        {
            while ((!attackedCells.insert(attackCell).second) && (attackCell.GetRow() < helper::NO_OF_ROWS - 1))
            {
                attackCell.SetRow(attackCell.GetRow() + 1);
            }
        }
        else
        {
            if (attackCell.GetRow() > 0)
            {
                while ((!attackedCells.insert(attackCell).second) || (attackCell.GetRow() > 0))
                {
                    attackCell.SetRow(attackCell.GetRow() - 1);
                }
            }
        }        
    }
}

namespace strategy
{
    ComputerStrategy::ComputerStrategy(hitboard::HitBoard & hitBoard, shipboard::ShipBoard & shipBoard)
        :m_hitBoard(hitBoard),
        m_shipBoard(shipBoard),
        m_attackedCells(),
        m_lastAttackedCell()
    {}

    ComputerStrategy::~ComputerStrategy()
    {}

    cell::Cell ComputerStrategy::Fire()
    {
        cell::Cell attackCell;

        if (m_attackedCells.empty())
        {
            attackCell.SetCol(0);
            attackCell.SetRow(0);

            m_attackedCells.insert(attackCell);
        }
        else
        {
            for (auto i : m_hitBoard.GetInitializedBoard())
            {
                //get the last attacked cell
                std::vector<cell::CellProperties>::iterator cellIter =
                    std::find_if(
                    i.begin(),
                    i.end(),
                    [&](cell::CellProperties cell)
                {
                    return (cell.GetColumn() == m_lastAttackedCell.GetColumn() && cell.GetRow() == m_lastAttackedCell.GetRow());
                });

                if (cellIter != i.end())
                {
                    //check if is part of a ship
                    if (cellIter->GetShipMembership())
                    {
                        SearchProximityCell(m_lastAttackedCell, attackCell, m_attackedCells);
                    }
                    else
                    {
                        SearchForShipCell(m_attackedCells, attackCell);
                    }
                }
            }
        }

        m_lastAttackedCell = attackCell;

        return attackCell;
    }

    bool ComputerStrategy::GenerateShip()
    {
        std::vector<std::pair<cell::Cell, cell::Cell>>randomShips;
        randomShips = GenerateRandomCoord();

        for (auto ship : randomShips)
        {
            if (!m_shipBoard.AddShip(ship.first, ship.second))
            {
                return false;
            }
        }
        return true;
    }
}

