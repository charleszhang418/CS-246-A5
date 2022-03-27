#include"difficulty.h"
#include <iostream>
#include <string>

Difficulty::~Difficulty() { }

Level::Level(Difficulty* diff): diff{diff} { }

Level::~Level() { 
    delete this->diff;
}

std::string Level::getblock() { }

Level0::Level0(Difficulty* diff): Level{diff} { }

Level0::~Level0() { }

std::string Level0::getblock() { }

Level1::Level1(Difficulty* diff): Level{diff} { }

Level1::~Level1() { }

std::string Level1::getblock() { }

Level2::Level2(Difficulty* diff): Level{diff} { }

Level2::~Level2() { }

std::string Level2::getblock() { }

Level3::Level3(Difficulty* diff): Level{diff} { }

Level3::~Level3() { }

std::string Level3::getblock() { }

Level4::Level4(Difficulty* diff): Level{diff} { }

Level4::~Level4() { }

std::string Level4::getblock() { }

ActionHeavy::ActionHeavy(Difficulty* diff): Level{diff} {}

ActionHeavy::~ActionHeavy() {}

std::string ActionHeavy::getblock() { }
