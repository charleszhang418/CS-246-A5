#include "block.h"
#include "cell.h"

#include <iostream>

using namespace std;


void Block::erasetype(bool clock) {
    if (clock) {
        if (type == 3) {
            type = 0;
        } else {
            type++;
        }
    } else {
        if (type == 0) {
            type = 3;
        } else {
            type--;
        }
    }
}

void Block::clearCellState() {
    cell1->eraseIffilled(false);
    cell2->eraseIffilled(false);
    cell3->eraseIffilled(false);
    cell4->eraseIffilled(false);
    cell1->eraseValue(' ');
    cell2->eraseValue(' ');
    cell3->eraseValue(' ');
    cell4->eraseValue(' ');
    cell1->eraseBlock(nullptr);
    cell2->eraseBlock(nullptr);
    cell3->eraseBlock(nullptr);
    cell4->eraseBlock(nullptr);
}

// void Block::SetCellState(char type) {
//     cell1->eraseIffilled(true);
//     cell2->eraseIffilled(true);
//     cell3->eraseIffilled(true);
//     cell4->eraseIffilled(true);
//     cell1->eraseValue(type);
//     cell2->eraseValue(type);
//     cell3->eraseValue(type);
//     cell4->eraseValue(type);
// }

int Block::getLevel() {
    return this->level;
}

int Block::getWeight() { return 0; }

int Block::getCellCleared() {
    return cellCleared;
}

void Block::updateCellCleared() {
    this->cellCleared += 1;
}



void Block::eraseallcell(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4) {
   this->cell1 = cell1;
   this->cell2 = cell2;
   this->cell3 = cell3;
   this->cell4 = cell4;
}



std::vector<std::vector<int>> Block::getalllocation() {
    std::vector<std::vector<int>> alllocation;
    alllocation.emplace_back(cell1->getlocation());
    alllocation.emplace_back(cell2->getlocation());
    alllocation.emplace_back(cell3->getlocation());
    alllocation.emplace_back(cell4->getlocation());
    return alllocation;
}


Block::Block(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): level{level}, cell1{cell1}, cell2{cell2}, cell3{cell3}, cell4{cell4} { }

int Block::getType() {
    return this->type;
}

Block::~Block() {}
IBlock::IBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block{level, cell1, cell2, cell3, cell4} { 
    
}

char IBlock::getChar() {
    return this->c;
}

std::vector<std::vector<int>> IBlock::rotate(bool clockwise) {
    std::vector<std::vector<int>> result;
    if ((this->type == 0) || (this->type == 2)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol());
        v1.emplace_back(this->cell1->getrow() - 3);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() - 1);
        v2.emplace_back(this->cell2->getrow() - 2);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() - 2);
        v3.emplace_back(this->cell3->getrow() - 1);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() - 3);
        v4.emplace_back(this->cell4->getrow());
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol());
        v1.emplace_back(this->cell1->getrow() + 3);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() + 1);
        v2.emplace_back(this->cell2->getrow() + 2);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() + 2);
        v3.emplace_back(this->cell3->getrow() + 1);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() + 3);
        v4.emplace_back(this->cell4->getrow());
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    }
    return result;
}

void IBlock::updateCellState(Difficulty* diff) {
    cell1->eraseIffilled(true);
    cell2->eraseIffilled(true);
    cell3->eraseIffilled(true);
    cell4->eraseIffilled(true);
    cell1->eraseValue(this->c);
    cell2->eraseValue(this->c);
    cell3->eraseValue(this->c);
    cell4->eraseValue(this->c);
    cell1->eraseBlock(diff);
    cell2->eraseBlock(diff);
    cell3->eraseBlock(diff);
    cell4->eraseBlock(diff);
}

std::vector<std::vector<int>> IBlock::displayNext() {
    std::vector<std::vector<int>> result;
    std::vector<int> v1;
    v1.emplace_back(0);
    v1.emplace_back(1);
    std::vector<int> v2;
    v2.emplace_back(1);
    v2.emplace_back(1);
    std::vector<int> v3;
    v3.emplace_back(2);
    v3.emplace_back(1);
    std::vector<int> v4;
    v4.emplace_back(3);
    v4.emplace_back(1);
    result.emplace_back(v1);
    result.emplace_back(v2);
    result.emplace_back(v3);
    result.emplace_back(v4);
    return result;
}

