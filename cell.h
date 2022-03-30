#ifndef __CELL_H__
#define __CELL_H__

#include <vector> 
#include "subject.h"
#include "observer.h"

// mutiple ineritance 
class Cell : public Subject, public Observer {
    int row, col; 
    char value = 'n';
    bool iffilled = false;

    public:
    Cell(int, int); 

    // this method will change the subject, so it triggers
    // notifyobservers 
    void eraseVal();

    bool getiffilled();
    int getrow();
    int getcol();
    char getvalue();

    void notify() override; 
};

#endif 

