#include <vector> 
#include <iostream>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "block.h"
#include "board.h"
using namespace std;

Board::Board(int width, int height, int level, int score) : 
width{width}, height{height}, level{level}, score{score} {
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

char Board::getVal(int col, int row) {
    return cells[col][row]->getvalue();
}

/*
void Board::spin(Block* change, bool clock) {
    
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
        for (int i = 0; i < 4; i++) {
            int old1 = placeold[i][0];
            int old2 = placeold[i][1];
            // cells[old1][old2]->eraseValue(' ');
            // cells[old1][old2]->eraseIffilled(true);
            
            int new1 = placenew[i][0];
            int new2 = placenew[i][1];
            
            // cells[new1][new2]->eraseValue(need);
            // cells[new1][new2]->eraseIffilled(false);   
        }
         
        change->erasetype(clock);
        cout << need << endl;
        cout << (placenew[0][0]) << (placenew[0][1]) << (placenew[1][0]) <<
        (placenew[1][1]) << (placenew[2][0]) << (placenew[2][1]) <<
        (placenew[3][0]) << (placenew[3][1]);
        Cell* cell1 = cells[placenew[0][0]][placenew[0][1]];
        Cell* cell2 = cells[placenew[1][0]][placenew[1][1]];
        Cell* cell3 = cells[placenew[2][0]][placenew[2][1]];
        Cell* cell4 = cells[placenew[3][0]][placenew[3][1]];
        change->eraseallcell(cell1, cell2, cell3, cell4);
        change->updateCellState();
    }
}

*/

void Board::spin(Block* change, bool clock) {
    vector<vector<int>> placenew =  change->rotate(clock);
    for (int i = 0; i < 4; i++) {
            int old1 = placenew[i][0];
            int old2 = placenew[i][1];
            cout << old1 << ' ' << old2 << endl;
    }

    vector<vector<int>> v = change->rotate(clock);
    int col1 = v[0][0];
    cout << col1 << endl;
    int col2 = v[1][0];
    int col3 = v[2][0];
    int col4 = v[3][0];
    int row1 = v[0][1];
    int row2 = v[1][1];
    int row3 = v[2][1];
    int row4 = v[3][1];
    if ((col1 >= 0 && col1 < width) && (col2 >= 0 && col2 < width) && 
    (col3 >= 0 && col3 < width) && (col4 >= 0 && col4 < width) && (row1 >= 0 && row1 < height) 
    && (row2 >= 0 && row2 < height) && (row3 >= 0 && row3 < height) && (row4 >= 0 && row4 < height)) {
        change->clearCellState();
    Cell* cell1 = this->getCell(col1, row1);
    Cell* cell2 = this->getCell(col2, row2);
    Cell* cell3 = this->getCell(col3, row3);
    Cell* cell4 = this->getCell(col4, row4);
    if (!(cell1->getiffilled()) && !(cell2->getiffilled()) && !(cell3->getiffilled()) && !(cell4->getiffilled())) {
        change->eraseallcell(cell1, cell2, cell3, cell4);
        change->updateCellState();
    } else {
        change->updateCellState();
    }
    }
}




Cell* Board::getCell(int col, int row) {
    return this->cells[row][col];
}

Block* Board::generateNewBlock(char c) {
    if (c == 'I') {
       return new IBlock(this->getCell(0, 3), this->getCell(1, 3), this->getCell(2, 3), this->getCell(3, 3));
    } else if (c == 'J') {
       return new JBlock(this->getCell(0, 2), this->getCell(0, 3), this->getCell(1, 3), this->getCell(2, 3));
    } else if (c == 'L') {
       return new LBlock(this->getCell(0, 2), this->getCell(0, 3), this->getCell(1, 3), this->getCell(2, 3));
    } else if (c == 'O') {
       return new OBlock(this->getCell(0, 2), this->getCell(1, 2), this->getCell(0, 3), this->getCell(1, 3));
    } else if (c == 'S') {
       return new SBlock(this->getCell(1, 2), this->getCell(2, 2), this->getCell(0, 3), this->getCell(1, 3));
    } else if (c == 'Z') {
       return new ZBlock(this->getCell(0, 2), this->getCell(1, 2), this->getCell(1, 3), this->getCell(1, 4));
    } else {
       return new TBlock(this->getCell(0, 2), this->getCell(1, 2), this->getCell(2, 2), this->getCell(1, 3));
    }
}

bool Board::move(int x, int y, int weight, Block* b) {
    // int col1 = b
    // if (x == 1) {

    // }
}

Board::~Board() {}

void Board::DropDown(int fresh) {
    for (int i = fresh; i > 0; i--) {
        for (int j = 0; j < width; j++) {
            cells[j][i]->copy(cells[j][i-1]);
        }
    }
    for (int j = 0; j < width; j++) {
        cells[j][0]->ClearCell();
    }
}



int Board::BlockClear() {
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
                cells[j][i]->attach(cells[j][i]->getvblock());
                cells[j][i]->notifyObservers();
                cells[j][i]->detach(cells[j][i]->getvblock());
            }
            DropDown(i);
            score += ((level + 1) * (level + 1));
            i += 1;
        }
    }
    return line;
}

void Board::notify() {
    for (auto& b : blocks) {
        if (b->checkBlank()) {
            score += ((b->getlevel()) * (b->getlevel()));
            for (int i = 0; i < blocks.size(); i++) {
                if (blocks[i] == b) {
                    blocks.erase(blocks.begin() + (i - 1));
                    break;
                }
            }
        }
    }
}


