#include <vector> 
#include <iostream>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "block.h"
#include "board.h"
#include "difficulty.h"
using namespace std;

Board::Board(int width, int height, int level, int score, int dropTime) : 
width{width}, height{height}, level{level}, score{score}, dropTime{dropTime} {
    vector<vector<Cell*>> cells;
    for (int i = 0; i < height; i++) {
        vector<Cell*> line;
        for (int j = 0; j < width; j++) {
            Cell* cell = new Cell(j, i,' ');
            line.emplace_back(cell);
        }
        cells.emplace_back(line);
    }
    this->cells = cells;
    vector<Block*> blocks;
    blocks = blocks;
}

void Board::setLevel(int level) {
    this->level = level;
}

void Board::setDropTime(int dropTime) {
    dropTime = dropTime;
}

int Board::getLevel() const {
    return level;
} 

int Board::getScore() const {
    return score;
}

char Board::getVal(int col, int row) {
    return cells[col][row]->getvalue();
}

int Board::getDropTime() const {
    return dropTime;
}


void Board::spin(Difficulty* change, bool clock) {

    bool suc = 1;
    vector<vector<int>> placeold =  change->getalllocation();
    vector<vector<int>> placenew =  change->rotate(clock);

    for (int i = 0; i < 4; i++) {
        int new1 = placenew[i][0];
        int new2 = placenew[i][1];
        if ((new1 < 0) || (new2 < 0) || (new1 >= width) || (new2 >= height)) {
            suc = 0;
            break;
        }
        if (cells[new1][new2]->getiffilled()) {
            suc = 0;
            break;
        }
    }

    if (suc == 1) {
        change->clearCellState();
        char need = change->getChar();
        // for (int i = 0; i < 4; i++) {
        //     int old1 = placeold[i][0];
        //     int old2 = placeold[i][1];
        //     // cells[old1][old2]->eraseValue(' ');
        //     // cells[old1][old2]->eraseIffilled(true);

        //     int new1 = placenew[i][0];
        //     int new2 = placenew[i][1];

        //     // cells[new1][new2]->eraseValue(need);
        //     // cells[new1][new2]->eraseIffilled(false);
        // }

        change->erasetype(clock);
        cout << need << endl;
        cout << (placenew[0][0]) << (placenew[0][1]) << (placenew[1][0]) <<
        (placenew[1][1]) << (placenew[2][0]) << (placenew[2][1]) <<
        (placenew[3][0]) << (placenew[3][1]);
        Cell* cell1 = getCell(placenew[0][0], placenew[0][1]);
        Cell* cell2 = getCell(placenew[1][0], placenew[1][1]);
        Cell* cell3 = getCell(placenew[2][0], placenew[2][1]);
        Cell* cell4 = getCell(placenew[3][0], placenew[3][1]);
        change->eraseallcell(cell1, cell2, cell3, cell4);
        change->updateCellState();
        cell1->eraseBlock(curBlock);
        cell2->eraseBlock(curBlock);
        cell3->eraseBlock(curBlock);
        cell4->eraseBlock(curBlock);
    }
}





Cell* Board::getCell(int col, int row) {
    return this->cells[row][col];
}

Difficulty* Board::generateNewBlock(char c, int level) {
    Block* block;
    Difficulty* diff;
    if (c == 'I') {
        block = new IBlock(level, this->getCell(0, 3), this->getCell(1, 3), this->getCell(2, 3), this->getCell(3, 3));
    } else if (c == 'J') {
        block = new JBlock(level, this->getCell(0, 2), this->getCell(0, 3), this->getCell(1, 3), this->getCell(2, 3));
    } else if (c == 'L') {
        block = new LBlock(level, this->getCell(2, 2), this->getCell(0, 3), this->getCell(1, 3), this->getCell(2, 3));
    } else if (c == 'O') {
        block = new OBlock(level, this->getCell(0, 2), this->getCell(1, 2), this->getCell(0, 3), this->getCell(1, 3));
    } else if (c == 'S') {
        block = new SBlock(level, this->getCell(1, 2), this->getCell(2, 2), this->getCell(0, 3), this->getCell(1, 3));
    } else if (c == 'Z') {
        block = new ZBlock(level, this->getCell(0, 2), this->getCell(1, 2), this->getCell(1, 3), this->getCell(2, 3));
    } else {
        block = new TBlock(level, this->getCell(0, 2), this->getCell(1, 2), this->getCell(2, 2), this->getCell(1, 3));
    }
    if (level >= 0) {
        
        diff = new Level0(block);
        
    } 
    if (level >= 1) {
        diff = new Level1(diff);
    }
    if (level >= 2) {
        diff = new Level2(diff);
    }
    if (level >= 3) {
        diff = new Level3(diff);
    }
    if (level >= 4) {
        diff = new Level4(diff);
    }
    curBlock = diff;
    //block->updateBlockDifficulty(diff);
    return diff;
}

