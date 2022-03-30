#include "block.h"

#include <iostream>

Block::Block(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): cell1{cell1}, cell2{cell2}, cell3{cell3}, cell4{cell4} { }

int Block::getType() {
    return this->type;
}

Block::~Block() {}

IBlock::IBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block(cell1, cell2, cell3, cell4) { }

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



IBlock::~IBlock() {}

JBlock::JBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block(cell1, cell2, cell3, cell4) { }

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

JBlock::~JBlock() {}

LBlock::LBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block(cell1, cell2, cell3, cell4) { }

LBlock::~LBlock() {}

OBlock::OBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block(cell1, cell2, cell3, cell4) { }

OBlock::~OBlock() {}

SBlock::SBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block(cell1, cell2, cell3, cell4) { }

SBlock::~SBlock() {}

ZBlock::ZBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block(cell1, cell2, cell3, cell4) { }

ZBlock::~ZBlock() {}

TBlock::TBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block(cell1, cell2, cell3, cell4) { }

TBlock::~TBlock() {}










char Block::getc() {
    return c;
}

