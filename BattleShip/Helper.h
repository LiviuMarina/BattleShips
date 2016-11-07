#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <array>
#include "Cell.h"
#include <string>
#include <iostream>


namespace helper
{
    /**
    *  \brief Define constants for number board columns and rows.
    */
    const int NO_OF_ROWS = 10;
    const int NO_OF_COLUMNS = 10;

    /**
    *  \brief Define Max int.
    */
    const int MAX_INT = 2147483647;
    
    enum ShipType{
        submarine = 1,
        destroyer,
        cruiser,
        battleship,
        aircraft,
        MAX_TYPE = 6
    };

    enum Orientation
    {
        horizontally,
        vertical
    };

    /**
    *  \brief Convert input string to Cell.
    *  \param[in] inputStr The string that will be converted to cell.
    *  \param[out] resultedCell The resulted cell .
    *  \return True is the inputCell was converted, false otherwise..
    */
    bool StringToCell(std::string inputStr, cell::Cell & resultedCell);
}
#endif //HELPER_FUNCTIONS_H