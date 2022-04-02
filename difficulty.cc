#include "difficulty.h"
#include <iostream>
#include <string>

int Difficulty::getWeight() {
    return 0;
}
std::vector<std::vector<int>> Difficulty::getalllocation() { }
void Difficulty::clearCellState() { }
void Difficulty::eraseallcell(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4) { }
void Difficulty::updateCellState() { }
std::vector<std::vector<int>> Difficulty::displayNext() { }

Difficulty::~Difficulty() { }

Level::Level(Difficulty* diff): diff{diff} { }

Level::~Level() { 
    delete this->diff;
}

// int Level::getWeight() {
    
//     return 0;
// }

Level0::Level0(Difficulty* diff): Level{diff} { }

Level0::~Level0() { }

int Level0::getWeight() {
    return 0;
}
    

Level1::Level1(Difficulty* diff): Level{diff} { }

Level1::~Level1() { }

int Level1::getWeight() { 
    return diff->getWeight();
}

Level2::Level2(Difficulty* diff): Level{diff} { }

Level2::~Level2() { }

int Level2::getWeight() { 
    return diff->getWeight();
}

Level3::Level3(Difficulty* diff): Level{diff} { }

Level3::~Level3() { }

int Level3::getWeight() { 
    return 1 + diff->getWeight();
}

Level4::Level4(Difficulty* diff): Level{diff} { }

Level4::~Level4() { }

int Level4::getWeight() {
    return diff->getWeight();
}

ActionHeavy::ActionHeavy(Difficulty* diff): Level{diff} {}

ActionHeavy::~ActionHeavy() {}

int ActionHeavy::getWeight() {
   return 2 + diff->getWeight();
}
