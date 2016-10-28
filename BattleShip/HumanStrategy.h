#ifndef HUMANSTRATEGY_H
#define HUMANSTRATEGY_H

#include "Strategy.h"
#include "HitBoard.h"
#include "ShipBoard.h"

namespace strategy
{
    class HumanStrategy :public Strategy
    {
    public:
        /**
        *  \brief Class constructor.
        *  \param[in] hitBoard Board where to keep marks for the hits.
        *  \param[in] shipBoard Board were are stored the ships.
        */
        HumanStrategy(hitboard::HitBoard & hitBoard, shipboard::ShipBoard & shipBoard);

        /**
        *  \brief Virtual destructor.
        */
        ~HumanStrategy();

        /**
        *  \brief Attack opponent.
        *  \return Cell to be marked as hit
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
    };
}

#endif //HUMANSTRATEGY_H