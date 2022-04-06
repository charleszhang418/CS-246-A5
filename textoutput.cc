#include "textoutput.h"
#include "board.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


TextOutput::TextOutput(int width, int height, Board *board1, Board *board2, Board *p_board1, Board *p_board2) :
    width{width}, height{height}, board1{board1}, board2{board2}, p_board1{p_board1}, p_board2{p_board2} {}


int TextOutput::getHeight() {return height;}


int TextOutput::getWidth() {return width;}


void TextOutput::setHiscore(int hiscore) {
    this->hi_score = hiscore;
}


ostream &operator<<(ostream &out,  TextOutput &text_out) {
    string slash = "-----------";
    string between = "      ";
    out << "Highest Score: " << text_out.hi_score << endl; // Highest score on the first line

    // Print the level and socre for the two board
    out << "Level:" << setw(5) << text_out.board1->getLevel() << between << "Level:" << setw(5) << text_out.board2->getLevel() << endl;
    out << "Score:" << setw(5) << text_out.board1->getScore() << between << "Score:" << setw(5) << text_out.board2->getScore() << endl;

    // Slashes
    out << slash << between << slash << endl;
    
    // Game board
    for (int i = 0; i < text_out.getHeight(); ++i) {
        for (int j = 0; j < text_out.getWidth(); ++j) {
            if (text_out.board1->getCell(j, i)->getblind()) {
                out << '?';
            } else {
                out << text_out.board1->getVal(i,j);
            }
        }
        out << between;
        for (int j = 0; j < text_out.getWidth(); ++j) {
            if (text_out.board2->getCell(j, i)->getblind()) {
                out << '?';
            } else {
                out << text_out.board2->getVal(i,j);
            }
        }
        out << endl;
    }

    out << slash << between << slash << endl;
    out << "Next:" << between << between << "Next:" << between << endl;

    // Preview board
    for (int i = 2; i < 4; ++i) {
        for (int j = 0; j < text_out.getWidth(); ++j) {
            out << text_out.p_board1->getVal(i, j);
        }
        out << between;
        for (int j = 0; j < text_out.getWidth(); ++j) {
            out << text_out.p_board2->getVal(i, j);
        }
        out << endl;
    }
    
    out << slash << between << slash << endl;
    

    return out;

}

TextOutput::~TextOutput() {}