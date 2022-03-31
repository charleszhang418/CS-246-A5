#include <vector> 
#include <iostream>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "block.h"
#include "board.h"
using namespace std;

Board::Board(int width, int height, int level) : 
width{width}, height{height}, level{level} {
    vector<vector<Cell*>> cells;
    for (int i = 0; i < height; i++) {
        vector<Cell*> line;
        for (int j = 0; j < width; j++) {
            Cell* cell = new Cell(j,i,' ');
            line.emplace_back(cell);
        }
        cells.emplace_back(line);
    }
    this->cells = cells;
}

char Board::getVal(int col, int row) {
    return cells[col][row]->getvalue();
}

/*
Block* Board::spin(Block* change, bool clock) {
    bool suc = true;
    vector<vector<int>> placeold =  getalllocation(change);
    vector<vector<int>> placenew =  rotate(change);
    
    for (int i = 0; i < 4; i++) {
        int new1 = placenew[i][0];
        int new2 = placenew[i][1];
        if (cells[new1][new2]->getiffilled()) {
            suc = false;
        }
    }
    
    if (suc = true) {
        char need = change->getChar();
        for (int i = 0; i < 4; i++) {
            int old1 = placeold[i][0];
            int old2 = placeold[i][1];
            cells[old1][old2]->eraseValue(' ');
            cells[old1][old2]->eraseIffilled(false);
            
            int new1 = placenew[i][0];
            int new2 = placenew[i][1];
            
            cells[new1][new2]->eraseValue(need);
            cells[new1][new2]->eraseIffilled(true);   
        }
        change->erasetype(clock);
        Cell* cell1 = cells[placenew[0][0]][placenew[0][1]];
        Cell* cell2 = cells[placenew[1][0]][placenew[1][1]];
        Cell* cell3 = cells[placenew[2][0]][placenew[2][1]];
        Cell* cell4 = cells[placenew[3][0]][placenew[3][1]];
        change->eraseallcell(cell1, cell2, cell3, cell4);
    }
}


*/

Cell* Board::getCell(int col, int row) {
    return this->cells[col][row];
}

Board::~Board() {}


