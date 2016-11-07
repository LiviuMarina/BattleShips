#include "stdafx.h"
#include "HumanStrategy.h"
#include "Helper.h"
#include <iostream> 
#include <string>
#include <fstream>
#include <exception>

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
        std::cout << "Please select location to attack (A-J and 0-9):" << std::endl;
        std::string attackLocation = "";
        std::cin >> attackLocation;

        std::cout << "Attacked cell: " << attackLocation << std::endl;

        cell::Cell attackCell;
        if (!helper::StringToCell(attackLocation, attackCell))
        {
            return cell::Cell();
        }

        return attackCell;
    }

    bool HumanStrategy::GenerateShip()
    {
        std::ifstream shipsFile;
        shipsFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            shipsFile.open("ShipsFile.txt");
            std::string txtLine;

            while (!shipsFile.eof()) 
            {
                cell::Cell startPosition, endPosition;

                getline(shipsFile, txtLine);
                std::string pointsDelimiter = ",";

                int pos = txtLine.find(pointsDelimiter);
                std::string startPoint = txtLine.substr(0, pos);
                int nextPointStart = pos + 1;
                int strLenght = txtLine.length();
                int numberOfChars = strLenght - nextPointStart;
                std::string endPoint = txtLine.substr(nextPointStart, numberOfChars);

                if (!helper::StringToCell(startPoint, startPosition))
                {
                    return false;
                }

                if (!helper::StringToCell(endPoint, endPosition))
                {
                    return false;
                }

                if (!m_shipBoard.AddShip(startPosition, endPosition))
                {
                    return false;
                }

            }
            shipsFile.close();

            return true;
        }

        catch (std::ifstream::failure & e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "Ships config file cannot be found. Enter the ships manually" << std::endl;
        }        

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

