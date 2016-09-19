// BattleShip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ostream>
#include "Game.h"

int _tmain(int argc, _TCHAR* argv[])
{ 
    std::cout << "Welcome to BattleShip game " << std::endl;
    std::cout << "Start the game? y/n" << std::endl;

    bool startGame = false;
    char startGameResponse;
    std::cin >> startGameResponse;

    if (startGameResponse == 'y')
    {   
        startGame = true;

        if (startGame)
        {
            Game game;
            game.CreateGame();

        }
        else
        {
            return 0;
        }

    }    

	return 0;
}

