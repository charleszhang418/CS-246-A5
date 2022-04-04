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
#include <cstdlib>

using namespace std;

char randomBlock(int level) {
    string block;
    if (level == 1) {
        block = {'S', 'Z', 'I', 'I', 'J', 'J', 'L', 'L', 'O', 'O', 'T', 'T'};
        int i = rand() % block.size();
        return block[i];
    } else if (level == 2) {
        block = {'S', 'Z', 'I', 'J', 'L', 'O', 'T'};
        int i = rand() % block.size();
        return block[i];
    } else if (level == 3 || level == 4) {
        block = {'S', 'S', 'Z', 'Z', 'I', 'J', 'L', 'O', 'T'};
        int i = rand() % block.size();
        return block[i];
    }
}

int main (int argc, char *argv[]) {
    
    string p1_level0 = "sequence1.txt";
    string p2_level0 = "sequence2.txt";
    
    //? Board Varibles
    Command cmd;
    
    int hi_score = 0;
    int width = 11;
    int height = 18;
    int player = 0;
    int ini_level = 0;
    
    bool graphicsMode = true; //? Default: with both graphic output and text output


    //? Command-line interface if exists
    for (int i = 1; i < argc; ++i) {
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
                cout << arg << endl;
            }
            
            if (cmd_arg == "-scriptfile1") {
                ifstream fin(arg, ios::in);
                if (!fin) {
                    cout << "Cannot open the scriptfile1: " << arg << endl;
                    return 1;
                }

                p1_level0 = arg;
            } else if (cmd_arg == "-scriptfile2") {
                ifstream fin(arg, ios::in);
                if (!fin) {
                    cout << "Cannot open the scriptfile2: " << arg << endl;
                    return 1;
                }

                p2_level0 = arg;
            } else if (cmd_arg == "-startlevel") {
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
            ++i;
        }
    }
    
    
    //! Questions here need fix!!!
    //? Initialize two boards
    Board *b1 = new Board{width, height, ini_level};
    Board *b2 = new Board{width, height, ini_level};
    Board *pb1 = new Board{width, height, 0};
    Board *pb2 = new Board{width, height, 0};
    TextOutput t{11 , 18, b1, b2, pb1, pb2};
    
    // b1->dropMid();
    // b1->dropMid();
    // b1->dropMid();

    // b1->spin(curBlock1, false);
    // b1->spin(curBlock1, false);
    // b1->spin(curBlock1, false);
    // b1->spin(curBlock1, true);./a    
    // Block* currentBlock = new JBlock(b1->getCell(0, 3), b1->getCell(0, 4), b1->getCell(1, 4), b1->getCell(2, 4));
    
    // b1->move(-1, 0, 2, curBlock1);

    //? For textoutput and graphicsoutput
    
    
    // Initialize boards with other setting
    
    
    // cout << curBlock2->displayNext()[0][0] << endl;
    // cout << curBlock2->displayNext()[0][1] << endl;
    // cout << curBlock2->displayNext()[1][0] << endl;
    // cout << curBlock2->displayNext()[1][1] << endl;
    // cout << curBlock2->displayNext()[2][0] << endl;
    // cout << curBlock2->displayNext()[2][1] << endl;
    // cout << curBlock2->displayNext()[3][0] << endl;
    // cout << curBlock2->displayNext()[3][1] << endl;    

    string cmdin;

    //? Temp input
    string b1_seq = {'L', 'O', 'I', 'L', 'O', 'L', 'O', 'L', 'O'};

    int p1_count = 1;
    int p2_count = 1;

    string p1_seq;
    string p2_seq;
    int temp = 0;
    char tmp;
    ifstream fin1(p1_level0);
    while (fin1 >> tmp) {
        p1_seq[temp++] = tmp;
    }
    temp = 0;
    ifstream fin2(p2_level0);
    while (fin2 >> tmp) {
        p2_seq[temp++] = tmp;
    }

    char cur_B1;
    char cur_B2;
    char nxt_B1;
    char nxt_B2;
    char p_B1;
    char p_B2;


    if (ini_level == 0) {
        cur_B1 = p1_seq[0];
        nxt_B1 = p1_seq[1];

        cur_B2 = p2_seq[0];
        nxt_B2 = p2_seq[1];
    } else if (ini_level >= 1 && ini_level <= 4) {
        cur_B1 = randomBlock(ini_level);
        nxt_B1 = randomBlock(ini_level);

        cur_B2 = randomBlock(ini_level);
        nxt_B2 = randomBlock(ini_level);
    }
    
    Difficulty *curBlock1 = b1->generateNewBlock(cur_B1, ini_level);
    Difficulty *curBlock2 = b2->generateNewBlock(cur_B2, ini_level);
    Difficulty *p_Block1 = pb1->generateNewBlock(nxt_B1, ini_level);
    Difficulty *p_Block2 = pb2->generateNewBlock(nxt_B2, ini_level);

    //! Game
    while (true) {

        bool restart = false;
        if (player != 0) {
            if ((player % 2) != 0) {
                p1_count += 1;
                cur_B1 = b1_seq[p1_count];
                cout << cur_B1 << endl;
                curBlock1 = b1->generateNewBlock(cur_B1, 0);
                
            } else {
                p2_count += 1;
                cur_B2 = b1_seq[p2_count];
                cout << cur_B2 << endl;
                curBlock2 = b2->generateNewBlock(cur_B2, 0);
            }
        }

        if (player != 0) {
            if ((player % 2) != 0) {
                cur_B1 = nxt_B1;
                curBlock1 = b1->generateNewBlock(cur_B1, b1->getLevel());
                if (b1->getLevel() == 0) {
                    p1_count += 1;
                    nxt_B1 = p1_seq[p1_count];
                } else if (b1->getLevel() >= 1 && b1->getLevel() <= 4) {
                    nxt_B1 = randomBlock(b1->getLevel());
                }
                p_Block1->clearCellState();
                p_Block1 = pb1->generateNewBlock(nxt_B1, b1->getLevel());
                
            } else {
                cur_B2 = nxt_B2;
                curBlock2 = b2->generateNewBlock(cur_B2, b2->getLevel());
                if (b2->getLevel() == 0) {
                    p2_count += 1;
                    nxt_B2 = p2_seq[p2_count];
                } else if (b2->getLevel() >= 1 && b2->getLevel() <= 4) {
                    nxt_B2 = randomBlock(b2->getLevel());
                }
                p_Block2->clearCellState();
                p_Block2 = pb2->generateNewBlock(nxt_B2, b2->getLevel());
            }
        }

        player += 1;
        cout << t;
        
        // Two players turn
        Board *cur_play = ((player % 2) != 0) ? b1 : b2;
        Difficulty *curBlock = ((player % 2) != 0) ? curBlock1 : curBlock2;
        // With input

        // Special Action
        string intput;

        //! For player turn
        while (cin >> cmdin) {

            bool touch = true;

            if (cmdin == "rename") {
                string old, cur;
                cin >> old;
                cin >> cur;
                cmd.short_com(old, cur);
                cout << t;
                continue;
            }

            if (cmdin == "left") {
                if (touch) {
                    touch = cur_play->move(-1, 0, curBlock->getWeight(), curBlock);
                }
            }

            if (cmdin == "right") {
                if (touch) {
                    touch = cur_play->move(1, 0, curBlock->getWeight(), curBlock);
                }
            }

            if (cmdin == "down") {
                if (touch) {
                    touch = cur_play->move(0, 1, curBlock->getWeight(), curBlock);
                }
            }
            
            if (cmdin == "clockwise") {
                if (touch) {
                    cur_play->spin(curBlock, true);
                }
            }

            if (cmdin == "counterclockwise") {
                if (touch) {
                    cur_play->spin(curBlock, true);
                }
            }

            if (cmdin == "drop") {
                while (touch) {
                    touch = cur_play->move(0, 1, curBlock->getWeight(), curBlock);
                }
                cur_play->BlockClear();

                //! Clear lines
                cout << t; 
                break;
            }

            if (cmdin == "levelup") {
                int cur_level = cur_play->getLevel();
                if (cur_level < 4) {
                    cur_level += 1;
                }
                cur_play->setLevel(cur_level);
                cout << t;
            }

            if (cmdin == "leveldown") { 
                int cur_level = cur_play->getLevel();
                if (cur_level > 0) {
                    cur_level -= 1;
                }
                cur_play->setLevel(cur_level);
                cout << t;
            }

            if (cmdin == "norandom") {
                cout << "Not yet developed" << endl;
            }

            if (cmdin == "random") {
                cout << "Not yet developed" << endl;
            }

            if (cmdin == "sequence") {
                cout << "Not yet developed" << endl;
            }

            //! For Block create with Block name
            if (cmdin.length() == 1) {
                Difficulty *newBlock;
                int cur_level = cur_play->getLevel();

                if (cmdin == "I") {
                    curBlock->clearCellState();
                    cur_play->generateNewBlock('I', cur_level);
                } else if (cmdin == "J") {
                    curBlock->clearCellState();
                    cur_play->generateNewBlock('J', cur_level);
                } else if (cmdin == "L") {
                    curBlock->clearCellState();
                    cur_play->generateNewBlock('L', cur_level);
                } else if (cmdin == "O") {
                    curBlock->clearCellState();
                    cur_play->generateNewBlock('O', cur_level);
                } else if (cmdin == "S") {
                    curBlock->clearCellState();
                    cur_play->generateNewBlock('S', cur_level);
                } else if (cmdin == "Z") {
                    curBlock->clearCellState();
                    cur_play->generateNewBlock('Z', cur_level);
                } else if (cmdin == "T") {
                    curBlock->clearCellState();
                    cur_play->generateNewBlock('T', cur_level);
                } else {
                    continue;
                }

                cout << t;
                continue;

            }


            if (cmdin == "restart") {
                
                restart = true;
                //! Need to clear the borads

            }
            cout << t;
        }

        int p1_score = b1->getScore();
        int p2_score = b2->getScore();
        
        hi_score = (p1_score > hi_score || p2_score > hi_score) ? (p1_score > p2_score ? p1_score : p2_score) : hi_score;

        if (restart) {continue;}

        //! Spcecial Actions



    }


}
