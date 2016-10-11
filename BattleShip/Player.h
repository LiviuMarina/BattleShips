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

    //Get player board
    std::shared_ptr<PlayerBoard> GetPlayerBoard()
    {
        return m_playerBoard;
    }

    //Get opponent board
    std::shared_ptr<OpponentBoard> GetOpponentBoard()
    {
        return m_opponentBoard;
    }

    //Get player strategy
    std::shared_ptr<Strategy> GetStrategy() const
    {
        return m_strategy;
    }

private:

    std::shared_ptr<Strategy> m_strategy;

    std::shared_ptr<PlayerBoard> m_playerBoard;
    std::shared_ptr<OpponentBoard> m_opponentBoard;

    PlayerStrategy m_playerStrategy;
};


#endif //PLAYER_H