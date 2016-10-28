#ifndef HITBOARD_H
#define HITBOARD_H

#include "Cell.h"
#include "Helper.h"
#include "Board.h"
#include <array>

using namespace board;

namespace hitboard
{
    class HitBoard : public Board
    {
    public:

        /**
        *  \brief Default constructor.
        */
        HitBoard();

        /**
        *  \brief Destructor.
        */
        ~HitBoard();

        /**
        *  \brief Mark the cell that was hit.
        *  \param[in] hitCell Cell to be marked.
        */
        void Mark(const cell::Cell & hitCell, bool intoShip);
    };
}


#endif //HITBOARD_H