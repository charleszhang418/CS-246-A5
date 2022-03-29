#include <vector> 
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "block.h"
#include "board.h"
using namespace std;

Cell::Cell(const int& row, const int& col) : row{row}, col{col} {}