#ifndef PLAYER_H
#define PLAYER_H

#include "OpponentBoard.h"
#include "PlayerBoard.h"
#include "Strategy.h"
#include <memory>

enum PlayerStrategy
{
    humanStrategy,
    computerStrategy
};

class Player
{
public:

    Player(PlayerStrategy playerStrategy);
    ~Player();

    //Select the Player's strategy
    //details: The strategy can be "human" or "computer"
    void SelectStrategy();

    //Select the Board
    //details: Can be selected the board for player or for opponent 
    void SelectBoard();


private:

    std::shared_ptr<Strategy> m_strategy;
    PlayerBoard * m_playerBoard;
    OpponentBoard * m_opponentBoard;

    PlayerStrategy m_playerStrategy;
};


#endif //PLAYER_H