/***************Includes****************/
#include "tests/tests.h"
#include "class/board/board.h"
#include <iostream>

using namespace std;

/***************Constants***************/
/***************Defines*****************/
/***************Enums*******************/
/***************Class*******************/

int main(void)
{
    tests();
    Board board = Board();
    board.renderDebugBoard();
}
