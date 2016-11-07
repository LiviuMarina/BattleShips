#ifndef BOARD_H
#define BOARD_H

#include "CellProperties.h"
#include <vector>
#include <memory>

namespace board{

    class Board
    {
    public:

        /**
        *  \brief Default constructor.
        */
        Board();

        /**
        *  \brief Destructor.
        */
        virtual ~Board();

        /**
        *  \brief Initialize the board
        *  \details Is allocating memory for each cell
        */
        void InitBoard();

        /**
        *  \brief Get the initialized the board
        */
        const std::vector<std::vector<cell::CellProperties>> & GetInitializedBoard()const
        {
            return m_boardCells;
        }

        /**
        *  \brief Refresh the board
        */
        void Refresh();

        /**
        *  \brief Set board width.
        *  \param[in] width Board width.
        */
        void SetWidth(int width)
        {
            m_width = width;
        }

        /**
        *  \brief Set board height.
        *  \param[in] height Board height.
        */
        void SetHeight(int height)
        {
            m_height = height;
        }  

    private:

        int m_width;
        int m_height;

    protected:

        std::vector<std::vector<cell::CellProperties>> m_boardCells;
    };
    
}

#endif //BOARD_H