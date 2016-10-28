// BattleShip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ostream>
#include "Game.h"
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{ 
    std::cout << "Welcome to BattleShip game " << std::endl;
    std::cout << "Start the game? y/n" << std::endl;

    char startGameResponse;
    std::cin >> startGameResponse;

    if (startGameResponse == 'n')
    {
        return 0;
    }

    game::Game game;       

    game.CreateGame();

    std::cout << "Game is started. Please add ships for battle" << std::endl;

    std::shared_ptr<strategy::Strategy> humanPlayerStrategy = game.GetHumanPlayer().GetStrategy();

    if (humanPlayerStrategy != NULL)
    {
        if (!humanPlayerStrategy->GenerateShip())
        {
            std::cout << "One or more ships failed to be added" << std::endl;
            return 0;
        }
    }
    else
    {
        return 0;
    }   

    std::cout << "Ships were added. Wait for the computer to add the ships" << std::endl;

    std::shared_ptr<strategy::Strategy> computerPlayerStrategy = game.GetComputerPlayer().GetStrategy();

    if (computerPlayerStrategy != NULL)
    {
        if (!computerPlayerStrategy->GenerateShip())
        {
            std::cout << "Random ships failed to be added" << std::endl;
            return 0;
        }
    }
    else
    {
        return 0;
    }
       
    std::cout << "Random ships were added." << std::endl;

    bool notDefeatead = true;

    while (notDefeatead)
    {
        if (!game.Play(notDefeatead))
        {
            std::cout << "Game was stopped." << std::endl;
            break;
        }
    }   
    
	return 0;
}

