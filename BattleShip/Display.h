#ifndef DISPLAY
#define DISPLAY

#include "ShipBoard.h"
#include "HitBoard.h"

namespace display
{
    class Display
    {
    public:
        /**
        *  \brief Constructor.
        *  \param[in] shipBoard A reference to the ship board.
        *  \param[in] hitBoard A reference to the hit board.
        */
        Display(const shipboard::ShipBoard& shipBoard, const hitboard::HitBoard& hitBoard);

        /**
        *  \brief Destructor.
        */
        ~Display();

        /**
        *  \brief Draw the boards in console.
        */
        void Draw();

    private:

        const shipboard::ShipBoard & m_shipBoard;
        const hitboard::HitBoard & m_hitBoard;

    };
}

#endif //DISPLAY

