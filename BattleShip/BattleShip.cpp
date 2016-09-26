// BattleShip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ostream>
#include "Game.h"
#include <string>

namespace{

    bool StringToCell(std::string inputStr, Cell & resultedCell)
    {
        bool result = false;

        if (inputStr.length() == 2)
        {
            resultedCell.SetRow(inputStr[0]);
            resultedCell.SetCol(int(inputStr[1]) - 48);
            result = true;
        }

        else
        {
            std::cout << "Wrong Cell format" << std::endl;

        }

        return result;

    }
}

int _tmain(int argc, _TCHAR* argv[])
{ 
    std::cout << "Welcome to BattleShip game " << std::endl;
    std::cout << "Start the game? y/n" << std::endl;

    //bool startGame = false;
    char startGameResponse;
    std::cin >> startGameResponse;

    Game game;

    if (startGameResponse == 'y')
    {  
        game.CreateGame();

        std::cout << "Game is started. Please add ships for battle"<<std::endl;
    } 

    int maxNoOfShips = 0;

    while (maxNoOfShips < 5)
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

        if (!game.GetHumanPlayer()->GetPlayerStrategy()->AddShip(startPosition, endPosition))
        {
            std::cout << "One or more cells belongs to another ship. Please enter other positions" << std::endl;
        }

        ++maxNoOfShips;
    }
    


	return 0;
}

