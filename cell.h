#ifndef __CELL_H__
#define __CELL_H__

#include <vector>
#include "difficulty.h"

// mutiple ineritance 
class Cell {
    public:
    int col, row; 
    // the type of the cell, if it is blank currently, it is " "
    char value;
    // whether the cell is occupied
    bool iffilled = false;
    // the corresbonding block if it is occupied
    Difficulty* block = nullptr;
    // whether is is blind due to the action implemented by the opponent
    bool blind = false;

    public:
    Cell(int, int, char); 

    ~Cell();

    // these methods allows client to change the value of field of the object in the type Cell
    void eraseRow(int);
    void eraseCol(int);
    void eraseValue(char);
    void eraseIffilled(bool);
    void eraseBlock(Difficulty* diff);
    void eraseBlind();

    // these methods allows client to get the value of field of the object in the type Cell
    bool getiffilled();
    int getrow();
    int getcol();
    Difficulty* getblock();
    char getvalue();
    std::vector<int> getlocation();
    bool getblind();

    // erase all status of a cell to exactly the same as the target cell
    void copy(Cell*);

    // clean the cell status to unoccupied
    void ClearCell();

};

#endif 

