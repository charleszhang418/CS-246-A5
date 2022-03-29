#include "textoutput.h"
//#include "observer.h"
//#include "cell.h"
//#include "board.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

TextOutput::TextOutput(int width, int height //, Board *board1, Board *board2
    ) :
    width{width}, height{height} //, board1{board1}, board2{board2} 
    {

        for (int i = 0; i < height; ++i) {
            vector<char> row_temp;
            player1.emplace_back(row_temp);
            player2.emplace_back(row_temp);
            for (int j = 0; j < width; ++j) {
                player1[i].emplace_back(' ');
                player2[i].emplace_back(' ');
            }
        }

}

ostream &operator<<(ostream &out,  TextOutput &text_out) {
    string slash = "-----------";
    string between = "      ";
    out << "Highest Score: " << "Substitution here" << endl; // Highest score on the first line

    // Print the level and socre for the two board
    out << "Level:" << setw(5) << "N" << between << "Level:" << setw(5) << "M" << endl;
    out << "Score:" << setw(5) << "N" << between << "Score:" << setw(5) << "M" << endl;

    // Slashes
    out << slash << between << slash << endl;

    // Game board
    for (int i = 0; i < text_out.height; ++i) {
        for (int j = 0; j < text_out.width; ++j) {
            out << text_out.player1[i][j];
        }
        out << between;
        for (int j = 0; j < text_out.width; ++j) {
            out << text_out.player2[i][j];
        }
        out << endl;
    }
    return out;

}

TextOutput::~TextOutput() {}