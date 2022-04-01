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
    virtual void clearCellState();
    virtual void updateCellState() = 0;
    int getType();
    virtual void eraseallcell(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    ~Block();

    void erasetype(bool);

    std::vector<std::vector<int>> getalllocation();
};

class IBlock: public Block {
    protected:
    char c = 'I';
    public:
    IBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4) ;
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    void updateCellState() override;
    ~IBlock();
};

class JBlock: public Block {
    protected:
    char c = 'J';
    public:
    JBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    void updateCellState() override;
    ~JBlock();
};

class LBlock: public Block {
    protected:
    char c = 'L';
    public:
    LBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    void updateCellState() override;
    ~LBlock();
};

class OBlock: public Block {
    protected:
    char c = 'O';
    public:
    OBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    void updateCellState() override;
    ~OBlock();
};

class SBlock: public Block {
    protected:
    char c = 'S';
    public:
    SBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    void updateCellState() override;
    ~SBlock();
};

class ZBlock: public Block {
    protected:
    char c = 'Z';
    public:
    ZBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    void updateCellState() override;
    ~ZBlock();
};

class TBlock: public Block {
    protected:
    char c = 'T';
    public:
    TBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    void updateCellState() override;
    ~TBlock();
};




#endif