#ifndef __CELL_H__
#define __CELL_H__

#include <vector> 
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "block.h"

// mutiple ineritance 
class Board : public Subject, public Observer {
    int level;
    int width = 11;
    int height = 15; 
    std::vector<std::vector<Cell*>> cells;
    int mark = 0;

    public:
    Board( const int&, const int&, const int&); 

    // this method will change the subject, so it triggers
    // notifyobservers 
    bool isover();

    bool operationvalid();

    void resetgame();

    bool isRowFull(const int&);

    void setvalue(const int&);

    int getvalue();

    int getmark();


   
};

#endif 