#include "stdafx.h"
#include "ComputerStrategy.h"
#include <vector>
#include <utility>
#include <random>
#include <chrono>

namespace{

    //Add random coordinates to generate ships
    void AddRandomCoord(std::vector<int> rows, std::vector<int>columns, ShipType shipType, std::vector<std::pair<Cell, Cell>> & randomShips)
    {
        std::pair<Cell, Cell>  ship;
        Orientation orientation = orizontal;
        int noOfCells = static_cast<ShipType> (shipType);

        if (noOfCells % 2)
        {
            orientation = vertical;
        }

        int iterations = 1;
        if (shipType == ShipType::destroyer || shipType == ShipType::submarine)
        {
            iterations = 2;
        }

        for (int i = 1; i <= iterations; ++i)
        {
            if (orientation == orizontal)
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
                        if (prevStartRow > 0)
                        {
                            shipRow = prevStartRow - 1;
                        }

                        else
                        {
                            shipRow = prevEndRow - 1;
                        }
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
                        if (prevStartCol > 0)
                        {
                            shipCol = prevStartCol - 1;
                        }
                        else
                        {
                            shipCol = prevEndCol - 1;
                        }
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

    //Generate random coordinates for computer strategy
    std::vector<std::pair<Cell, Cell>> GenerateRandomCoord()
    {
        std::vector<std::pair<Cell, Cell>>randomCoord;

        std::vector<int> rows = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        std::vector<int> columns = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        
        // obtain a time-based seed:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(rows.begin(), rows.end(), std::default_random_engine(seed));
        std::shuffle(columns.begin(), columns.end(), std::default_random_engine(seed+1));

        for (int i = MAX_TYPE - 1; i >= 1; --i)
        {
            ShipType type = static_cast<ShipType> (i);
            (AddRandomCoord(rows, columns, type, randomCoord));
        }      

        return randomCoord;
    }
}

ComputerStrategy::ComputerStrategy(OpponentBoard & opponentBoard, PlayerBoard & playerBoard)
    :m_opponentBoard(opponentBoard),
    m_playerBoard(playerBoard)
{}

ComputerStrategy::~ComputerStrategy()
{}

void ComputerStrategy::Mark(Cell cell)
{}

Cell & ComputerStrategy::Fire()
{
    return Cell();
}

bool ComputerStrategy::AddShip()
{

    std::vector<std::pair<Cell, Cell>>randomShips;
    randomShips = GenerateRandomCoord();

    for (auto ship : randomShips)
    {
        if (!m_playerBoard.AddShip(ship.first, ship.second))
        {
            return false;
        }
    }
    
    return true;
}

