#ifndef CELL_H
#define CELL_H

const int DEC_TO_ASCII = 65;

class Cell
{
public:

    //default constructor
    Cell() {}

    //constructor
    Cell(int row, int column);

    //destructor
    ~Cell() {}    

    //Set the Cell row
    void SetRow(int row)
    {
        m_row = row;
    }
    
    //Get the row were the cell is positioned
    const int GetRow() const
    {
        return m_row;
    }

    //Set the Cell's column
    void SetCol(int column)
    {
        m_column = column;
    }
    
    //Get the column were the cell is positioned
    const int GetColumn() const
    {
        return m_column;
    }

private:
    int m_row;
    int m_column;
};

//Class CellProperties
class CellProperties : public Cell
{
public:

    //Default cosntructor
    CellProperties();

    //Destructor
    ~CellProperties() {}

    //Add a flag that the Cell is into a ship
    void SetShipMembership(bool intoShip)
    {
        m_intoShip = intoShip;
    }

    //Check if the Cell is already into the ship
    const bool GetShipMembership() const
    {
        return m_intoShip;
    }

    //Set a flag that specify that the Cell is hit by opponent
    void SetHitState(bool isHit)
    {
        m_isHit = isHit;
    }

    //Check if the Cell was already hit
    const bool GetHitState() const
    {
        return m_isHit;
    }

private:

    bool m_isHit;
    bool m_intoShip;

};

//Overloadingf operator== 
bool operator==(const Cell & lhs, const Cell & rhs);

#endif //CELL_H