IBlock::~IBlock() {}

JBlock::JBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block{level, cell1, cell2, cell3, cell4} { 
   
}

char JBlock::getChar() {
    return this->c;
}

std::vector<std::vector<int>> JBlock::rotate(bool clockwise) {
    std::vector<std::vector<int>> result;
    if ((this->type == 0) && (clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() + 1);
        v1.emplace_back(this->cell1->getrow() - 1);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol());
        v2.emplace_back(this->cell2->getrow() - 2);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() - 1);
        v3.emplace_back(this->cell3->getrow() - 1);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() - 2);
        v4.emplace_back(this->cell4->getrow());
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 0) && (!clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol());
        v1.emplace_back(this->cell1->getrow() + 1);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() + 1);
        v2.emplace_back(this->cell2->getrow());
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol());
        v3.emplace_back(this->cell3->getrow() - 1);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() - 1);
        v4.emplace_back(this->cell4->getrow() - 2);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 1) && (clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() + 1);
        v1.emplace_back(this->cell1->getrow() + 2);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() + 2);
        v2.emplace_back(this->cell2->getrow() + 1);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() + 1);
        v3.emplace_back(this->cell3->getrow());
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol());
        v4.emplace_back(this->cell4->getrow() - 1);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 1) && (!clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() - 1);
        v1.emplace_back(this->cell1->getrow() + 1);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol());
        v2.emplace_back(this->cell2->getrow() + 2);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() + 1);
        v3.emplace_back(this->cell3->getrow() + 1);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() + 2);
        v4.emplace_back(this->cell4->getrow());
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 2) && (clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() - 2);
        v1.emplace_back(this->cell1->getrow());
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() - 1);
        v2.emplace_back(this->cell2->getrow() + 1);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol());
        v3.emplace_back(this->cell3->getrow());
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() + 1);
        v4.emplace_back(this->cell4->getrow() - 1);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 2) && (!clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() - 1);
        v1.emplace_back(this->cell1->getrow() - 2);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() - 2);
        v2.emplace_back(this->cell2->getrow() - 1);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() - 1);
        v3.emplace_back(this->cell3->getrow());
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol());
        v4.emplace_back(this->cell4->getrow() + 1);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 3) && (clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol());
        v1.emplace_back(this->cell1->getrow() - 1);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() - 1);
        v2.emplace_back(this->cell2->getrow());
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol());
        v3.emplace_back(this->cell3->getrow() + 1);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() + 1);
        v4.emplace_back(this->cell4->getrow() + 2);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() + 2);
        v1.emplace_back(this->cell1->getrow());
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() + 1);
        v2.emplace_back(this->cell2->getrow() - 1);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol());
        v3.emplace_back(this->cell3->getrow());
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() - 1);
        v4.emplace_back(this->cell4->getrow() + 1);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    }
    return result;
}

void JBlock::updateCellState(Difficulty* diff) {
    cell1->eraseIffilled(true);
    cell2->eraseIffilled(true);
    cell3->eraseIffilled(true);
    cell4->eraseIffilled(true);
    cell1->eraseValue(this->c);
    cell2->eraseValue(this->c);
    cell3->eraseValue(this->c);
    cell4->eraseValue(this->c);
    cell1->eraseBlock(diff);
    cell2->eraseBlock(diff);
    cell3->eraseBlock(diff);
    cell4->eraseBlock(diff);
}

std::vector<std::vector<int>> JBlock::displayNext() {
    std::vector<std::vector<int>> result;
    std::vector<int> v1;
    v1.emplace_back(0);
    v1.emplace_back(0);
    std::vector<int> v2;
    v2.emplace_back(0);
    v2.emplace_back(1);
    std::vector<int> v3;
    v3.emplace_back(1);
    v3.emplace_back(1);
    std::vector<int> v4;
    v4.emplace_back(2);
    v4.emplace_back(1);
    result.emplace_back(v1);
    result.emplace_back(v2);
    result.emplace_back(v3);
    result.emplace_back(v4);
    return result;
}

