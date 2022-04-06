#include <vector> 
#include <iostream>
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
    this->dropTime = dropTime;
}

void Board::setCurBlock(Difficulty* diff) {
    curBlock = diff;
}

void Board::setNextBlock(char c) {
    nextBlock = c;
}

void Board::addBlock(Difficulty* diff) {
    blocks.emplace_back(diff);
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

Difficulty* Board::getCurBlock() const {
    return curBlock;
}

char Board::getNextBlock() const {
    return nextBlock;
}

void Board::spin(Difficulty* change, bool clock) {

    bool suc = 1;
    vector<vector<int>> placeold =  change->getalllocation();
    vector<vector<int>> placenew =  change->rotate(clock);

    for (int i = 0; i < 4; i++) {
        int new1 = placenew[i][0];
        int new2 = placenew[i][1];
        change->clearCellState();
        if ((new1 < 0) || (new2 < 0) || (new1 >= width) || (new2 >= height)) {
            suc = 0;
            change->updateCellState(curBlock);
            break;
        }

        if (cells[new1][new2]->getiffilled()) {
            suc = 0;
            change->updateCellState(curBlock);
            break;
        }
    }

    if (suc == 1) {
        change->erasetype(clock);
        
        Cell* cell1 = getCell(placenew[0][0], placenew[0][1]);
        Cell* cell2 = getCell(placenew[1][0], placenew[1][1]);
        Cell* cell3 = getCell(placenew[2][0], placenew[2][1]);
        Cell* cell4 = getCell(placenew[3][0], placenew[3][1]);
        change->eraseallcell(cell1, cell2, cell3, cell4);
        change->updateCellState(curBlock);
    }
}





Cell* Board::getCell(int col, int row) {
    return this->cells[row][col];
}

Difficulty* Board::generateNewBlock(char c, int level) {
    Block* block;
    Difficulty* diff;
    if (c == 'I') {
        if (this->getCell(0, 3)->getiffilled() || this->getCell(1, 3)->getiffilled() || this->getCell(2, 3)->getiffilled() || this->getCell(3, 3)->getiffilled()) {
            return nullptr;
        } else {
            block = new IBlock(level, this->getCell(0, 3), this->getCell(1, 3), this->getCell(2, 3), this->getCell(3, 3));
        } 
    } else if (c == 'J') {
        if (this->getCell(0, 2)->getiffilled() || this->getCell(0, 3)->getiffilled() || this->getCell(1, 3)->getiffilled() || this->getCell(2, 3)->getiffilled()) {
            return nullptr;
        } else {
            block = new JBlock(level, this->getCell(0, 2), this->getCell(0, 3), this->getCell(1, 3), this->getCell(2, 3));
        }
    } else if (c == 'L') {
        if (this->getCell(2, 2)->getiffilled() || this->getCell(0, 3)->getiffilled() || this->getCell(1, 3)->getiffilled() || this->getCell(2, 3)->getiffilled()) {
            return nullptr;
        } else {
            block = new LBlock(level, this->getCell(2, 2), this->getCell(0, 3), this->getCell(1, 3), this->getCell(2, 3));
        }
    } else if (c == 'O') {
        if (this->getCell(0, 2)->getiffilled() || this->getCell(1, 2)->getiffilled() || this->getCell(0, 3)->getiffilled() || this->getCell(1, 3)->getiffilled()) {
            return nullptr;
        } else {
            block = new OBlock(level, this->getCell(0, 2), this->getCell(1, 2), this->getCell(0, 3), this->getCell(1, 3));
        }
    } else if (c == 'S') {
        if (this->getCell(1, 2)->getiffilled() || this->getCell(2, 2)->getiffilled() || this->getCell(0, 3)->getiffilled() || this->getCell(1, 3)->getiffilled()) {
            return nullptr;
        } else {
            block = new SBlock(level, this->getCell(1, 2), this->getCell(2, 2), this->getCell(0, 3), this->getCell(1, 3));
        }
    } else if (c == 'Z') {
        if (this->getCell(0, 2)->getiffilled() || this->getCell(1, 2)->getiffilled() || this->getCell(1, 3)->getiffilled() || this->getCell(2, 3)->getiffilled()) {
            return nullptr;
        } else {
            block = new ZBlock(level, this->getCell(0, 2), this->getCell(1, 2), this->getCell(1, 3), this->getCell(2, 3));
        }
    } else if (c == 'T'){
        if (this->getCell(0, 2)->getiffilled() || this->getCell(1, 2)->getiffilled() || this->getCell(2, 2)->getiffilled() || this->getCell(1, 3)->getiffilled()) {
            return nullptr;
        } else {
            block = new TBlock(level, this->getCell(0, 2), this->getCell(1, 2), this->getCell(2, 2), this->getCell(1, 3));
        }
    } else {
        return nullptr;
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
    diff->updateCellState(diff);
    this->curBlock = diff;
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
                    b->updateCellState(curBlock);
                } else {
                    b->updateCellState(curBlock);
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
                    b->updateCellState(curBlock);
                } else {
                    b->updateCellState(curBlock);
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

bool Board::dropMid() {
    if (this->getCell(5, 0)->getiffilled()) {
        return false;
    } else {
        int i = 0;
        while ((i + 1 < height) && !(this->getCell(5, i + 1)->getiffilled())) {
            i += 1;
        }
        this->getCell(5, i)->eraseValue('*');
        this->getCell(5, i)->eraseIffilled(true);
        // std::cout << i << std::endl;

        // this->BlockClear();
        return true;
    }
}



Board::~Board() {}

void Board::DropDown(int fresh) {
    for (int i = fresh; i > 0; i--) {
        for (int j = 0; j < width; j++) {
            // if (cells[j][i-1]->getblock() != nullptr) {
            //     cells[j][i-1]->getblock()->
            // }
            getCell(j, i)->copy(getCell(j, i - 1));
        }
    }
    for (int j = 0; j < width; j++) {
        getCell(j, 0)->ClearCell();
    }
}



bool Board::BlockClear() {
    int line = 0;
    for (int i = (height - 1); i >= 0; i--) {
        bool clear = true;
        for (int j = 0; j < width; j++) {
            if (!(cells[i][j]->getiffilled())) {
                clear = false;
            }
        }
        if (clear == true) {
            line++;
            for (int j = 0; j < width; j++) {
                // cells[j][i]->attach(cells[j][i]->getblock());
                // std::cout << curBlock << std::endl;

                
                
                
                if (cells[i][j]->getblock() != 0) {
                    cells[i][j]->getblock()->updateCellCleared();
                }
                
                cells[i][j]->ClearCell();
                // cells[j][i]->detach(cells[j][i]->getblock());
                deleteBlock();
            }
            // for (int j = 0; j < width; j++) {
            //     cells[i][j]->eraseBlock(nullptr);
            // }
            DropDown(i);
            score += ((level + 1) * (level + 1));
            i += 1;
            this->dropTime = 0;
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
            score += ((b->getLevel() + 1) * (b->getLevel()) + 1);
            for (size_t i = 0; i < blocks.size(); i++) {
                if (blocks[i] == b) {
                    blocks.erase(blocks.begin() + i);
                    // delete b;
                    return;
                }
            }
        }
    }
}

void Board::blind() {
    for (int i = 2; i <= 11; i++) {
        for (int j = 2; j <= 8; j++) {
            getCell(j,i)->eraseBlind();
        }
    }
}
