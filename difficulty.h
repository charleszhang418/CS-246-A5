#ifndef __DIFFICULTY_H__
#define __DIFFICULTY_H__
#include "cell.h"
#include <vector>
#include <iostream>
#include <string>

class Difficulty {
  public:
    virtual int getWeight() = 0;
    virtual std::vector<std::vector<int>> getalllocation();
    virtual void clearCellState();
    virtual void eraseallcell(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4);
    virtual void updateCellState();
    virtual std::vector<std::vector<int>> displayNext() = 0;
    virtual ~Difficulty();
};


class Level: public Difficulty {
    protected:
    Difficulty *diff;
    public:
    Level(Difficulty* diff);
    std::vector<std::vector<int>> displayNext();
    virtual ~Level();
    //virtual int getWeight();
    // int getWeight() override;
};

class Level0: public Level {
    public:
    Level0(Difficulty* diff);
    virtual ~Level0();
    int getWeight() override;
};

class Level1: public Level {
    public:
    Level1(Difficulty* diff);
    virtual ~Level1();
    int getWeight() override;
};

class Level2: public Level {
    public:
    Level2(Difficulty* diff);
    virtual ~Level2();
    int getWeight() override;
};

class Level3: public Level {
    public:
    Level3(Difficulty* diff);
    virtual ~Level3();
    int getWeight() override;
};

class Level4: public Level {
    public:
    Level4(Difficulty* diff);
    virtual ~Level4();
    int getWeight() override;
};

class ActionHeavy: public Level {
    public:
    ActionHeavy(Difficulty* diff);
    virtual ~ActionHeavy();
    int getWeight() override;
};

#endif