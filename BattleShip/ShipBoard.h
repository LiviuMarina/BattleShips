#ifndef SHIPBOARD_H
#define SHIPBOARD_H

#include "Board.h"
#include "Cell.h"
#include "Ship.h"
#include <vector>

using namespace board;

namespace shipboard
{
    class ShipBoard :public Board
    {
    public:
        /**
        *  \brief Default constructor.
        */
        ShipBoard();

        /**
        *  \brief Destructor.
        */
        ~ShipBoard();

        /**
        *  \brief Add ship into the board.
        *  \param[in] startPosition Ship start position.
        *  \param[in] endPosition Ship end position.
        *  \return True if the ship was added with success, false otherwise.
        */
        bool AddShip(const cell::Cell & startPosition, const cell::Cell & endPosition);

        /**
        *  \brief Get a vector of added ships.
        *  \return A const reference to the vector of added ships.
        */
        const std::vector<ship::Ship> & GetShips() const;

        /**
        *  \brief Check if the player is defeated.
        *  \return True is the player was defeated, false otherwise..
        */
        bool Defeated() const;

        /**
        *  \brief Mark into ship board the hit cell.
        *  \param[in] cell Cell to be marked as hit.
        *  \param[out] intoShip Checks if the cell is a ship member.
        *  \return True if the cell was not attacked before, false otherwise.
        */
        bool Mark(const cell::Cell & cell, bool & intoShip);

    private:

        std::vector<ship::Ship> m_Ships;
    };

}
#endif //SHIPBOARD_H

