#include "Cell.h"

#ifndef CELL_PROPERTIES
#define CELL_PROPERTIES

namespace cell
{
    class CellProperties : public Cell
    {
    public:

        /**
        *  \brief Default constructor.
        */
        CellProperties();

        /**
        *  \brief Destructor.
        */
        ~CellProperties();

        /**
        *  \brief Set membership property for cell.
        *  \param[in] intoShip Cell is part of a ship.
        */
        void SetShipMembership(bool intoShip)
        {
            m_intoShip = intoShip;
        }

        /**
        *  \brief Get membership property of a cell.
        *  \return True if the cell is part of a ship, false otherwise.
        */
        const bool GetShipMembership() const
        {
            return m_intoShip;
        }

        /**
        *  \brief Set hit flag for a cell.
        *  \details The cell was hit by enemy
        *  \param[in] intoShip Cell is part of a ship.
        */
        void SetHitState(bool isHit)
        {
            m_isHit = isHit;
        }

        /**
        *  \brief Check if the cell was hit.
        *  \return True if the cell was hit, false otherwise.
        */
        const bool GetHitState() const
        {
            return m_isHit;
        }

    private:

        bool m_isHit;
        bool m_intoShip;
    };
}

#endif //CELL_PROPERTIES