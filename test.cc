#include "textoutput.h"

#include <iostream>

using namespace std;

int main() {
    Board *board1 = new Board{11, 18, 0};
    Board *board2 = new Board{11, 18, 0};
    TextOutput t{11, 18, board1, board2};
    return 1;
}