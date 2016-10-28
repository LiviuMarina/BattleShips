#include "stdafx.h"
#include "HumanStrategy.h"
#include "Helper.h"
#include <iostream> 
#include <string>

namespace strategy
{
    HumanStrategy::HumanStrategy(hitboard::HitBoard & hitBoard, shipboard::ShipBoard & shipBoard)
        :m_hitBoard(hitBoard),
        m_shipBoard(shipBoard)
    {}

    HumanStrategy::~HumanStrategy()
    {}

    cell::Cell HumanStrategy::Fire()
    {
        std::cout << "Please select location to attack:" << std::endl;
        std::string attackLocation = "";
        std::cin >> attackLocation;

        cell::Cell attackCell;
        if (!helper::StringToCell(attackLocation, attackCell))
        {
            return cell::Cell();
        }

        return attackCell;
    }

    bool HumanStrategy::GenerateShip()
    {
        int maxNoOfShips = 0;

        while (maxNoOfShips < 7)
        {
            cell::Cell startPosition, endPosition;
            std::cout << "Enter ship start point.Row between A and J, column between 0 and 9." << std::endl;
            std::string start = "";
            std::cin >> start;

            if (!helper::StringToCell(start, startPosition))
            {
                continue;
            }

            std::cout << "Enter ship end point.Row between A and J, column between 0 and 9." << std::endl;
            std::string end = "";
            std::cin >> end;

            if (!helper::StringToCell(end, endPosition))
            {
                continue;
            }

            if (!m_shipBoard.AddShip(startPosition, endPosition))
            {
                continue;
            }

            ++maxNoOfShips;

            std::cout << "You have entered: " << maxNoOfShips << "ships."<< std::endl;
        }

        return true;
    }
}