JBlock::~JBlock() {}

LBlock::LBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block{level, cell1, cell2, cell3, cell4} { 

}

char LBlock::getChar() {
    return this->c;
}

std::vector<std::vector<int>> LBlock::rotate(bool clockwise) {
    std::vector<std::vector<int>> result;
    if ((this->type == 0) && (clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() - 1);
        v1.emplace_back(this->cell1->getrow() + 1);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol());
        v2.emplace_back(this->cell2->getrow() - 2);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() - 1);
        v3.emplace_back(this->cell3->getrow() - 1);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() - 2);
        v4.emplace_back(this->cell4->getrow());
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 0) && (!clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() - 2);
        v1.emplace_back(this->cell1->getrow() - 1);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() + 1);
        v2.emplace_back(this->cell2->getrow());
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol());
        v3.emplace_back(this->cell3->getrow() - 1);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() - 1);
        v4.emplace_back(this->cell4->getrow() - 2);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 1) && (clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() - 1);
        v1.emplace_back(this->cell1->getrow());
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() + 2);
        v2.emplace_back(this->cell2->getrow() + 1);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() + 1);
        v3.emplace_back(this->cell3->getrow());
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol());
        v4.emplace_back(this->cell4->getrow() - 1);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 1) && (!clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() + 1);
        v1.emplace_back(this->cell1->getrow() - 1);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol());
        v2.emplace_back(this->cell2->getrow() + 2);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() + 1);
        v3.emplace_back(this->cell3->getrow() + 1);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() + 2);
        v4.emplace_back(this->cell4->getrow());
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 2) && (clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol());
        v1.emplace_back(this->cell1->getrow() - 2);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() - 1);
        v2.emplace_back(this->cell2->getrow() + 1);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol());
        v3.emplace_back(this->cell3->getrow());
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() + 1);
        v4.emplace_back(this->cell4->getrow() - 1);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 2) && (!clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() + 1);
        v1.emplace_back(this->cell1->getrow());
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() - 2);
        v2.emplace_back(this->cell2->getrow() - 1);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() - 1);
        v3.emplace_back(this->cell3->getrow());
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol());
        v4.emplace_back(this->cell4->getrow() + 1);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 3) && (clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() + 2);
        v1.emplace_back(this->cell1->getrow() + 1);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() - 1);
        v2.emplace_back(this->cell2->getrow());
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol());
        v3.emplace_back(this->cell3->getrow() + 1);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() + 1);
        v4.emplace_back(this->cell4->getrow() + 2);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol());
        v1.emplace_back(this->cell1->getrow() + 2);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() + 1);
        v2.emplace_back(this->cell2->getrow() - 1);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol());
        v3.emplace_back(this->cell3->getrow());
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() - 1);
        v4.emplace_back(this->cell4->getrow() + 1);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } 
    return result;
}

void LBlock::updateCellState(Difficulty* diff) {
    cell1->eraseIffilled(true);
    cell2->eraseIffilled(true);
    cell3->eraseIffilled(true);
    cell4->eraseIffilled(true);
    cell1->eraseValue(this->c);
    cell2->eraseValue(this->c);
    cell3->eraseValue(this->c);
    cell4->eraseValue(this->c);
    cell1->eraseBlock(diff);
    cell2->eraseBlock(diff);
    cell3->eraseBlock(diff);
    cell4->eraseBlock(diff);
}

std::vector<std::vector<int>> LBlock::displayNext() {
    std::vector<std::vector<int>> result;
    std::vector<int> v1;
    v1.emplace_back(2);
    v1.emplace_back(0);
    std::vector<int> v2;
    v2.emplace_back(0);
    v2.emplace_back(1);
    std::vector<int> v3;
    v3.emplace_back(1);
    v3.emplace_back(1);
    std::vector<int> v4;
    v4.emplace_back(2);
    v4.emplace_back(1);
    result.emplace_back(v1);
    result.emplace_back(v2);
    result.emplace_back(v3);
    result.emplace_back(v4);
    return result;
}

