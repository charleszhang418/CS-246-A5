#include <vector> 
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "block.h"
#include "board.h"
using namespace std;

Cell::Cell(int row, int col) : row{row}, col{col} {}

bool Cell::getiffilled() {
    return iffilled;
}

int Cell::getrow() {
    return row;
}

int Cell::getcol() {
    return col;
}

char Cell::getvalue() {
    return value;
}



void Cell::notify( Subject& ) {
    return
}