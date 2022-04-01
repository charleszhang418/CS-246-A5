#ifndef __DIFFICULTY_H__
#define __DIFFICULTY_H__

#include <iostream>
#include <string>

class Difficulty {
  public:
    // virtual int getWeight() = 0;
    virtual ~Difficulty();
};


class Level: public Difficulty {
    protected:
    Difficulty* diff;
    public:
    Level();
    virtual ~Level();
    virtual int getWeight() = 0;
    // int getWeight() override;
};

class Level0: public Level {
    protected:
    Difficulty* diff;
    public:
    Level0(Difficulty* diff);
    virtual ~Level0();
    int getWeight() override;
};

class Level1: public Level {
    protected:
    Difficulty* diff;
    public:
    Level1(Difficulty* diff);
    virtual ~Level1();
    int getWeight() override;
};

class Level2: public Level {
    protected:
    Difficulty* diff;
    public:
    Level2(Difficulty* diff);
    virtual ~Level2();
    int getWeight() override;
};

class Level3: public Level {
    protected:
    Difficulty* diff;
    public:
    Level3(Difficulty* diff);
    virtual ~Level3();
    int getWeight() override;
};

class Level4: public Level {
    protected:
    Difficulty* diff;
    public:
    Level4(Difficulty* diff);
    virtual ~Level4();
    int getWeight() override;
};

class ActionHeavy: public Level {
    protected:
    Difficulty* diff;
    public:
    ActionHeavy(Difficulty* diff);
    virtual ~ActionHeavy();
    int getWeight() override;
};

#endif