LBlock::~LBlock() {}

OBlock::OBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block{level, cell1, cell2, cell3, cell4} { 

}

char OBlock::getChar() {
    return this->c;
}

std::vector<std::vector<int>> OBlock::rotate(bool clockwise) {
    std::vector<std::vector<int>> result;
    std::vector<int> v1;
    v1.emplace_back(this->cell1->getcol());
    v1.emplace_back(this->cell1->getrow());
    std::vector<int> v2;
    v2.emplace_back(this->cell2->getcol());
    v2.emplace_back(this->cell2->getrow());
    std::vector<int> v3;
    v3.emplace_back(this->cell3->getcol());
    v3.emplace_back(this->cell3->getrow());
    std::vector<int> v4;
    v4.emplace_back(this->cell4->getcol());
    v4.emplace_back(this->cell4->getrow());
    result.emplace_back(v1);
    result.emplace_back(v2);
    result.emplace_back(v3);
    result.emplace_back(v4);
    return result;
}

void OBlock::updateCellState(Difficulty* diff) {
    cell1->eraseIffilled(true);
    cell2->eraseIffilled(true);
    cell3->eraseIffilled(true);
    cell4->eraseIffilled(true);
    cell1->eraseValue(this->c);
    cell2->eraseValue(this->c);
    cell3->eraseValue(this->c);
    cell4->eraseValue(this->c);
    cell1->eraseBlock(diff);
    cell2->eraseBlock(diff);
    cell3->eraseBlock(diff);
    cell4->eraseBlock(diff);
}

std::vector<std::vector<int>> OBlock::displayNext() {
    std::vector<std::vector<int>> result;
    std::vector<int> v1;
    v1.emplace_back(0);
    v1.emplace_back(0);
    std::vector<int> v2;
    v2.emplace_back(1);
    v2.emplace_back(0);
    std::vector<int> v3;
    v3.emplace_back(0);
    v3.emplace_back(1);
    std::vector<int> v4;
    v4.emplace_back(1);
    v4.emplace_back(1);
    result.emplace_back(v1);
    result.emplace_back(v2);
    result.emplace_back(v3);
    result.emplace_back(v4);
    return result;
}

OBlock::~OBlock() {}

SBlock::SBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block{level, cell1, cell2, cell3, cell4} { 
    
}

char SBlock::getChar() {
    return this->c;
}

std::vector<std::vector<int>> SBlock::rotate(bool clockwise) {
    std::vector<std::vector<int>> result;
    if (((this->type == 0) || (this->type == 2))) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol());
        v1.emplace_back(this->cell1->getrow());
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() - 1);
        v2.emplace_back(this->cell2->getrow() + 1);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol());
        v3.emplace_back(this->cell3->getrow() - 2);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() - 1);
        v4.emplace_back(this->cell4->getrow() - 1);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol());
        v1.emplace_back(this->cell1->getrow());
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() + 1);
        v2.emplace_back(this->cell2->getrow() - 1);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol());
        v3.emplace_back(this->cell3->getrow() + 2);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() + 1);
        v4.emplace_back(this->cell4->getrow() + 1);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } 
    return result;
}

void SBlock::updateCellState(Difficulty* diff) {
    cell1->eraseIffilled(true);
    cell2->eraseIffilled(true);
    cell3->eraseIffilled(true);
    cell4->eraseIffilled(true);
    cell1->eraseValue(this->c);
    cell2->eraseValue(this->c);
    cell3->eraseValue(this->c);
    cell4->eraseValue(this->c);
    cell1->eraseBlock(diff);
    cell2->eraseBlock(diff);
    cell3->eraseBlock(diff);
    cell4->eraseBlock(diff);
}

