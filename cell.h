#ifndef __CELL_H__
#define __CELL_H__

#include <vector> 
#include "subject.h"
#include "observer.h"
#include "block.h"
#include "difficulty.h"

// mutiple ineritance 
class Cell : public Subject {
    public:
    int col, row; 
    char value;
    bool iffilled = false;
    Difficulty* block = nullptr;

    public:
    Cell(int, int, char); 

    // this method will change the subject, so it triggers
    // notifyobservers 
    void eraseRow(int);
    void eraseCol(int);
    void eraseValue(char);
    void eraseIffilled(bool);
    void eraseBlock(Difficulty* diff);


    bool getiffilled();
    int getrow();
    int getcol();
    Difficulty* getblock();
    char getvalue();
    std::vector<int> getlocation();

    void copy(Cell*);
    void ClearCell();

};

#endif 

