#include <vector> 
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "block.h"
#include "board.h"
using namespace std;

Cell::Cell(int row, int col, char value) :  col{col}, row{row}, value{value} {}

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

void Cell::eraseRow(int row) {
    row = row;
}

void Cell::eraseCol(int col) {
    col = col;
}

void Cell::eraseValue(char value) {
    value = value;
}

void Cell::eraseIffilled(bool iffilled) {
    iffilled = iffilled;
}



void Cell::notify() {
    return;
}