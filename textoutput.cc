#include "textoutput.h"
#include "board.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

TextOutput::TextOutput(int width, int height, Board *board1, Board *board2) :
    width{width}, height{height}, board1{board1}, board2{board2} {}


ostream &operator<<(ostream &out,  TextOutput &text_out) {
    string slash = "-----------";
    string between = "      ";
    out << "Highest Score: " << "Substitution here" << endl; // Highest score on the first line

    // Print the level and socre for the two board
    out << "Level:" << setw(5) << "N" << between << "Level:" << setw(5) << text_out.board1->getScore() << endl;
    out << "Score:" << setw(5) << "N" << between << "Score:" << setw(5) << text_out.board1->getScore() << endl;

    // Slashes
    out << slash << between << slash << endl;

    // Game board
    for (int i = 0; i < text_out.width; ++i) {
        for (int j = 0; j < text_out.height; ++j) {
            out << text_out.board1->getVal(i, j);
        }
        out << between;
        for (int j = 0; j < text_out.height; ++j) {
            out << text_out.board2->getVal(i, j);
        }
        out << endl;
    }
    return out;

}

TextOutput::~TextOutput() {}