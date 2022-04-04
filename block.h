#ifndef __BLOCK_H__
#define __BLOCK_H__


#include "cell.h"
#include "difficulty.h"




class Block : public Difficulty {
    protected:
    int type = 0;
    int level;
    Cell* cell1;
    Cell* cell2;
    Cell* cell3;
    Cell* cell4;
    public:
    Block(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    int getlevel();
    virtual char getChar() = 0;
    virtual std::vector<std::vector<int>> rotate(bool clockwise) = 0;
    virtual void clearCellState();
    // virtual void SetCellState(char);
    virtual void updateCellState() = 0;
    int getType();
    //virtual void updateBlockDifficulty(Difficulty* diff);
    virtual int getLevel();
    virtual int getWeight();
    virtual void eraseallcell(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    virtual std::vector<std::vector<int>> displayNext() = 0;
    ~Block();

    void erasetype(bool);

    
    std::vector<std::vector<int>> getalllocation();

    bool checkBlank();

    void notify();
};

class IBlock: public Block {
    protected:
    char c = 'I';
    public:
    IBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4) ;
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    void updateCellState() override;
    std::vector<std::vector<int>> displayNext() override;
    ~IBlock();
};

class JBlock: public Block {
    protected:
    char c = 'J';
    public:
    JBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    void updateCellState() override;
    std::vector<std::vector<int>> displayNext() override;
    ~JBlock();
};

class LBlock: public Block {
    protected:
    char c = 'L';
    public:
    LBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    void updateCellState() override;
    std::vector<std::vector<int>> displayNext() override;
    ~LBlock();
};

class OBlock: public Block {
    protected:
    char c = 'O';
    public:
    OBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    void updateCellState() override;
    std::vector<std::vector<int>> displayNext() override;
    ~OBlock();
};

class SBlock: public Block {
    protected:
    char c = 'S';
    public:
    SBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    void updateCellState() override;
    std::vector<std::vector<int>> displayNext() override;
    ~SBlock();
};

class ZBlock: public Block {
    protected:
    char c = 'Z';
    public:
    ZBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    void updateCellState() override;
    std::vector<std::vector<int>> displayNext() override;
    ~ZBlock();
};

class TBlock: public Block {
    protected:
    char c = 'T';
    public:
    TBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    char getChar() override;
    std::vector<std::vector<int>> rotate(bool clockwise) override;
    void updateCellState() override;
    ~TBlock();
    std::vector<std::vector<int>> displayNext() override;
};




#endif