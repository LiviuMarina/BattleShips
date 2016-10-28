#ifndef STRATEGY_H
#define STRATEGY_H

#include "Cell.h"

namespace strategy
{
    class Strategy
    {
    public:
        /**
        *  \brief Default constructor.
        */
        Strategy()
        {}

        /**
        *  \brief Virtual destructor.
        */
        virtual ~Strategy()
        {}

        /**
        *  \brief Attack opponent.
        *  \return Cell to be marked as hit
        */
        virtual cell::Cell Fire() = 0;

        /**
        *  \brief Generate ship.
        *  \return True is the ship was generated, false otherwise.
        */
        virtual bool GenerateShip() = 0;
    };

}

#endif //STRATEGY_H