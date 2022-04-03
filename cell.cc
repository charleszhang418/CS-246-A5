#include <vector> 
#include "subject.h"
#include "observer.h"
#include "cell.h"
using namespace std;

Cell::Cell(int col, int row, char value) :  col{col}, row{row}, value{value} {}

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

Difficulty* Cell::getblock() {
    return block;
}

void Cell::eraseRow(int row) {
    this->row = row;
}

void Cell::eraseCol(int col) {
    this->col = col;
}

void Cell::eraseValue(char value) {
    this->value = value;
}

void Cell::eraseIffilled(bool iffilled) {
    this->iffilled = iffilled;
}

void Cell::eraseBlock(Difficulty* block) {
    this->block = block;
}

void Cell::copy(Cell* target) {
    eraseRow(target->getrow());
    eraseCol(target->getcol());
    eraseIffilled(target->getiffilled());
    eraseValue(target->getvalue());
    eraseBlock(target->getblock());
}

void Cell::ClearCell() {
    eraseIffilled(false);
    eraseValue(' ');
    eraseBlock(nullptr);
}

