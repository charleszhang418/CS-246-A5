#ifndef __CELL_H__
#define __CELL_H__

#include <vector>
#include "difficulty.h"

// mutiple ineritance 
class Cell {
    public:
    int col, row; 
    char value;
    bool iffilled = false;
    Difficulty* block = nullptr;
    bool blind = false;

    public:
    Cell(int, int, char); 

    ~Cell();

    // this method will change the subject, so it triggers
    // notifyobservers 
    void eraseRow(int);
    void eraseCol(int);
    void eraseValue(char);
    void eraseIffilled(bool);
    void eraseBlock(Difficulty* diff);
    void eraseBlind();


    bool getiffilled();
    int getrow();
    int getcol();
    Difficulty* getblock();
    char getvalue();
    std::vector<int> getlocation();
    bool getblind();

    void copy(Cell*);
    void ClearCell();

};

#endif 

