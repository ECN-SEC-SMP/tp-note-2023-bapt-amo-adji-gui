#include <cassert>
#include <iostream>

#include "tests.h"

using namespace std;

/* Format to use for tests*/
// Test class X
// void testX(){
//     X x = X()
//     int result = X.add(4, 6)
//     cout << "Resultat addition:" << result << "\n"
// }
/* Format to use for tests*/

void tests() {
  test_robot();
  test_shape();
  test_player();
}

void test_robot() {
  Robot robot1; // Default constructor
  // Assert color is right
  assert(robot1.getColor() == eBlue);
  // Assert color is right once setted
  robot1.setColor(eRed);
  assert(robot1.getColor() == eRed);

  Robot robot2(eGreen); // Constructor with parameters
  // Assert color is right when using constructor with parameters
  assert(robot2.getColor() == eGreen);

  std::cout << "Robot: All tests succeded" << std::endl;
}

void test_shape() {
  Tile tile1; // Default constructor
  assert(tile1.getShape() == eTriangle);
  assert(tile1.getColor() == eBlue);

  tile1.setShape(eCircle);
  tile1.setColor(eRed);
  // Assert shape and color are rights once setted
  assert(tile1.getShape() == eCircle);
  assert(tile1.getColor() == eRed);

  Tile tile2(eStar, eRed);
  assert(tile2.getShape() == eStar);
  assert(tile2.getColor() == eRed);

  std::cout << "Tile: All tests succeded" << std::endl;
}

/**
 * @brief Test the player fonction
 *
 * @details This fonction create a player call p1,
 *          print all the information on the player,
 *          change the value of player atribute and print them all again,
 *          reset all the attribut and print them all.
 */
void test_player() {
  Player p1; // joueur 1

  // Affichage des coordonnées initiales
  cout << "Player 1 name is " << p1.getName() << endl;
  cout << "Total moves are: " << p1.getTotalMove() << endl;
  cout << "Total announced moved are:" << p1.getAnnouncedMove() << endl;
  cout << "Point number are: " << p1.getPoint() << endl;

  cout << "-->Adding 1 move, point and getting announced move" << endl;
  // Modification des mouvement
  p1.addMove();
  p1.setAnnouncedMove();
  p1.addPoint();

  cout << "Player 1 name is " << p1.getName() << endl;
  cout << "Total moves are: " << p1.getTotalMove() << endl;
  cout << "Total announced moved are:" << p1.getAnnouncedMove() << endl;
  cout << "Point number are: " << p1.getPoint() << endl;

  // Reset des mouvements
  p1.resetMove();
  p1.resetAnnouncedMove();
  p1.resetPoint();

  cout << "-->Resetting everything" << endl;
  // Affichage des mouvement resest
  cout << "Player 1 name is " << p1.getName() << endl;
  cout << "Total moves are: " << p1.getTotalMove() << endl;
  cout << "Total announced moved are:" << p1.getAnnouncedMove() << endl;
  cout << "Point number are: " << p1.getPoint() << endl;
}
