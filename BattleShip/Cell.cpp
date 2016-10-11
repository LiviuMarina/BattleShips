#include "stdafx.h"
#include "Cell.h"

Cell::Cell(int row, int column)
    :m_row(row),
    m_column(column)
{}

CellProperties::CellProperties()
    : m_isHit(false),
    m_intoShip(false)
{}

bool operator==(const Cell & lhs, const Cell & rhs)
{
    return (lhs.GetColumn() == rhs.GetColumn()) && (lhs.GetRow() == rhs.GetRow());
}