std::vector<std::vector<int>> SBlock::displayNext() {
    std::vector<std::vector<int>> result;
    std::vector<int> v1;
    v1.emplace_back(1);
    v1.emplace_back(0);
    std::vector<int> v2;
    v2.emplace_back(2);
    v2.emplace_back(0);
    std::vector<int> v3;
    v3.emplace_back(0);
    v3.emplace_back(1);
    std::vector<int> v4;
    v4.emplace_back(1);
    v4.emplace_back(1);
    result.emplace_back(v1);
    result.emplace_back(v2);
    result.emplace_back(v3);
    result.emplace_back(v4);
    return result;
}

SBlock::~SBlock() {}

ZBlock::ZBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block{level, cell1, cell2, cell3, cell4} { 
    
}

char ZBlock::getChar() {
    return this->c;
}

std::vector<std::vector<int>> ZBlock::rotate(bool clockwise) {
    std::vector<std::vector<int>> result;
    if (((this->type == 0) || (this->type == 2))) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() + 1);
        v1.emplace_back(this->cell1->getrow() - 1);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol());
        v2.emplace_back(this->cell2->getrow());
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() - 1);
        v3.emplace_back(this->cell3->getrow() - 1);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() - 2);
        v4.emplace_back(this->cell4->getrow());
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() - 1);
        v1.emplace_back(this->cell1->getrow() + 1);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol());
        v2.emplace_back(this->cell2->getrow());
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() + 1);
        v3.emplace_back(this->cell3->getrow() + 1);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() + 2);
        v4.emplace_back(this->cell4->getrow());
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    }
    return result;
}

void ZBlock::updateCellState(Difficulty* diff) {
    cell1->eraseIffilled(true);
    cell2->eraseIffilled(true);
    cell3->eraseIffilled(true);
    cell4->eraseIffilled(true);
    cell1->eraseValue(this->c);
    cell2->eraseValue(this->c);
    cell3->eraseValue(this->c);
    cell4->eraseValue(this->c);
    cell1->eraseBlock(diff);
    cell2->eraseBlock(diff);
    cell3->eraseBlock(diff);
    cell4->eraseBlock(diff);
}

std::vector<std::vector<int>> ZBlock::displayNext() {
    std::vector<std::vector<int>> result;
    std::vector<int> v1;
    v1.emplace_back(0);
    v1.emplace_back(0);
    std::vector<int> v2;
    v2.emplace_back(1);
    v2.emplace_back(0);
    std::vector<int> v3;
    v3.emplace_back(1);
    v3.emplace_back(1);
    std::vector<int> v4;
    v4.emplace_back(2);
    v4.emplace_back(1);
    result.emplace_back(v1);
    result.emplace_back(v2);
    result.emplace_back(v3);
    result.emplace_back(v4);
    return result;
}

ZBlock::~ZBlock() {}

