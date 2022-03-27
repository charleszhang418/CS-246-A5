#include"difficulty.h"
#include <iostream>
#include <string>

Difficulty::~Difficulty() { }

Level::Level(Difficulty* diff): diff{diff} {
    
}

Level::~Level() { 
    delete this->diff;
}

std::string Level::getblock() { }
