#ifndef __DIFFICULTY_H__
#define __DIFFICULTY_H__

#include <vector>
#include <iostream>
#include <string>
// #include "cell.h"

class Cell;

class Cell;

class Difficulty  {
  public:

  // pure virtual declaration

    virtual int getWeight() = 0;
    virtual std::vector<std::vector<int>> getalllocation() = 0;
    virtual void clearCellState() = 0;
    virtual void eraseallcell(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4) = 0;
    virtual void updateCellState(Difficulty* diff) = 0;
    virtual std::vector<std::vector<int>> displayNext() = 0;
    virtual std::vector<std::vector<int>> rotate(bool clockwise) = 0;
    virtual char getChar() = 0;
    virtual void erasetype(bool clock) = 0;
    virtual ~Difficulty();
    virtual bool checkBlank() = 0;
    virtual int getLevel() = 0;
    virtual void updateCellCleared() = 0;

};


class Level: public Difficulty {
    protected:
    Difficulty *diff;
    public:
    Level(Difficulty* diff);
    //return the coordination of all four cells this block has
    virtual std::vector<std::vector<int>> getalllocation();
    //reset all the field of all four cells this block has
    virtual void clearCellState();
    // update the pointer of the fours cells this block has
    virtual void eraseallcell(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    // update the field value of all four cells this block has
    virtual void updateCellState(Difficulty* diff);
    // return the coordination of the next block 
    virtual std::vector<std::vector<int>> displayNext();
    // rotate this block, direction is based on the parameter clockwise
    virtual std::vector<std::vector<int>> rotate(bool clockwise);
    // return the value of field c
    virtual char getChar();
    // update the value of erasetype of this block 
    virtual void erasetype(bool clock);
    // determine if all four cells of this block is reduced
    virtual bool checkBlank();
    // return the value of field level
    virtual int getLevel();
    // make the field CellCleared plus one
    virtual void updateCellCleared();
    ~Level();
};

class Level0: public Level {
    public:
    Level0(Difficulty* diff);
    ~Level0();
    // return the weight of this block
    int getWeight() override;
};

class Level1: public Level {
    public:
    Level1(Difficulty* diff);
    ~Level1();
    // return the weight of this block
    int getWeight() override;
};

class Level2: public Level {
    public:
    Level2(Difficulty* diff);
    ~Level2();
    // return the weight of this block
    int getWeight() override;
};

class Level3: public Level {
    public:
    Level3(Difficulty* diff);
    ~Level3();
    // return the weight of this block
    int getWeight() override;
};

class Level4: public Level {
    public:
    Level4(Difficulty* diff);
    ~Level4();
    // return the weight of this block
    int getWeight() override;
};

class ActionHeavy: public Level {
    public:
    ActionHeavy(Difficulty* diff);
    ~ActionHeavy();
    // return the weight of this block
    int getWeight() override;
};

#endif