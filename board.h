#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector> 
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "block.h"

// mutiple ineritance 
class Board : public Subject, public Observer {
    int width;
    int height;
    int score;
    int level;
    std::vector<std::vector<Cell*>> cells;

    public:
    Board(int width, int height, int level); 
    ~Board();

    void initial();

    // Setters
    void setLevel(int level);
    void setScore(int score);

    // Getters
    int getLevel() const;
    int getScore() const;
    char getVal(int col, int row) const;
    // this method will change the subject, so it triggers
    // notifyobservers 
    bool isover();

    bool isvalid();

    void resetgame();

    bool isRowFull(const int&);



    // Block* spin(Block*);






   
};

#endif 