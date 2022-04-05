#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector> 
#include "cell.h"
#include "block.h"
#include "difficulty.h"

// mutiple ineritance 
class Board {
    int width;
    int height;
    int score;
    int level;
    int dropTime;
    std::vector<std::vector<Cell*>> cells;
    std::vector<Difficulty*> blocks;
    Difficulty* curBlock = nullptr;
    char nextBlock = ' ';

    public:
    Board(int width, int height, int level, int score = 0, int dropTime = 0); 
    ~Board();

    // Setters
    void setLevel(int level);
    void setScore(int score);
    void setDropTime(int dropTime);
    void setCurBlock(Difficulty* diff);
    void setNextBlock(char c);
    void addBlock(Difficulty* diff);

    // Getters
    int getLevel() const;
    int getScore() const;
    char getVal(int col, int row);
    int getDropTime() const;
    Difficulty* getCurBlock() const;
    char getNextBlock() const;


    //? Blockspin
    void spin(Difficulty* change, bool clock);

    //? BlockMove
    bool move(int x, int y, int weight, Difficulty* b);

    void clearFull();

    // void resetgame();

    Difficulty* generateNewBlock(char c, int level);

    void deleteBlock();
    bool dropMid();

    

    Cell* getCell(int col, int row);

    // Blockclear
    bool BlockClear();

    void DropDown(int);

    void blind();

};

#endif 