bool Board::move(int x, int y, int weight, Difficulty* b) {
    int sum = y + weight;
    while ((x != 0) || (sum > 0)) {
        int col1 = b->getalllocation()[0][0];
        int row1 = b->getalllocation()[0][1];
        int col2 = b->getalllocation()[1][0];
        int row2 = b->getalllocation()[1][1];
        int col3 = b->getalllocation()[2][0];
        int row3 = b->getalllocation()[2][1];
        int col4 = b->getalllocation()[3][0];
        int row4 = b->getalllocation()[3][1];
        if (x != 0) {
            if (((col1 + x) >= 0) && ((col1 + x) < 11) && ((col2 + x) >= 0) && ((col2 + x) < 11) && ((col3 + x) >= 0) && ((col3 + x) < 11) && ((col4 + x) >= 0) && ((col4 + x) < 11)) {
                b->clearCellState();
                Cell* cell1 = this->getCell(col1 + x, row1);
                Cell* cell2 = this->getCell(col2 + x, row2);
                Cell* cell3 = this->getCell(col3 + x, row3);
                Cell* cell4 = this->getCell(col4 + x, row4);
                if (!(cell1->getiffilled()) && !(cell2->getiffilled()) && !(cell3->getiffilled()) && !(cell4->getiffilled())) {
                    b->eraseallcell(cell1, cell2, cell3, cell4);
                    b->updateCellState();
                    cell1->eraseBlock(curBlock);
                    cell2->eraseBlock(curBlock);
                    cell3->eraseBlock(curBlock);
                    cell4->eraseBlock(curBlock);
                } else {
                    b->updateCellState();
                    cell1->eraseBlock(curBlock);
                    cell2->eraseBlock(curBlock);
                    cell3->eraseBlock(curBlock);
                    cell4->eraseBlock(curBlock);
                }
            }
            x = 0;
        } else {
            if ((row1 + 1 < 18) && (row2 + 1 < 18) && (row3 + 1 < 18) && (row4 + 1 < 18)) {
                b->clearCellState();
                Cell* cell1 = this->getCell(col1, row1 + 1);
                Cell* cell2 = this->getCell(col2, row2 + 1);
                Cell* cell3 = this->getCell(col3, row3 + 1);
                Cell* cell4 = this->getCell(col4, row4 + 1);
                if (!(cell1->getiffilled()) && !(cell2->getiffilled()) && !(cell3->getiffilled()) && !(cell4->getiffilled())) {
                    b->eraseallcell(cell1, cell2, cell3, cell4);
                    b->updateCellState();
                    cell1->eraseBlock(curBlock);
                    cell2->eraseBlock(curBlock);
                    cell3->eraseBlock(curBlock);
                    cell4->eraseBlock(curBlock);
                } else {
                    b->updateCellState();
                    cell1->eraseBlock(curBlock);
                    cell2->eraseBlock(curBlock);
                    cell3->eraseBlock(curBlock);
                    cell4->eraseBlock(curBlock);
                    return false;
                }
            sum -= 1;
            } else {
                return false;
            }
        }
    }
    return true;  
}

Board::~Board() {}

void Board::DropDown(int fresh) {
    for (int i = fresh; i > 0; i--) {
        for (int j = 0; j < width; j++) {
            // if (cells[j][i-1]->getblock() != nullptr) {
            //     cells[j][i-1]->getblock()->
            // }
            cells[j][i]->copy(cells[j][i-1]);
        }
    }
    for (int j = 0; j < width; j++) {
        cells[j][0]->ClearCell();
    }
}



bool Board::BlockClear() {
    int line = 0;
    for (int i = (height - 1); i >= 0; i--) {
        bool clear = true;
        for (int j = 0; j < width; j++) {
            if (!(cells[j][i]->getiffilled())) {
                clear = false;
            }
        }
        if (clear == true) {
            line++;
            for (int j = 0; j < width; j++) {
                cells[j][i]->ClearCell();
                cells[j][i]->attach(cells[j][i]->getblock());
                cells[j][i]->notifyObservers();
                cells[j][i]->detach(cells[j][i]->getblock());
                deleteBlock();
            }
            for (int j = 0; j < width; j++) {
                cells[j][i]->eraseBlock(nullptr);
                }
            DropDown(i);
            score += ((level + 1) * (level + 1));
            i += 1;
        }
    }
    if (line >= 2) {
        return true;
    } else {
        return false;
    }
}

void Board::deleteBlock() {
    for (auto& b : blocks) {
        if (b->checkBlank()) {
            score += ((b->getlevel()) * (b->getlevel()));
            for (int i = 0; i < blocks.size(); i++) {
                if (blocks[i] == b) {
                    blocks.erase(blocks.begin() + (i - 1));
                    delete b;
                    return;
                }
            }
        }
    }
}


