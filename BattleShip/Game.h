#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <memory>

class Game
{
public:
    Game();
    ~Game();

    //Create a new game
    void CreateGame();

    //Exit from the current game
    void ExitGame();

    //Get human player
    const std::shared_ptr<Player> GetHumanPlayer() const;

    //Get computer player
    const std::shared_ptr<Player> GetComputerPlayer() const;

private:

    std::shared_ptr<Player> m_humanPlayer;
    std::shared_ptr<Player> m_computerPlayer;
};

#endif //GAME_H