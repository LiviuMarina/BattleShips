#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <memory>

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

    private:

        player::Player m_humanPlayer;
        player::Player m_computerPlayer;
    };

}

#endif //GAME_H