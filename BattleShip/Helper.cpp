#include "stdafx.h"
#include "Helper.h"

namespace helper
{
    bool StringToCell(std::string inputStr, cell::Cell & resultedCell)
    {
        bool result = false;

        if (inputStr.length() == 2)
        {
            resultedCell.SetRow(inputStr[0] - DEC_TO_ASCII);
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
