#include "block.h"

#include <iostream>

Block::Block(int shape, Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4): cell1{cell1}, cell2{cell2}, cell3{cell3}, cell4{cell4} { }

Block::~Block() {}