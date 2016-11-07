#ifndef COMPUTERSTRATEGY_H
#define COMPUTERSTRATEGY_H

#include "Strategy.h"
#include "HitBoard.h"
#include "ShipBoard.h"
#include <set>

namespace strategy
{
    class ComputerStrategy :public Strategy
    {
    public:

        /**
        *  \brief Default constructor.
        */
        ComputerStrategy(hitboard::HitBoard & opponentBoard, shipboard::ShipBoard & playerBoard);

        /**
        *  \brief Virtual destructor.
        */
        ~ComputerStrategy();

        /**
        *  \brief Attack opponent.
        *  \return Cell to be marked as hit.
        */
        virtual cell::Cell Fire();

        /**
        *  \brief Generate ship.
        *  \return True is the ship was generated, false otherwise.
        */
        virtual bool GenerateShip();


    private:

        hitboard::HitBoard & m_hitBoard;
        shipboard::ShipBoard & m_shipBoard;

        std::set<cell::Cell> m_attackedCells;
        cell::Cell m_lastAttackedCell;
    };
}

#endif //COMPUTERSTRATEGY_H