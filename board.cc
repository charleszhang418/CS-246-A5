#include <vector> 
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "block.h"
#include "board.h"
using namespace std;

Board::Board(int level, int width, int height) : level{level},
width{width}, height{height} {
    vector<std::vector<Cell*>> cells;
    for (int i = 0; i < height; i++) {
        vector<Cell*> line;
        for (int j = 0; j < width; j++) {
            Cell* cell = new Cell(j,i);
            line.emplace_back(cell);
        }
     cells.emplace_back(line);
    }
}

<<<<<<< Updated upstream
char Board::getVal(int col, int row) const {
    return cells[col][row]->getvalue();
}

/*
Block* Board::spin(Block* change) {
=======
/*
Block* spin(Block* change) {
>>>>>>> Stashed changes
    bool suc = true;
    vector<vector<int>> placeold =  helper1(change);
    vector<vector<int>> placenew =  helper2(change);
    for (int i = 0; i < 4; i++) {
<<<<<<< Updated upstream
        int new1 = placenew[i][0];
        int new2 = placenew[i][1];
        if (cells[new1][new2]->getiffilled()) {
            suc = false;
        }
    }
    if (suc = true) {
        for (int i = 0; i < 4; i++) {
            int old1 = placeold[i][0];
            int old2 = placeold[i][1];
            cells[old1][old2]->eraseValue(' ');
            cells[old1][old2]->eraseIffilled(false);
            char need = 
    }
=======
        int new1 = place[i][0];
        int new2 = place[i][1];

>>>>>>> Stashed changes
}

*/




