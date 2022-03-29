#ifndef _TEXTOUTPUT_H_
#define _TEXTOUTPUT_H_

//#include "observer.h"
//#include "cell.h"

#include <vector>
#include <iostream>

class Board;
class Block;

class TextOutput {
//: public Observer 

    int width, height;
    std::vector<std::vector<char>> player1;
    std::vector<std::vector<char>> player2;

    Board *board1;
    Board *board2;

  public:
    TextOutput(int width, int height);//, Board *board1, Board *board2
    void nextBlock_out(Block *next, int player);
    ~TextOutput();
    friend std::ostream &operator<<(std::ostream &out, TextOutput &text_out);

};

#endif