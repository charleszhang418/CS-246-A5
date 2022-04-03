#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector> 
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "block.h"

// mutiple ineritance 
class Board : public Observer {
    int width;
    int height;
    int score;
    int level;
    int score;
    std::vector<std::vector<Cell*>> cells;
    std::vector<Block*> blocks;

    public:
    Board(int width, int height, int level, int score = 0); 
    ~Board();

    void initial();

    // Setters
    void setLevel(int level);
    void setScore(int score);

    // Getters
    int getLevel() const;
    int getScore() const;
    char getVal(int col, int row);
    // this method will change the subject, so it triggers
    // notifyobservers 
    bool isover();

    //? Blockspin
    void spin(Block* change, bool clock);

    //? BlockMove
    bool move(int x, int y, int weight, Block* b);

    void clearFull();

    void resetgame();

    Block* generateNewBlock(char c);

    void notify();

    

    Cell* getCell(int col, int row);

    // Blockclear
    int BlockClear();

    void DropDown(int);









   
};

#endif 