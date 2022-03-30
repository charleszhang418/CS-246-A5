#ifndef __CELL_H__
#define __CELL_H__

#include <vector> 
#include "subject.h"
#include "observer.h"

// mutiple ineritance 
class Cell : public Subject, public Observer {
    int col, row; 
    char value;
    bool iffilled = false;

    public:
    Cell(int, int, char = ' '); 

    // this method will change the subject, so it triggers
    // notifyobservers 
    void eraseRow(int);
    void eraseCol(int);
    void eraseValue(char);
    void eraseIffilled(bool);


    bool getiffilled();
    int getrow();
    int getcol();
    char getvalue();

    void notify() override; 
};

#endif 

