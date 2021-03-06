#ifndef PLAYER_H
#define PLAYER_H

#include "HitBoard.h"
#include "ShipBoard.h"
#include "Strategy.h"
#include <memory>

namespace player
{
    enum PlayerStrategy
    {
        humanStrategy,
        computerStrategy
    };

    class Player
    {
    public:

        /**
        *  \brief Default constructor.
        */
        Player();

        /**
        *  \brief Destructor.
        */
        ~Player();

        /**
        *  \brief Select the strategy for the player.
        *  \param[in] playerStrategy Player strategy. Can be computer or human.
        */
        void SelectStrategy(PlayerStrategy playerStrategy);

        /**
        *  \brief Get a reference to the ship board.
        *  \details The ship board is containing the ship added by player.
        *  \return A reference to the ship board.
        */
        const shipboard::ShipBoard& GetShipBoard() const
        {
            return m_shipBoard;
        }

        /**
        *  \brief Get a reference to the hit board.
        *  \details Hit board will contain the marks for the hits.
        *  \return A reference to the hit board.
        */
        const hitboard::HitBoard& GetHitBoard() const
        {
            return m_hitBoard;
        }

        /**
        *  \brief Get the player strategy.
        *  \return A pointer to the strategy.
        */
        std::shared_ptr<strategy::Strategy> GetStrategy() const
        {
            return m_strategy;
        }

        /**
        *  \brief Initialize Hit and Ship boards
        */
        void InitBoards();

        /**
        *  \brief Mark a hit cell.
        *  \param[in] cell Cell that will be marked as hit.
        */
        void Mark(const cell::Cell & cell, bool & intoShip);

        /**
        *  \brief Attack opponent.
        *  \return Cell to be marked as hit
        */
        cell::Cell Fire();

        /**
        *  \brief Check if the player was defeated.
        *  \return True if the player was defeated, false otherwise.
        */
        bool Defeated();

        /**
        *  \brief Mark a hit cell on HitBoard.
        *  \param[in] cell Cell that will be marked as hit.
        *  \param[in] intoShip A flag if the cell is part of the ship.
        */
        void FillHitBoard(const cell::Cell & cell, bool intoShip);

    private:

        std::shared_ptr<strategy::Strategy> m_strategy;

        shipboard::ShipBoard m_shipBoard;
        hitboard::HitBoard m_hitBoard;
    };

}

#endif //PLAYER_H