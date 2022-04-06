#ifndef __BLOCK_H__
#define __BLOCK_H__


#include "cell.h"
#include "difficulty.h"




class Block : public Difficulty {
    protected:
    int type = 0;
    int level;
    int cellCleared = 0;
    Cell* cell1;
    Cell* cell2;
    Cell* cell3;
    Cell* cell4;
    public:
    Block(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);

    //pure virtual delclaration
    virtual char getChar() = 0;
    //pure virtual delclaration
    virtual std::vector<std::vector<int>> rotate(bool clockwise) = 0;
    
    //reset all the field of all four cells this block has
    virtual void clearCellState();
    //pure virtual delclaration
    virtual void updateCellState(Difficulty* diff) = 0;
    // return the value of the field type
    int getType();
    // return the value of the field level
    virtual int getLevel();
    // return the weight of this block
    virtual int getWeight();
    // return the value of the field CellCleared
    virtual int getCellCleared();
    // make the field CellCleared plus one
    virtual void updateCellCleared();
    // update the pointer of the fours cells this block has
    virtual void eraseallcell(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    // pure virtual declaration
    virtual std::vector<std::vector<int>> displayNext() = 0;

    // update the value of erasetype of this block 
    void erasetype(bool);

    // return the coordination of all four cells this block has
    std::vector<std::vector<int>> getalllocation();

    // Determine if all four cells this block has is reduced
    bool checkBlank();

    ~Block();
    
    

};

class IBlock: public Block {
    protected:
    char c = 'I';
    public:
    IBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    // return the value of field c
    char getChar() override;
    // rotate this block, direction is based on the parameter clockwise
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    // update the field value of all four cells this block has
    void updateCellState(Difficulty* diff) override;
    // return the coordination of the next block 
    std::vector<std::vector<int>> displayNext() override;
    ~IBlock();
};

class JBlock: public Block {
    protected:
    char c = 'J';
    public:
    JBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    // return the value of field c
    char getChar() override;
    // rotate this block, direction is based on the parameter clockwise
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    // update the field value of all four cells this block has
    void updateCellState(Difficulty* diff) override;
    // return the coordination of the next block 
    std::vector<std::vector<int>> displayNext() override;
    ~JBlock();
};

class LBlock: public Block {
    protected:
    char c = 'L';
    public:
    LBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    // return the value of field c
    char getChar() override;
    // rotate this block, direction is based on the parameter clockwise
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    // update the field value of all four cells this block has
    void updateCellState(Difficulty* diff) override;
    // return the coordination of the next block 
    std::vector<std::vector<int>> displayNext() override;
    ~LBlock();
};

class OBlock: public Block {
    protected:
    char c = 'O';
    public:
    OBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    // return the value of field c
    char getChar() override;
    // rotate this block, direction is based on the parameter clockwise
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    // update the field value of all four cells this block has
    void updateCellState(Difficulty* diff) override;
    // return the coordination of the next block 
    std::vector<std::vector<int>> displayNext() override;
    ~OBlock();
};

class SBlock: public Block {
    protected:
    char c = 'S';
    public:
    SBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    // return the value of field c
    char getChar() override;
    // rotate this block, direction is based on the parameter clockwise
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    // update the field value of all four cells this block has
    void updateCellState(Difficulty* diff) override;
    // return the coordination of the next block 
    std::vector<std::vector<int>> displayNext() override;
    ~SBlock();
};

class ZBlock: public Block {
    protected:
    char c = 'Z';
    public:
    ZBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    // return the value of field c
    char getChar() override;
    // rotate this block, direction is based on the parameter clockwise
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    // update the field value of all four cells this block has
    void updateCellState(Difficulty* diff) override;
    // return the coordination of the next block 
    std::vector<std::vector<int>> displayNext() override;
    ~ZBlock();
};


class TBlock: public Block {
    protected:
    char c = 'T';
    public:
    TBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    // return the value of field c
    char getChar() override;
    // rotate this block, direction is based on the parameter clockwise
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    // update the field value of all four cells this block has
    void updateCellState(Difficulty* diff) override;
    // return the coordination of the next block 
    std::vector<std::vector<int>> displayNext() override;
    ~TBlock();
    
};




#endif