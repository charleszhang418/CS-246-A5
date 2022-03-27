#ifndef __BLOCK_H__
#define __BLOCK_H__


#include "cell.h"




class Block {
    protected:
    int shape;
    Cell* cell1;
    Cell* cell2;
    Cell* cell3;
    Cell* cell4;
    public:
    Block(int shape);
    ~Block();
}

#endif