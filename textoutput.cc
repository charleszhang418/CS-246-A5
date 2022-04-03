#include "textoutput.h"
#include "board.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

TextOutput::TextOutput(int width, int height, Board *board1, Board *board2) :
    width{width}, height{height}, board1{board1}, board2{board2} {}


int TextOutput::getHeight() {return height;}


int TextOutput::getWidth() {return width;}



ostream &operator<<(ostream &out,  TextOutput &text_out) {
    string slash = "-----------";
    string between = "      ";
    out << "Highest Score: " << "Substitution here" << endl; // Highest score on the first line

    // Print the level and socre for the two board
    out << "Level:" << setw(5) << "N" << between << "Level:" << setw(5) << "N" << endl;
    out << "Score:" << setw(5) << "N" << between << "Score:" << setw(5) << "N" << endl;

    // Slashes
    out << slash << between << slash << endl;
    
    // Game board
    for (int i = 0; i < text_out.getHeight(); ++i) {
        for (int j = 0; j < text_out.getWidth(); ++j) {
            out << text_out.board1->getVal(j,i);
        }
        out << between;
        for (int j = 0; j < text_out.getWidth(); ++j) {
            out << text_out.board2->getVal(j,i);
        }
        out << endl;
    }
    return out;

}

TextOutput::~TextOutput() {}