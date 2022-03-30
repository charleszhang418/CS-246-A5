#include <vector> 
#include "subject.h"
#include "observer.h"
#include "cell.h"
using namespace std;

Cell::Cell(int row, int col, char value) :  row{row}, col{col}, value{value} {}

bool Cell::getiffilled() {
    return iffilled;
}

int Cell::getrow() {
    return row;
}

int Cell::getcol() {
    return col;
}

vector<int> Cell::getlocation() {
    vector<int> location;
    location.emplace_back(this->getcol());
    location.emplace_back(this->getrow());
    return location;
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

