#include <iostream>
#include "../Position.h"
#include "../Robot.h"

using namespace std;

/* Format to use for tests*/
// Test class X
// void testX(){
//     X x = X()
//     int result = X.add(4, 6)
//     cout << "Resultat addition:" << result << "\n"
// }
/* Format to use for tests*/

/* Format to use for tests*/
// testX();s
/* Format to use for tests*/

void test_position(void);
void test_robot(void);

int main(void)
{
  /* Format to use for tests*/
  // testX();
  /* Format to use for tests*/

  // test_position();
  // test_robot();
}

void test_position()
{
  /* Format to use for tests*/

  Position pos1;        // Utilisation du constructeur par défaut
  Position pos2(10, 5); // Utilisation du constructeur avec paramètres

  // Affichage des coordonnées initiales
  cout << "Position 1 : x = " << pos1.getX() << ", y = " << pos1.getY() << endl;
  cout << "Position 2 : x = " << pos2.getX() << ", y = " << pos2.getY() << endl;

  // Modification des coordonnées
  pos1.setX(3);
  // pos1.setY(17); //Assertion (error du programme)
  pos2.setX(15);
  pos2.setY(12);

  // Affichage des coordonnées modifiées
  cout << "Position 1 : x = " << pos1.getX() << ", y = " << pos1.getY() << endl;
  cout << "Position 2 : x = " << pos2.getX() << ", y = " << pos2.getY() << endl;

  /* Format to use for tests*/
}

void test_robot()
{
  /* Format to use for tests*/

  Robot robot1; // Utilisation du constructeur par défaut
  robot1.setColor(eRed);
  robot1.setPosition(10, 15);

  std::cout << "Robot 1 - Color: " << robot1.getColor() << std::endl;
  std::cout << "Robot 1 - Position: (" << robot1.getPosition().getX() << ", " << robot1.getPosition().getY() << ")" << std::endl;

  Robot robot2(5, 5); // Utilisation du constructeur avec des coordonnées
  robot2.setColor(eGreen);
  robot2.setPosition(15, 15);

  std::cout << "Robot 2 - Color: " << robot2.getColor() << std::endl;
  std::cout << "Robot 2 - Position: (" << robot2.getPosition().getX() << ", " << robot2.getPosition().getY() << ")" << std::endl;

  /* Format to use for tests*/
}
