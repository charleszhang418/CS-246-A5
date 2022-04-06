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
    } else {
        block = {'S', 'S', 'Z', 'Z', 'I', 'J', 'L', 'O', 'T'};
        int i = rand() % block.size();
        return block[i];
    }
}

int main (int argc, char *argv[]) {
    
    string p1_level0 = "sequence1.txt";
    string p2_level0 = "sequence2.txt";
    
    
    Command cmd;
    // Board Varibles
    int hi_score = 0;
    int width = 11;
    int height = 18;
    int player = 0;
    int ini_level = 0;
    srand(time(NULL));
    
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
                srand(stoi(arg));
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
    
    
    //? Initialize two boards
    Board *b1 = new Board{width, height, ini_level};
    Board *b2 = new Board{width, height, ini_level};
    Board *pb1 = new Board{width, height, 0};
    Board *pb2 = new Board{width, height, 0};
    // Xwindow * win = new Xwindow();
    TextOutput t{11 , 18, b1, b2, pb1, pb2};
    
    

    string cmdin;

    int p1_count = 1;
    int p2_count = 1;
    int drop = 0;


    string p1_seq;
    string p2_seq;
    int temp_1 = 0;
    int temp_2 = 0;
    char tmp;
    ifstream fin1(p1_level0);
    while (fin1 >> tmp) {
        p1_seq[temp_1++] = tmp;
    }
    ifstream fin2(p2_level0);
    while (fin2 >> tmp) {
        p2_seq[temp_2++] = tmp;
    }

    char cur_B1;
    char cur_B2;
    char nxt_B1;
    char nxt_B2;

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
    b1->setCurBlock(curBlock1);
    b2->setCurBlock(curBlock2);
    b1->setNextBlock(nxt_B1);
    b2->setNextBlock(nxt_B2);
    
    Difficulty *p_Block1 = pb1->generateNewBlock(nxt_B1, ini_level);
    Difficulty *p_Block2 = pb2->generateNewBlock(nxt_B2, ini_level);

    string special_action;
    bool blind = false;
    bool heavy = false;
    char force;
    bool force_block = false;
    bool rowCleared = false;
    

    //! Game
    while (true) {

        // bool restart = false;

        if (rowCleared) {
            cout << t;
            cout << "You can choose one special action!" << endl;
            cin >> special_action;
            if (special_action == "blind") {
                cout << "Your opponent will be blinded next turn!" << endl;
                blind = true;
                
            } else if (special_action == "heavy") {
                cout << "Your opponent's board will be heavier next turne!" << endl;
                heavy = true;
            } else if (special_action == "force") {
                cout << "Choose one block for your opponent's next turn" << endl;
                force_block = true;
                cin >> force;
            }
        }

        if (player != 0) {
            if ((player % 2) != 0) {
                if (force_block) {
                    curBlock2->clearCellState();
                    // delete curBlock2;
                    cur_B2 = force;
                    force_block = false;
                    curBlock2 = b2->generateNewBlock(cur_B2, b2->getLevel());
                }
                cur_B1 = nxt_B1;
                curBlock1 = b1->generateNewBlock(cur_B1, b1->getLevel());
                if (b1->getLevel() == 0) {
                    p1_count += 1;
                    if (p1_count >= temp_1) {
                        nxt_B1 = ' ';
                    } else {
                        nxt_B1 = p1_seq[p1_count];
                    }
                } else if (b1->getLevel() >= 1 && b1->getLevel() <= 4) {
                    nxt_B1 = randomBlock(b1->getLevel());
                }
                p_Block1->clearCellState();
                if (nxt_B1 != ' ') {
                    p_Block1 = pb1->generateNewBlock(nxt_B1, b1->getLevel());
                }
                
            } else {
                if (force_block) {
                    curBlock1->clearCellState();
                    // delete curBlock1;
                    cur_B1 = force;
                    force_block = false;
                    curBlock1 = b1->generateNewBlock(cur_B1, b1->getLevel());
                }
                cur_B2 = nxt_B2;
                curBlock2 = b2->generateNewBlock(cur_B2, b2->getLevel());
                if (b2->getLevel() == 0) {
                    p2_count += 1;
                    if (p2_count >= temp_2) {
                        nxt_B2 = ' ';
                    } else {
                        nxt_B2 = p2_seq[p2_count];
                    }
                } else if (b2->getLevel() >= 1 && b2->getLevel() <= 4) {
                    nxt_B2 = randomBlock(b2->getLevel());
                }
                p_Block2->clearCellState();
                if (nxt_B2 != ' ') {
                    p_Block2 = pb2->generateNewBlock(nxt_B2, b2->getLevel());
                }
            } 
        } 

        if (curBlock1 == nullptr || curBlock2 == nullptr) {
            if (b1->getScore() > b2->getScore()) {
                cout << "Player1 wins!" << endl;
            } else if (b1->getScore() > b2->getScore()) {
                cout << "Player2 wins!" << endl;
            } else {
                cout << "DRAW!!!" << endl;
            }
            // delete b1;
            // delete b2;
            // delete pb1;
            // delete pb2;
            return 0;
        }

        b1->setCurBlock(curBlock1);
        b2->setCurBlock(curBlock2);
        b1->setNextBlock(nxt_B1);
        b2->setNextBlock(nxt_B2);

        

        player += 1;
        
        
        // Two players turn
        Board *cur_play = ((player % 2) != 0) ? b1 : b2;
        Difficulty *curBlock = ((player % 2) != 0) ? curBlock1 : curBlock2;
        // With input
        // Special Action
        if (blind) {
            cur_play->blind();
        }
        
        cout << t;

        string input;
        bool touch = true;

        //! For player turn
        while (cin >> input) {

            
            if (drop != 0) {
                while (touch) {
                    touch = cur_play->move(0, 1, curBlock->getWeight(), curBlock);
                }
                cur_play->BlockClear();

                //! Clear lines
                cout << t;
                drop--;
                cout << "Unable to control, you can only drop, remaining: " << drop << " times" << endl;
                break;;
            }


            cmdin = cmd.n_com(input);
            int n = cmd.n_count(input);
            cmdin = cmd.readcom(cmdin);

            if (cmdin == "drop" && n > 0) {drop = n;}
            
            n = (n == 0) ? 1 : n;

            if (cmdin == "rename") {
                string old, cur;
                cin >> old;
                cin >> cur;
                cmd.short_com(old, cur);
                cout << t;
                continue;
            }

            if (cmdin == "left") {
                for (int i = 0; i < n; ++i) {
                    if (touch) {
                        if (heavy) {
                            touch = cur_play->move(-1, 0, curBlock->getWeight() + 2, curBlock);
                        } else {
                            touch = cur_play->move(-1, 0, curBlock->getWeight(), curBlock);
                        }
                    }
                }
            }

            if (cmdin == "right") {
                for (int i = 0; i < n; ++i) {
                    if (touch) {
                        if (heavy) {
                            touch = cur_play->move(1, 0, curBlock->getWeight() + 2, curBlock);
                        } else {
                            touch = cur_play->move(1, 0, curBlock->getWeight(), curBlock);
                        }
                    }
                }
            }

            if (cmdin == "down") {
                for (int i = 0; i < n; ++ i) {
                    if (touch) {
                        touch = cur_play->move(0, 1, curBlock->getWeight(), curBlock);
                    }
                }
            }
            
            if (cmdin == "clockwise") {
                for (int i = 0; i < n; ++ i) {
                    if (touch) {
                        cur_play->spin(curBlock, true);
                        touch = cur_play->move(0, 1, curBlock->getWeight(), curBlock);
                    }
                }
            }

            if (cmdin == "counterclockwise") {
                for (int i = 0; i < n; ++ i) {
                    if (touch) {
                        cur_play->spin(curBlock, false);
                        touch = cur_play->move(0, 1, curBlock->getWeight(), curBlock);
                    }
                }
            }

            if (cmdin == "drop") {
                while (touch) {
                    touch = cur_play->move(0, 1, curBlock->getWeight(), curBlock);
                }
                cur_play->addBlock(curBlock);
                curBlock->eraseallcell(nullptr, nullptr, nullptr, nullptr);

                rowCleared = cur_play->BlockClear();

                int step = cur_play->getDropTime() + 1;
                cur_play->setDropTime(step);
                if ((cur_play->getLevel() == 4) && (step > 0) && (step % 5 == 0)) {
                    int result = cur_play->dropMid();
                    if (!result) {
                        if (b1->getScore() > b2->getScore()) {
                            cout << "Player1 wins!" << endl;
                        } else if (b1->getScore() > b2->getScore()) {
                            cout << "Player2 wins!" << endl;
                        } else {
                            cout << "DRAW!!!" << endl;
                        }
                        // delete b1;
                        // delete b2;
                        // delete pb1;
                        // delete pb2;
                        return 0;
                    }
                }

                int p1_score = b1->getScore();
                int p2_score = b2->getScore();
        
                if ((p1_score > hi_score) || (p2_score > hi_score)) {
                    t.setHiscore((p1_score > p2_score) ? p1_score : p2_score);
                }

                //! Clear lines
                if (heavy) {heavy = false;}
                break;
            }

            if (cmdin == "levelup") {
                for (int i = 0; i < n; ++ i) {
                    int cur_level = cur_play->getLevel();
                    if (cur_level < 4) {
                        cur_level += 1;
                    }
                    cur_play->setLevel(cur_level);
                }
            }

            if (cmdin == "leveldown") { 
                for (int i = 0; i < n; ++ i) {
                    int cur_level = cur_play->getLevel();
                    if (cur_level > 0) {
                        cur_level -= 1;
                    }
                    cur_play->setLevel(cur_level);
                }
            }

            if (cmdin == "norandom") {
                cout << "Not yet developed" << endl;
            }

            if (cmdin == "random") {
                

            if (cmdin == "sequence") {
                cout << "Not yet developed" << endl;
            }

            if (cmdin == "restart") {
                
                cout << "Not yet developed" << endl;
                // restart = true;
                //! Need to clear the borads

            }

            //! For Block create with Block name
            if (cmdin.length() == 1) {
                Difficulty *newBlock;
                int cur_level = cur_play->getLevel();

                if (cmdin == "I") {
                    curBlock->clearCellState();
                    newBlock = cur_play->generateNewBlock('I', cur_level);
                    cur_play->setCurBlock(newBlock);
                } else if (cmdin == "J") {
                    curBlock->clearCellState();
                    newBlock = cur_play->generateNewBlock('J', cur_level);
                    cur_play->setCurBlock(newBlock);
                } else if (cmdin == "L") {
                    curBlock->clearCellState();
                    newBlock = cur_play->generateNewBlock('L', cur_level);
                    cur_play->setCurBlock(newBlock);
                } else if (cmdin == "O") {
                    curBlock->clearCellState();
                    newBlock = cur_play->generateNewBlock('O', cur_level);
                    cur_play->setCurBlock(newBlock);
                } else if (cmdin == "S") {
                    curBlock->clearCellState();
                    newBlock = cur_play->generateNewBlock('S', cur_level);
                    cur_play->setCurBlock(newBlock);
                } else if (cmdin == "Z") {
                    curBlock->clearCellState();
                    newBlock = cur_play->generateNewBlock('Z', cur_level);
                    cur_play->setCurBlock(newBlock);
                } else if (cmdin == "T") {
                    curBlock->clearCellState();
                    newBlock = cur_play->generateNewBlock('T', cur_level);
                    cur_play->setCurBlock(newBlock);
                } else {
                    continue;
                }
            }
        }
        cout << t;

        }
        if (blind) {
            cur_play->blind();
            blind = false;
        }
    }
}
