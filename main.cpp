/***************Includes****************/
#include "class/board/board.h"
#include "class/gameController/gameController.h"
#include "tests/tests.h"
#include <iostream>

using namespace std;

/***************Constants***************/
/***************Defines*****************/
/***************Enums*******************/
/***************Class*******************/

int main(void) {
  cout << "******Running the tests******" << endl;
  tests();

  cout << "******Running the gameController******" << endl;
  gameController gC = gameController();

  cout << "******Displaying the debug board******" << endl;
  Board board = Board();
  board.renderDebugBoard();
}
