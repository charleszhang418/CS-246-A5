#include <vector> 
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "block.h"
#include "board.h"
using namespace std;

Cell::Cell(int row, int col) : row{row}, col{col} {}

std::vector<int> getState() {

}

void Cell::notify( Subject& ) {
    return
}