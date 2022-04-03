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
#include <fstream>

using namespace std;

int main (int argc, char *argv[]) {
    
    string p1_level0 = "sequence1.txt";
    string p2_level0 = "sequence2.txt";
    
    //? Board Varibles
    Command cmd;
    
    int hi_score = 0;
    int width = 11;
    int height = 18;
    int player = 1;
    int ini_level = 0;
    

    bool graphicsMode = true; //? Default: with both graphic output and text output


    //? Command-line interface if exists
    for (int i = 0; i < argc; ++i) {
        string cmd_arg = argv[i];
        if (cmd_arg == "-text") {
            graphicsMode = false;
        } else {
            if (cmd_arg != "-seed" && cmd_arg != "-scriptfile1" && cmd_arg != "-scriptfile2" && cmd_arg != "-startlevel") {
                cout << "Unknown command line argument: " << cmd_arg << endl;
                return 1;
            }
            string arg = argv[i + 1];
            
            if (cmd_arg == "-seed") {
                continue;
            }
            
            if (cmd_arg == "scriptfile1") {
                ifstream fin(arg, ios::in);
                if (!fin) {
                    cout << "Cannot open the scriptfile1: " << arg;
                    return 1;
                }

                p1_level0 = arg;
            } 

            if (cmd_arg == "scriptfile2") {
                ifstream fin(arg, ios::in);
                if (!fin) {
                    cout << "Cannot open the scriptfile2: " << arg;
                    return 1;
                }

                p2_level0 = arg;
            }

            if (cmd_arg == "-startlevel") {
                try {
                    ini_level = stoi(arg);
                } catch(...) {
                    cout << "Please enter an integer after startlevel" << endl;
                    return 1;
                }

                if (ini_level > 4) {
                    ini_level = 4;
                }

                if (ini_level < 0) {
                    ini_level = 0;
                }
            }
        }
    }
    
    
    //! Questions here need fix!!!
    //? Initialize two boards
    Board *b1 = new Board{width, height, ini_level};
    Board *b2 = new Board{width, height, ini_level};
    TextOutput t{11 , 18, b1, b2};


    Difficulty *curBlock1 = b1->generateNewBlock('L', 4);
    Difficulty *curBlock2 = b2->generateNewBlock('L', 2);
    // Block* currentBlock = new JBlock(b1->getCell(0, 3), b1->getCell(0, 4), b1->getCell(1, 4), b1->getCell(2, 4));
    
    //b1->spin(currentBlock, true);

    //b1->move(-1, 0, 2, curBlock1);

    //? For textoutput and graphicsoutput
    
    cout << t;
    // Initialize boards with other setting

    cout << curBlock1->getWeight() << endl;
    cout << curBlock2->getWeight() << endl;
    
    
    // cout << curBlock2->displayNext()[0][0] << endl;
    // cout << curBlock2->displayNext()[0][1] << endl;
    // cout << curBlock2->displayNext()[1][0] << endl;
    // cout << curBlock2->displayNext()[1][1] << endl;
    // cout << curBlock2->displayNext()[2][0] << endl;
    // cout << curBlock2->displayNext()[2][1] << endl;
    // cout << curBlock2->displayNext()[3][0] << endl;
    // cout << curBlock2->displayNext()[3][1] << endl;    
    
    string cmdin;
    //! Game
    while (cin >> cmdin) {

        bool restart = false;
        bool touch = false;
        // Two players turn
        Board *cur_play = (player == 1) ? b1 : b2;
        Difficulty *curBlock = (player == 1) ? curBlock1 : curBlock2;
        // With input

        // Special Action
        string intput;

        

        if (cmdin == "rename") {
            string old, cur;
            cin >> old;
            cin >> cur;
            cmd.short_com(old, cur);
        }

        if (cmdin == "left") {
            if (!touch) {
                touch = cur_play->move(-1, 0, curBlock->getWeight(), curBlock1);
            }
        }

        if (cmdin == "right") {
            if (!touch) {
                touch = cur_play->move(1, 0, curBlock->getWeight(), curBlock1);
            }
        }

        if (cmdin == "down") {
            if (!touch) {
                touch = cur_play->move(0, 1, curBlock->getWeight(), curBlock);
            }
        }
        
        if (cmdin == "clockwise") {
            if (!touch) {
                cur_play->spin(curBlock, true);
            }
        }

        if (cmdin == "counterclockwise") {
            if (!touch) {
                cur_play->spin(curBlock, true);
            }
        }

        if (cmdin == "drop") {
            while (!touch) {
                touch = cur_play->move(0, 1, curBlock->getWeight(), curBlock);
            }

            //! Clear lines 
        }

        if (cmdin == "levelup") {
            // int cur_level = cur_play->getLevel();
            // if (cur_level < 4) {
            //     cur_level += 1;
            // }
            // cur_play->setLevel(cur_level);
        }

        if (cmdin == "leveldown") { 
            // int cur_level = cur_play->getLevel();
            // if (cur_level > 0) {
            //     cur_level -= 1;
            // }
            // cur_play->setLevel(cur_level);
            // cout << t;
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