TBlock::TBlock(int level, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block{level, cell1, cell2, cell3, cell4} { 
    
}

char TBlock::getChar() {
    return this->c;
}


std::vector<std::vector<int>> TBlock::rotate(bool clockwise) {
    std::vector<std::vector<int>> result;
    if ((this->type == 0) && (clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() + 1);
        v1.emplace_back(this->cell1->getrow() - 1);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol());
        v2.emplace_back(this->cell2->getrow());
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() - 1);
        v3.emplace_back(this->cell3->getrow() + 1);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() - 1);
        v4.emplace_back(this->cell4->getrow() - 1);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 0) && (!clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol());
        v1.emplace_back(this->cell1->getrow() + 1);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() - 1);
        v2.emplace_back(this->cell2->getrow());
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() - 2);
        v3.emplace_back(this->cell3->getrow() - 1);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol());
        v4.emplace_back(this->cell4->getrow() - 1);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 1) && (clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() + 1);
        v1.emplace_back(this->cell1->getrow() + 2);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol());
        v2.emplace_back(this->cell2->getrow() + 1);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() - 1);
        v3.emplace_back(this->cell3->getrow());
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() + 1);
        v4.emplace_back(this->cell4->getrow());
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 1) && (!clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() - 1);
        v1.emplace_back(this->cell1->getrow() + 1);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol());
        v2.emplace_back(this->cell2->getrow());
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() + 1);
        v3.emplace_back(this->cell3->getrow() - 1);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() + 1);
        v4.emplace_back(this->cell4->getrow() + 1);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 2) && (clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() - 2);
        v1.emplace_back(this->cell1->getrow());
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() - 1);
        v2.emplace_back(this->cell2->getrow() - 1);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol());
        v3.emplace_back(this->cell3->getrow() - 2);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol());
        v4.emplace_back(this->cell4->getrow());
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 2) && (!clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() - 1);
        v1.emplace_back(this->cell1->getrow() - 2);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol());
        v2.emplace_back(this->cell2->getrow() - 1);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() + 1);
        v3.emplace_back(this->cell3->getrow());
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol() - 1);
        v4.emplace_back(this->cell4->getrow());
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else if ((this->type == 3) && (clockwise)) {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol());
        v1.emplace_back(this->cell1->getrow() - 1);
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() + 1);
        v2.emplace_back(this->cell2->getrow());
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol() + 2);
        v3.emplace_back(this->cell3->getrow() + 1);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol());
        v4.emplace_back(this->cell4->getrow() + 1);
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } else {
        std::vector<int> v1;
        v1.emplace_back(this->cell1->getcol() + 2);
        v1.emplace_back(this->cell1->getrow());
        std::vector<int> v2;
        v2.emplace_back(this->cell2->getcol() + 1);
        v2.emplace_back(this->cell2->getrow() + 1);
        std::vector<int> v3;
        v3.emplace_back(this->cell3->getcol());
        v3.emplace_back(this->cell3->getrow() + 2);
        std::vector<int> v4;
        v4.emplace_back(this->cell4->getcol());
        v4.emplace_back(this->cell4->getrow());
        result.emplace_back(v1);
        result.emplace_back(v2);
        result.emplace_back(v3);
        result.emplace_back(v4);
    } 
    return result;
}

void TBlock::updateCellState(Difficulty* diff) {
    cell1->eraseIffilled(true);
    cell2->eraseIffilled(true);
    cell3->eraseIffilled(true);
    cell4->eraseIffilled(true);
    cell1->eraseValue(this->c);
    cell2->eraseValue(this->c);
    cell3->eraseValue(this->c);
    cell4->eraseValue(this->c);
    cell1->eraseBlock(diff);
    cell2->eraseBlock(diff);
    cell3->eraseBlock(diff);
    cell4->eraseBlock(diff);
}

std::vector<std::vector<int>> TBlock::displayNext() {
    std::vector<std::vector<int>> result;
    std::vector<int> v1;
    v1.emplace_back(0);
    v1.emplace_back(0);
    std::vector<int> v2;
    v2.emplace_back(1);
    v2.emplace_back(0);
    std::vector<int> v3;
    v3.emplace_back(2);
    v3.emplace_back(0);
    std::vector<int> v4;
    v4.emplace_back(1);
    v4.emplace_back(1);
    result.emplace_back(v1);
    result.emplace_back(v2);
    result.emplace_back(v3);
    result.emplace_back(v4);
    return result;
}

TBlock::~TBlock() { }

// bool Block::checkBlank() {
//     if ((cell1 == nullptr) && (cell2 == nullptr) && (cell3 == nullptr) && (cell4 == nullptr))  {
//         return true;
//     } else {
//         return false;
//     }
// }

bool Block::checkBlank() {
    if (cellCleared == 4)  {
        return true;
    } else {
        return false;
    }
}

// void Block::notify() {
//     if (!(cell1->getiffilled())) {
//         cell1 = nullptr;
//     }
//     if (!(cell2->getiffilled())) {
//         cell2 = nullptr;
//     }
//     if (!(cell3->getiffilled())) {
//         cell3 = nullptr;
//     }
//     if (!(cell4->getiffilled())) {
//         cell4 = nullptr;
//     }
//     if (checkBlank() == true)  {
//         notifyObservers();
//         delete this;
//     }
// }

// void Block::notify() {
//     cellCleared++;
//     // if (cellCleared == 4) {
//         // notifyObservers();
//         // delete this;
//     // }
// }

