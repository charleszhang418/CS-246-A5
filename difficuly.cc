#include"difficulty.h"
#include <iostream>
#include <string>

Difficulty::~Difficulty() { }

Level::Level(Difficulty* diff): diff{diff} { }

Level::~Level() { 
    delete this->diff;
}

Block* block Level::getblock(Block* block) { }

Level0::Level0(Difficulty* diff): Level{diff} { }

Level0::~Level0() { }

Block* block Level0::getblock(Block* block) { 
    return block;
}

Level1::Level1(Difficulty* diff) Level{diff} { }

Level1::~Level1() { }

Block* block Level1::getblock(Block* block) { 
    return block;
}

Level2::Level2(Difficulty* diff): Level{diff} { }

Level2::~Level2() { }

Block* block Level2::getblock(Block* block) { 
     return block;
}

Level3::Level3(Difficulty* diff): Level{diff} { }

Level3::~Level3() { }

Block* block Level3::getblock(Block* block) { 
    if (block->cell1->iffilled)
}

Level4::Level4(Difficulty* diff): Level{diff} { }

Level4::~Level4() { }

Block* block Level4::getblock(Block* block) { }

ActionHeavy::ActionHeavy(Difficulty* diff): Level{diff} {}

ActionHeavy::~ActionHeavy() {}

Block* block ActionHeavy::getblock(Block* block) { }
