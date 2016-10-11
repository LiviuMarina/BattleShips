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

    Game game;       

    game.CreateGame();

    std::cout << "Game is started. Please add ships for battle" << std::endl;
    if (!game.GetHumanPlayer()->GetStrategy()->AddShip())
    {
        std::cout << "One or more ships failed to be added" << std::endl;
        return 0;
    }

    std::cout << "Ships were added. Wait for the computer to add the ships" << std::endl;

    if (!game.GetComputerPlayer()->GetStrategy()->AddShip())
    {
        std::cout << "Random ships failed to be added" << std::endl;
        return 0;
    }
       
    std::cout << "Random ships were added." << std::endl;

    while (!game.GetHumanPlayer()->GetPlayerBoard()->Defeated() && !game.GetComputerPlayer()->GetPlayerBoard()->Defeated())
    {
        game.GetHumanPlayer()->GetStrategy()->Mark(game.GetHumanPlayer()->GetStrategy()->Fire());
        game.GetHumanPlayer()->GetStrategy()->Mark(game.GetHumanPlayer()->GetStrategy()->Fire());

    }
    
	return 0;
}

