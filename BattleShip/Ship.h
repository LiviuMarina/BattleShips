#ifndef SHIP_H
#define SHIP_H

#include "CellProperties.h"
#include "Helper.h"
#include <vector>

namespace ship
{
    class Ship
    {
    public:
        /**
        *  \brief Class constructor.
        *  \param[in] begin Ship starting point.
        *  \param[in] end Ship end point.
        */
        Ship(const cell::Cell & begin, const cell::Cell & end, helper::Orientation shipOrientation);

        /**
        *  \brief Class destructor.
        */
        ~Ship();

        /**
        *  \brief Check if the ship was sunk..
        *  \return True if the ship was sunk, false otherwise.
        */
        bool Sunk(const std::vector<std::vector<cell::CellProperties>> & boardCells) const;

    private:
        
        cell::Cell m_begin;
        cell::Cell m_end;

        helper::Orientation m_shipOrientation;
    };
}

#endif //SHIP_H