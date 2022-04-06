#ifndef __TEXTOUTPUT_H__
#define __TEXTOUTPUT_H__

#include <vector>
#include <iostream>

class Board;

class TextOutput {

    int width, height;
    int hi_score = 0;

    Board *board1;
    Board *board2;
    Board *p_board1;
    Board *p_board2;


  public:
    TextOutput(int width, int height, Board *board1, Board *board2, Board *p_board1, Board *p_board2);
    ~TextOutput();
    int getHeight();
    int getWidth();
    void setHiscore(int hiscore);
    friend std::ostream &operator<<(std::ostream &out, TextOutput &text_out);

};

#endif