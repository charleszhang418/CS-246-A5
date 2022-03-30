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


Block* spin(Block* change) {
    bool suc = true;
    vector<vector<int>> place =  helper(change);
    for (int i = 0; i < 4; i++) {
        int new1 = place[i][0];
        int new2 = place[i][1];
        if 
    }
}





