#include "stdafx.h"
#include "HumanStrategy.h"
#include "Helper.h"
#include <iostream> 
#include <string>

HumanStrategy::HumanStrategy(OpponentBoard & opponentBoard, PlayerBoard & playerBoard)
    :m_opponentBoard(opponentBoard),
    m_playerBoard(playerBoard)
{}

HumanStrategy::~HumanStrategy()
{}

void HumanStrategy::Mark(Cell cell)
{}

Cell & HumanStrategy::Fire()
{
    return Cell();
}

bool HumanStrategy ::AddShip()
{
    int maxNoOfShips = 1;

    while (maxNoOfShips < 8)
    {
        Cell startPosition, endPosition;
        std::cout << "Enter ship start point:" << std::endl;
        std::string start = "";
        std::cin >> start;

        if (!StringToCell(start, startPosition))
        {
            continue;
        }

        std::cout << "Enter ship end point:" << std::endl;
        std::string end = "";
        std::cin >> end;

        if (!StringToCell(end, endPosition))
        {
            continue;
        }

        if (!m_playerBoard.AddShip(startPosition, endPosition))
        {
            continue;
        }

        ++maxNoOfShips;

        std::cout << "You have entered: " << maxNoOfShips << std::endl;
    }

    return true;   
}

