#ifndef __difficulty_H__
#define __difficulty_H__

#include <iostream>
#include <string>

class Difficulty {
  public:
    virtual std::string getblock() = 0;
    virtual ~Difficulty();
};


class Level: public Difficulty {
    protected:
    Difficulty* diff;
    public:
    Level(Difficulty* diff);
    virtual ~Level();
    std::string getblock() override;
};


class Level: public Difficulty {
    protected:
    Difficulty* diff;
    public:
    Level(Difficulty* diff);
    virtual ~Level();
    std::string getblock() override;
};

class Level0: public Level {
    protected:
    Difficulty* diff;
    public:
    Level0(Difficulty* diff);
    virtual ~Level0();
    std::string getblock() override;
};

class Level1: public Level {
    protected:
    Difficulty* core;
    public:
    Level1(Difficulty* diff);
    virtual ~Level1();
    std::string getblock() override;
};

class Level2: public Level {
    protected:
    Difficulty* diff;
    public:
    Level2(Difficulty* diff);
    virtual ~Level2();
    std::string getblock() override;
};

class Level3: public Level {
    protected:
    Difficulty* diff;
    public:
    Level3(Difficulty* diff);
    virtual ~Level3();
    std::string getblock() override;
};

class Level4: public Level {
    protected:
    Difficulty* diff;
    public:
    Level4(Difficulty* diff);
    virtual ~Level4();
    std::string getblock() override;
};

class ActionHeavy: public Level {
    protected:
    Difficulty* diff;
    public:
    ActionHeavy(Difficulty* diff);
    virtual ~ActionHeavy();
    std::string getblock() override;
};

#endif