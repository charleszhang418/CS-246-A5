#include "difficulty.h"
#include <iostream>
#include <string>

int Difficulty::getWeight() {
    return 0;
}



Difficulty::~Difficulty() { }

Level::Level(Difficulty* diff): diff{diff} { }

std::vector<std::vector<int>> Level::getalllocation() { 
    return diff->getalllocation();
}

void Level::clearCellState() { 
    diff->clearCellState();
}

void Level::eraseallcell(Cell* cell1, Cell* cell2, Cell* cell3, Cell* cell4) {
    diff->eraseallcell(cell1, cell2, cell3, cell4);
}

void Level::updateCellState(Difficulty* diff) { 
    this->diff->updateCellState(diff);
}

std::vector<std::vector<int>> Level::displayNext() { 
    return diff->displayNext();
}
std::vector<std::vector<int>> Level::rotate(bool clockwise) {
    return diff->rotate(clockwise);
}

char Level::getChar() {
    return diff->getChar();
}

void Level::erasetype(bool clock) {
    return diff->erasetype(clock);
}

Level::~Level() { 
    delete diff;
}

bool Level::checkBlank() {
    return diff->checkBlank();
}

int Level::getLevel() {
    return diff->getLevel();
}

//  void Level::notify() {
//      diff->notify();
//  }

// int Level::getWeight() {
    
//     return 0;
// }

void Level::updateCellCleared() {
    diff->updateCellCleared();
}


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



