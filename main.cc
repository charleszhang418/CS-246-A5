#include "command.h"
#include "board.h"
#include "cell.h"
#include "block.h"
#include "difficulty.h"
#include "textoutput.h"


#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int main (int argc, char *argv[]) {
    // Initialization of variables
    Command temp_com;
    int width = 11, height = 18;
    int cur_level = 0;
    int hi_score = 0;

    bool graphicsMode = true; // Default: with both graphic output and text output


    // Command-line interface if exists
    for (int i = 0; i < argc; ++i) {
        string cmd_arg = argv[i];
        if (cmd_arg == "-text") {
            graphicsMode = false;
        } 
        if (cmd_arg == "-seed") {
            // Left to add
        }
        if (cmd_arg == "scriptfile1") {
            // set player1 to file
        } 
        if (cmd_arg == "scriptfile2") {
            // set player2 to file;
        } 
        if (cmd_arg == "-startlevel") {
            string xxx = argv[i + 1];
            cur_level = stoi(xxx);
            i++;
        }

    }

    Board *b1 = new Board{11, 18, 0};
    TextOutput t{11, 18, b1, b1};
    cout << t;
    // Initialize boards with other settings
    // NEED BOARD FULL header file
    
    
    return 1;
    

    // Game
    while (true) {

        bool restart = false;
        // Two players turn
        // With input

        // Special Action

        


    }



}
