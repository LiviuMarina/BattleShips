#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "Display.h"

namespace game
{
    Game::Game():
        m_display(NULL)
    {
    }

    Game::~Game()
    {
    }

    void Game::CreateGame()
    {
        //create players
        m_computerPlayer.InitBoards();
        m_computerPlayer.SelectStrategy(player::computerStrategy);

        m_humanPlayer.InitBoards();
        m_humanPlayer.SelectStrategy(player::humanStrategy);

        m_display = std::make_shared<display::Display>(m_humanPlayer.GetShipBoard(), m_humanPlayer.GetHitBoard());
    }

    void Game::ExitGame()
    {
    }

    bool Game::Play(bool & notDefeatead)
    {
        if (!m_humanPlayer.Defeated())
        {
            bool intoShip = false;
            cell::Cell attackedCell = m_humanPlayer.Fire();

            if (attackedCell == cell::Cell())
            {
                std::cout << "Invalid attack cell." << std::endl;
                return true;
            }

            m_computerPlayer.Mark(attackedCell, intoShip);
            m_humanPlayer.FillHitBoard(attackedCell, intoShip);         
            
        }
        else
        {
            std::cout << "Human player was defeated." << std::endl;
            notDefeatead = false;
        }

        if (!m_computerPlayer.Defeated())
        {
            bool intoShip = false;
            cell::Cell attackedCell = m_computerPlayer.Fire();

            if (attackedCell == cell::Cell())
            {
                std::cout << "Invalid attack cell." << std::endl;
                return true;
            }
            
            m_humanPlayer.Mark(attackedCell, intoShip);
            m_computerPlayer.FillHitBoard(attackedCell, intoShip);


            m_display->Draw();

            char rowChar = static_cast<char>(attackedCell.GetRow() + DEC_TO_ASCII);
            std::cout << "Computer attacked cell: " << rowChar << attackedCell.GetColumn() << std::endl;

            if (intoShip)
            {
                std::cout << "Success. A ship was hit" << std::endl;
            }
            else
            {
                std::cout << "Computer attack failed. No ship was hit" << std::endl;
            }
        }
        else
        {
            std::cout << "Computer player was defeated." << std::endl;
            notDefeatead = false;
        }

        return true;
    }
}


