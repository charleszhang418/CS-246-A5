#ifndef __BLOCK_H__
#define __BLOCK_H__


#include "cell.h"




class Block {
    protected:
    int type = 0;
    Cell* cell1;
    Cell* cell2;
    Cell* cell3;
    Cell* cell4;
    public:
    Block(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    virtual char getChar() = 0;
    virtual std::vector<std::vector<int>> rotate(bool clockwise) = 0;
    int getType();
    ~Block();

    void erasetype(bool);

//    void eraseallcell(cell*, cell*, cell*, cell*);

// vector<vector<int>> getalllocation();
};

class IBlock: Block {
    protected:
    char c = 'I';
    public:
    IBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4) ;
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    ~IBlock();
};

class JBlock: Block {
    protected:
    char c = 'J';
    public:
    JBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    ~JBlock();
};

class LBlock: Block {
    protected:
    char c = 'L';
    public:
    LBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    ~LBlock();
};

class OBlock: Block {
    protected:
    char c = 'O';
    public:
    OBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    ~OBlock();
};

class SBlock: Block {
    protected:
    char c = 'S';
    public:
    SBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    ~SBlock();
};

class ZBlock: Block {
    protected:
    char c = 'Z';
    public:
    ZBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    ~ZBlock();
};

class TBlock: Block {
    protected:
    char c = 'T';
    public:
    TBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    ~TBlock();
};




#endif