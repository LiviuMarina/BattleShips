#include "stdafx.h"
#include "Cell.h"
#include "Helper.h"

namespace cell
{
    Cell::Cell()
        :m_row(helper::MAX_INT),
        m_column(helper::MAX_INT)
    {}

    Cell::Cell(int row, int column)
        : m_row(row),
        m_column(column)
    {}

    Cell::~Cell()
    {}

    bool operator==(const Cell & lhs, const Cell & rhs)
    {
        return (lhs.GetColumn() == rhs.GetColumn()) && (lhs.GetRow() == rhs.GetRow());
    }

    bool operator<(const Cell & lhs, const Cell & rhs)
    {
        //return (lhs.GetColumn() < rhs.GetColumn()) && (lhs.GetRow() < rhs.GetRow());
        if (lhs.GetColumn() < rhs.GetColumn()) return true;
        else if ((lhs.GetColumn() == rhs.GetColumn()) && (lhs.GetRow() < rhs.GetRow())) return true;
        else return false;
    }

}
