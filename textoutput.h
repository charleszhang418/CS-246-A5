#ifndef _TEXTOUTPUT_H_
#define _TEXTOUTPUT_H_

#include <vector>
#include <iostream>

class Board;

class TextOutput {

    int width, height;

    Board *board1;
    Board *board2;
    Board *p_board1;
    Board *p_board2;


  public:
    TextOutput(int width, int height, Board *board1, Board *board2, Board *p_board1, Board *p_board2);
    ~TextOutput();
    int getHeight();
    int getWidth();
    friend std::ostream &operator<<(std::ostream &out, TextOutput &text_out);

};

#endif