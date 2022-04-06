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
    // current level
    int level;
    // current score
    int score;
    // the number of times that dropping a block without clear any row
    int dropTime;
    // all cells of the board
    std::vector<std::vector<Cell*>> cells;
    // all blocks of the board that isn't cleared totally (all 4 cells) yet
    std::vector<Difficulty*> blocks;
    // a pointer to current block
    Difficulty* curBlock = nullptr;

    // what's the next block
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


    // Blockspin
    void spin(Difficulty* change, bool clock);

    // BlockMove
    bool move(int x, int y, int weight, Difficulty* b);


    
    // Create a new block as needed, it will change status of 4 cells if all of them are blank before
    Difficulty* generateNewBlock(char c, int level);
    

    // check all blocks attached to the board and delete one if all its 4 cells are cleared, as well as add the corresbonding score
    void deleteBlock();


    bool dropMid();

    
    // get the pointer to the cell in (column, row)
    Cell* getCell(int col, int row);

    // used to check if any row need to be cleared when a block is dropped
    bool BlockClear();


    // after a row is cleared, call this helper function to adjust all above rows
    void DropDown(int);

    // called when the opponent clear more than one row at the same time and act the blind
    // it changed the related cells into blind or change it back to normal at the proper time
    void blind();

};

#endif 