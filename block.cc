#include "block.h"

#include <iostream>

Block::Block(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): cell1{cell1}, cell2{cell2}, cell3{cell3}, cell4{cell4} { }

Block::~Block() {}

IBlock::IBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block(cell1, cell2, cell3, cell4) { }

IBlock::~IBlock() {}

JBlock::JBlock(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): Block(cell1, cell2, cell3, cell4) { }

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