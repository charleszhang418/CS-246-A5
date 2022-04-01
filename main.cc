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
    
    //? Initialization of variables
    int cur_level = 0;

    bool graphicsMode = true; //? Default: with both graphic output and text output


    //? Command-line interface if exists
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
    
    //? Board Varibles
    Command cmd;
    
    int hi_score = 0;
    int width = 11;
    int height = 18;

    //? Initialize two boards
    Board *b1 = new Board{width, height, cur_level};
    Board *b2 = new Board{width, height, cur_level};

    // Block* currentBlock = b1->generateNewBlock('T');
    //Block* currentBlock = new JBlock(b1->getCell(0, 3), b1->getCell(0, 4), b1->getCell(1, 4), b1->getCell(2, 4));
    
    //b1->spin(currentBlock, true);
    Block* curBlock = b1->generateNewBlock('L');

    //? For textoutput and graphicsoutput
    TextOutput t{11 , 18, b1, b2};
    cout << t;
    // Initialize boards with other setting
    

    //! Game
    while (true) {

        int player = 1;
        bool restart = false;
        // Two players turn
        Board *cur_play = (player == 1) ? b1 : b2;
        // With input

        // Special Action
        string intput;
        string cmdin;

        if (cmdin == "rename") {
            string old, cur;
            cin >> old;
            cin >> cur;
            cmd.short_com(old, cur);
        }

        if (cmdin == "left") {
            // if (cur_play->validMove(-1, 0)) {
            //     cur_play->Move(-1, 0);
            // }
        }

        if (cmdin == "right") {
            // if (cur_play->validMove(1, 0)) {
            //     cur_play->Move(1, 0);
            // }
        }

        if (cmdin == "down") {
            // if (cur_play->validMove(0, 1)) {
            //     cur_play->Move(0, 1);
            // }
        }
        
        if (cmdin == "clockwise") {

        }

        if (cmdin == "counterclockwise") {

        }

        if (cmdin == "drop") {

        }

        if (cmdin == "levelup") {
            
        }

        if (cmdin == "leveldown") {
            
        }

        if (cmdin == "norandom") {
            
        }

        if (cmdin == "random") {
            
        }

        if (cmdin == "sequence") {
            
        }

        //! For Block create with Block name


        if (cmdin == "restart") {
            restart = true;

        }


    }


}
