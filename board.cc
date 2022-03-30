#include <vector> 
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "block.h"
#include "board.h"
using namespace std;

Board::Board(const int& level, const int& width, const int& height): level{level},
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








