#include "stdafx.h"
#include "ComputerStrategy.h"
#include <vector>
#include <utility>
#include <random>
#include <chrono>
#include <algorithm>

namespace{
    
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
                int prevStartRow = 0;
                int prevEndRow = 0;

                int shipRow = rows[noOfCells * i];

                if (!randomShips.empty())
                {
                    prevStartRow = randomShips[randomShips.size() - 1].first.GetRow();
                    prevEndRow = randomShips[randomShips.size() - 1].second.GetRow();

                    if ((shipRow > prevStartRow) && (shipRow < prevEndRow))
                    {
                        (prevStartRow > 0) ? (shipRow = prevStartRow - 1) : (shipRow = prevEndRow - 1);                        
                    }
                }

                auto startColumn = find_if(columns.begin(),
                    columns.end(),
                    [=](const int column)
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
                int prevStartCol = 0;
                int prevEndCol = 0;
                int shipCol = columns[noOfCells * i];

                if (!randomShips.empty())
                {
                    prevStartCol = randomShips[randomShips.size() - 1].first.GetColumn();
                    prevEndCol = randomShips[randomShips.size() - 1].second.GetColumn();

                    if ((shipCol > prevStartCol) && (shipCol < prevEndCol))
                    {
                        (prevStartCol > 0) ? (shipCol = prevStartCol - 1) : (shipCol = prevEndCol - 1);                        
                    } 
                }

                auto startRow = find_if(rows.begin(),
                    rows.end(),
                    [=](const int row)
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
        
        // obtain a time-based seed:
        unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
        std::shuffle(rows.begin(), rows.end(), std::default_random_engine(seed));
        std::shuffle(columns.begin(), columns.end(), std::default_random_engine(seed+1));

        for (int i = helper::MAX_TYPE - 1; i >= 1; --i)
        {
            helper::ShipType type = static_cast<helper::ShipType> (i);
            (AddRandomCoord(rows, columns, type, randomCoord));
        }      

        return randomCoord;
    }

    /**
    *  \brief Select a cell to be attacked.
    *  \param[in] lastCell Last attacked cell.
    *  \param[in] attackedCell Cell to be hit.
    */
    void SearchForShipCell(const cell::CellProperties & lastCell, cell::Cell & attackCell)
    {
        if (lastCell.GetColumn() < helper::NO_OF_COLUMNS - 1)
        {
            attackCell.SetCol(lastCell.GetColumn() + 1);
        }
        else
        {
            if (lastCell.GetColumn() > 0)
            {
                attackCell.SetCol(lastCell.GetColumn() - 1);
            }

        }

        if (lastCell.GetRow() < helper::NO_OF_ROWS - 1)
        {
            attackCell.SetRow(lastCell.GetRow() + 1);
        }
        else
        {
            if (lastCell.GetRow() > 0)
            {
                attackCell.SetRow(lastCell.GetRow() - 2);
            }
        }
    }
}

namespace strategy
{
    ComputerStrategy::ComputerStrategy(hitboard::HitBoard & hitBoard, shipboard::ShipBoard & shipBoard)
        :m_hitBoard(hitBoard),
        m_shipBoard(shipBoard)
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
        }
        else
        {
            int size = m_attackedCells.size();
            cell::CellProperties lastCell = m_attackedCells[size - 1];
            for (auto i : m_shipBoard.GetInitializedBoard())
            {
                std::vector<cell::CellProperties>::iterator cellIter =
                    std::find_if(
                    i.begin(),
                    i.end(),
                    [&](cell::CellProperties cell)
                {
                    return (cell.GetColumn() == lastCell.GetColumn() && cell.GetRow() == lastCell.GetRow());

                });

                if (cellIter != i.end())
                {
                    if (cellIter->GetShipMembership())
                    {
                        if (lastCell.GetColumn() < helper::NO_OF_COLUMNS - 1)
                        { 
                            attackCell.SetCol(lastCell.GetColumn() + 1);
                        }
                        else
                        {
                            attackCell.SetCol(lastCell.GetColumn() - 1);
                            attackCell.SetRow(lastCell.GetRow() + 1);
                        }
                        
                        attackCell.SetRow(lastCell.GetRow());
                    }

                    else
                    {
                        SearchForShipCell(lastCell, attackCell);
                    }
                }
            }
        }

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

