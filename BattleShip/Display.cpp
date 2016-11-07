#include "stdafx.h"
#include "Display.h"
#include "Helper.h"

namespace display
{   
    Display::Display(const shipboard::ShipBoard& shipBoard, const hitboard::HitBoard& hitBoard)
        :m_shipBoard(shipBoard),
        m_hitBoard(hitBoard)
    {
    }
    

    Display::~Display()
    {
    }

    void Display::Draw()
    {
        system("cls");

        //plot shipBoard
        std::cout << "Ship Board"<< std::endl;
        std::cout << " " << '|';

        for (int i = 0; i < helper::NO_OF_COLUMNS; ++i)
        {
            std::cout << i << '|';
        }
        std::cout << std::endl;

        for (int i = 0; i < helper::NO_OF_ROWS; ++i)
        {
            char row = static_cast<char> (i + DEC_TO_ASCII);
            std::cout << row << '|';

            const std::vector<std::vector<cell::CellProperties>> initBoard = m_shipBoard.GetInitializedBoard();
            for (auto i : initBoard[i])
            {
                if (i.GetShipMembership())
                {
                    std::cout << '0' << '|';
                }
                else
                {
                    std::cout << '-' << '|';
                }
            }

            std::cout << std::endl;
        }

        //plot hitBoard
        std::cout << std::endl << std::endl;
        std::cout << "Hit Board" << std::endl;
        std::cout << " " << '|';

        for (int i = 0; i < helper::NO_OF_COLUMNS; ++i)
        {
            std::cout << i << '|';
        }
        std::cout << std::endl;

        for (int i = 0; i < helper::NO_OF_ROWS; ++i)
        {
            char row = static_cast<char> (i + DEC_TO_ASCII);
            std::cout << row << '|';

            const std::vector<std::vector<cell::CellProperties>> initBoard = m_hitBoard.GetInitializedBoard();
            for (auto i : initBoard[i])
            {
                if (i.GetHitState())
                {
                    if (i.GetShipMembership())
                    {
                        std::cout << '0' << '|';
                    }
                    else
                    {
                        std::cout << 'x' << '|';
                    }
                }
                else
                {
                    std::cout << '-' << '|';
                }
            }

            std::cout << std::endl;
        }        
    }
}
