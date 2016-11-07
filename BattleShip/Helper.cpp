#include "stdafx.h"
#include "Helper.h"

namespace helper
{
    bool StringToCell(std::string inputStr, cell::Cell & resultedCell)
    {
        bool result = false;

        if (inputStr.length() == 2)
        {
            int rowValue = inputStr[0] - DEC_TO_ASCII;
            if (rowValue >= NO_OF_ROWS || rowValue < 0)
            {
                std::cout << "Wrong Cell format" << std::endl;
                return result;
            }

            resultedCell.SetRow(rowValue);
            resultedCell.SetCol(int(inputStr[1]) - 48);
            result = true;
        }
        else
        {
            std::cout << "Wrong Cell format" << std::endl;
        }

        return result;
    }
}
