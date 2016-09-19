#include "stdafx.h"
#include "Cell.h"

Cell::Cell(char row, int column)
    :m_row(row),
    m_column(column)
{}

CellProperties::CellProperties()
    : m_isHit(false),
    m_intoShip(false)
{}
