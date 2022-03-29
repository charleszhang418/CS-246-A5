#ifndef __CELL_H__
#define __CELL_H__

#include <vector> 
#include "subject.h"
#include "observer.h"

// mutiple ineritance 
class Cell : public Subject, public Observer {
    int row, col; 
    bool iffilled = false;

    public:
    Cell(int, int); 

    // this method will change the subject, so it triggers
    // notifyobservers 
    void eraseVal();

    std::vector<int> getState() const;

    void notify() override; 
};

#endif 

