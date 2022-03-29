#ifndef __BLOCK_H__
#define __BLOCK_H__


#include "cell.h"




class Block {
    protected:
    Cell* cell1;
    Cell* cell2;
    Cell* cell3;
    Cell* cell4;
    public:
    Block(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    ~Block();
};

class IBlock: Block {
    protected:
    char c = 'I';
    public:
    IBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    ~IBlock();
};

class JBlock: Block {
    protected:
    char c = 'J';
    public:
    JBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    ~JBlock();
};

class LBlock: Block {
    protected:
    char c = 'L';
    public:
    LBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    ~LBlock();
};

class OBlock: Block {
    protected:
    char c = 'O';
    public:
    OBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    ~OBlock();
};

class SBlock: Block {
    protected:
    char c = 'S';
    public:
    SBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    ~SBlock();
};

class ZBlock: Block {
    protected:
    char c = 'Z';
    public:
    ZBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    ~ZBlock();
};

class TBlock: Block {
    protected:
    char c = 'T';
    public:
    TBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    ~TBlock();
};


#endif