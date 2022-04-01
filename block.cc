#include "block.h"

#include <iostream>

using namespace std;


void Block::erasetype(bool clock) {
    if (clock) {
        if (type == 4) {
            type = 0;
        } else {
            type++;
        }
    } else {
        if (type == 0) {
            type = 4;
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
}

void Block::updateBlockDifficulty(Difficulty* diff) {
    this->diff = diff;
}

int Block::getLevel() {
    return this->diff->getWeight();
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


Block::Block(Difficulty* diff, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): diff{diff}, cell1{cell1}, cell2{cell2}, cell3{cell3}, cell4{cell4} { }

int Block::getType() {
    return this->type;
}

Block::~Block() {}

IBlock::IBlock(Difficulty* diff, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block{diff, cell1, cell2, cell3, cell4} { 
    this->updateCellState();
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

void IBlock::updateCellState() {
    cell1->eraseIffilled(true);
    cell2->eraseIffilled(true);
    cell3->eraseIffilled(true);
    cell4->eraseIffilled(true);
    cell1->eraseValue(this->c);
    cell2->eraseValue(this->c);
    cell3->eraseValue(this->c);
    cell4->eraseValue(this->c);
}

IBlock::~IBlock() {}

JBlock::JBlock(Difficulty* diff, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block{diff, cell1, cell2, cell3, cell4} { 
    this->updateCellState();
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

void JBlock::updateCellState() {
    cell1->eraseIffilled(true);
    cell2->eraseIffilled(true);
    cell3->eraseIffilled(true);
    cell4->eraseIffilled(true);
    cell1->eraseValue(this->c);
    cell2->eraseValue(this->c);
    cell3->eraseValue(this->c);
    cell4->eraseValue(this->c);
}

JBlock::~JBlock() {}

LBlock::LBlock(Difficulty* diff, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block{diff, cell1, cell2, cell3, cell4} { 
    this->updateCellState();
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

void LBlock::updateCellState() {
    cell1->eraseIffilled(true);
    cell2->eraseIffilled(true);
    cell3->eraseIffilled(true);
    cell4->eraseIffilled(true);
    cell1->eraseValue(this->c);
    cell2->eraseValue(this->c);
    cell3->eraseValue(this->c);
    cell4->eraseValue(this->c);
}

LBlock::~LBlock() {}

OBlock::OBlock(Difficulty* diff, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block{diff, cell1, cell2, cell3, cell4} { 
    this->updateCellState();
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

void OBlock::updateCellState() {
    cell1->eraseIffilled(true);
    cell2->eraseIffilled(true);
    cell3->eraseIffilled(true);
    cell4->eraseIffilled(true);
    cell1->eraseValue(this->c);
    cell2->eraseValue(this->c);
    cell3->eraseValue(this->c);
    cell4->eraseValue(this->c);
}

OBlock::~OBlock() {}

SBlock::SBlock(Difficulty* diff, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block{diff, cell1, cell2, cell3, cell4} { 
    this->updateCellState();
}

char SBlock::getChar() {
    return this->c;
}

std::vector<std::vector<int>> SBlock::rotate(bool clockwise) {
    std::vector<std::vector<int>> result;
    if (((this->type == 0) || (this->type == 2)) && (clockwise)) {
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

void SBlock::updateCellState() {
    cell1->eraseIffilled(true);
    cell2->eraseIffilled(true);
    cell3->eraseIffilled(true);
    cell4->eraseIffilled(true);
    cell1->eraseValue(this->c);
    cell2->eraseValue(this->c);
    cell3->eraseValue(this->c);
    cell4->eraseValue(this->c);
}

SBlock::~SBlock() {}

ZBlock::ZBlock(Difficulty* diff, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block{diff, cell1, cell2, cell3, cell4} { 
    this->updateCellState();
}

char ZBlock::getChar() {
    return this->c;
}

std::vector<std::vector<int>> ZBlock::rotate(bool clockwise) {
    std::vector<std::vector<int>> result;
    if (((this->type == 0) || (this->type == 2)) && (clockwise)) {
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

void ZBlock::updateCellState() {
    cell1->eraseIffilled(true);
    cell2->eraseIffilled(true);
    cell3->eraseIffilled(true);
    cell4->eraseIffilled(true);
    cell1->eraseValue(this->c);
    cell2->eraseValue(this->c);
    cell3->eraseValue(this->c);
    cell4->eraseValue(this->c);
}

ZBlock::~ZBlock() {}

TBlock::TBlock(Difficulty* diff, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block{diff, cell1, cell2, cell3, cell4} { 
    this->updateCellState();
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
        v2.emplace_back(this->cell2->getcol());
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
        v1.emplace_back(this->cell1->getrow() - 1);
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

void TBlock::updateCellState() {
    cell1->eraseIffilled(true);
    cell2->eraseIffilled(true);
    cell3->eraseIffilled(true);
    cell4->eraseIffilled(true);
    cell1->eraseValue(this->c);
    cell2->eraseValue(this->c);
    cell3->eraseValue(this->c);
    cell4->eraseValue(this->c);
}

TBlock::~TBlock() {}

