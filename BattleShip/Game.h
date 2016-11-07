#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <memory>
#include "Display.h"
#include <exception>

namespace game
{
    class Game
    {
    public:

        /**
        *  \brief Default constructor.
        */
        Game();

        /**
        *  \brief Destructor.
        */
        ~Game();

        /**
        *  \brief Create a new game.
        */
        void CreateGame();

        /**
        *  \brief Play a new game.
        *  \param[out] notDefeatead Flag that represents the game status .
        *  \return True if the game can play without errors, false otherwise.
        */
        bool Play(bool & notDefeatead);

        /**
        *  \brief Exit the game.
        */
        void ExitGame();

        /**
        *  \brief Get the human player.
        *  \return A reference to the human player.
        */
        player::Player& GetHumanPlayer()
        {
            return m_humanPlayer;
        }

        /**
        *  \brief Get the computer player.
        *  \return A reference to the computer player.
        */
        player::Player& GetComputerPlayer()
        {
            return m_computerPlayer;
        }

        /**
        *  \brief Return the object used to display the boards.
        *  \return A reference to display object.
        */
        std::shared_ptr<display::Display> GetDisplay()
        {
            std::exception_ptr p;
            if (m_display == nullptr)
                throw std::exception_ptr(p);

            return m_display;
        }

    private:

        std::shared_ptr<display::Display> m_display;

        player::Player m_humanPlayer;
        player::Player m_computerPlayer;
    };

}

#endif //GAME_H