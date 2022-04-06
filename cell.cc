#include <vector> 
#include "difficulty.h"
#include "cell.h"
using namespace std;

Cell::Cell(int col, int row, char value): col{col}, row{row}, value{value} {}


Cell::~Cell() {
}

bool Cell::getiffilled() {
    return iffilled;
}

int Cell::getrow() {
    return row;
}

int Cell::getcol() {
    return col;
}

Difficulty* Cell::getblock() {
    return block;
}

void Cell::eraseBlock(Difficulty* diff) {
    block = diff;
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

bool Cell::getblind() {
    return blind;
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

void Cell::eraseBlind() {
    if (blind == false) {
        blind = true;
    } else {
        blind = false;
    }
}


void Cell::copy(Cell* target) {
    eraseIffilled(target->getiffilled());
    eraseValue(target->getvalue());
    eraseBlock(target->getblock());
}

void Cell::ClearCell() {
    eraseIffilled(false);
    eraseValue(' ');
    eraseBlock(nullptr);
}



