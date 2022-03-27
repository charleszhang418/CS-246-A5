#ifndef __CELL_H__
#define __CELL_H__

#include <vector> 
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "block.h"

// mutiple ineritance 
class Board : public Subject, public Observer {
    int width, height; 
    std::vector<std::vector<Cell*>> cells;

    public:
    Board( const int&, const int&); 

    // this method will change the subject, so it triggers
    // notifyobservers 
    bool isover();

    bool isvalid();

    void resetgame();

    bool isRowFull(const int&);

   
};

#endif 