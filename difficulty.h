#ifndef __DIFFICULTY_H__
#define __DIFFICULTY_H__

#include <iostream>
#include "block.h"
#include <string>

class Difficulty {
  public:
    virtual std::string getblock(Block* block) = 0;
    virtual ~Difficulty();
};


class Level: public Difficulty {
    protected:
    Difficulty* diff;
    public:
    Level(Difficulty* diff);
    virtual ~Level();
    Block* block getweight(Block* block) override;
};

class Level0: public Level {
    protected:
    Difficulty* diff;
    public:
    Level0(Difficulty* diff);
    virtual ~Level0();
    Block* block getweight(Block* block) override;
};

class Level1: public Level {
    protected:
    Difficulty* core;
    public:
    Level1(Difficulty* diff);
    virtual ~Level1();
    Block* block getweight(Block* block) override;
};

class Level2: public Level {
    protected:
    Difficulty* diff;
    public:
    Level2(Difficulty* diff);
    virtual ~Level2();
    Block* block getweight(Block* block) override;
};

class Level3: public Level {
    protected:
    Difficulty* diff;
    public:
    Level3(Difficulty* diff);
    virtual ~Level3();
    Block* block getweight(Block* block) override;
};

class Level4: public Level {
    protected:
    Difficulty* diff;
    public:
    Level4(Difficulty* diff);
    virtual ~Level4();
    Block* block getblock(Block* block) override;
};

class ActionHeavy: public Level {
    protected:
    Difficulty* diff;
    public:
    ActionHeavy(Difficulty* diff);
    virtual ~ActionHeavy();
    Block* block getblock(Block* block) override;
};

#endif