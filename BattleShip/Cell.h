#ifndef CELL_H
#define CELL_H

const int DEC_TO_ASCII = 65;

namespace cell
{
    class Cell
    {
    public:

        /**
        *  \brief Default constructor
        */
        Cell();

        /**
        *  \brief Constructor
        */
        Cell(int row, int column);

        /**
        *  \brief Destructor
        */
        virtual ~Cell();

        /**
        *  \brief Set cell row value.
        *  \param[in] row Cell row.
        */
        void SetRow(int row)
        {
            m_row = row;
        }

        /**
        *  \brief Get cell row.
        *  \return Cell row value.
        */
        const int GetRow() const
        {
            return m_row;
        }

        /**
        *  \brief Set cell column value.
        *  \param[in] row Cell row.
        */
        void SetCol(int column)
        {
            m_column = column;
        }

        /**
        *  \brief Get cell column.
        *  \return Cell row value.
        */
        const int GetColumn() const
        {
            return m_column;
        }

    private:
        int m_row;
        int m_column;
    };

    /**
    *  \brief Overloading operator==
    */
    bool operator==(const Cell & lhs, const Cell & rhs);

    /**
    *  \brief Overloading operator<
    */
    bool operator<(const Cell & lhs, const Cell & rhs);
}

#endif //CELL_H