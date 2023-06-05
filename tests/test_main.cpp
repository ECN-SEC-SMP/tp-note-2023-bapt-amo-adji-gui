#include <iostream>
#include <cassert>
#include "../Position.h"
#include "../Robot.h"
#include "../Tile.h"

using namespace std;

/* Format to use for tests*/
// Test class X
// void testX(){
//     X x = X()
//     int result = X.add(4, 6)
//     cout << "Resultat addition:" << result << "\n"
// }
/* Format to use for tests*/

void test_position(){
  /* Format to use for tests*/
  
  Position pos1; // Utilisation du constructeur par défaut
  Position pos2(10, 5); // Utilisation du constructeur avec paramètres

  // Affichage des coordonnées initiales
  cout << "Position 1 : x = " << pos1.getX() << ", y = " <<   pos1.getY() << endl;
  cout << "Position 2 : x = " << pos2.getX() << ", y = " <<   pos2.getY() << endl;

  // Modification des coordonnées
  pos1.setX(3);
  //pos1.setY(17); //Assertion (error du programme)
  pos2.setX(15);
  pos2.setY(12);

  // Affichage des coordonnées modifiées
  cout << "Position 1 : x = " << pos1.getX() << ", y = " << pos1.getY() << endl;
  cout << "Position 2 : x = " << pos2.getX() << ", y = " << pos2.getY() << endl;

  /* Format to use for tests*/
}

void test_robot(){
/* Format to use for tests*/

  Robot robot1; // Utilisation du constructeur par défaut
  robot1.setColor(eRed);
  robot1.setPosition(10, 15);

  std::cout << "Robot 1 - Color: " << robot1.getColor() << std::endl;
  std::cout << "Robot 1 - Position: (" << robot1.getPosition().getX() << ", " <<     robot1.getPosition().getY() << ")" << std::endl;

  Robot robot2(5, 5); // Utilisation du constructeur avec des coordonnées
  robot2.setColor(eGreen);
  robot2.setPosition(15, 15);

  std::cout << "Robot 2 - Color: " << robot2.getColor() << std::endl;
  std::cout << "Robot 2 - Position: (" << robot2.getPosition().getX() << ", " << robot2.getPosition().getY() << ")" << std::endl;
  
/* Format to use for tests*/
}
void test_shape(){
  /* Format to use for tests*/
  
  // Création d'une tuile et vérification de la forme
  Tile tile;
  assert(tile.getShape() == eTriangle);

  // Modification de la forme de la tuile et vérification
  tile.setShape(eCircle);
  assert(tile.getShape() == eCircle);

  // Création d'un robot et vérification de la couleur
  Robot robot;
  assert(robot.getColor() == eBlue);

  // Modification de la couleur du robot et vérification
  robot.setColor(eRed);
  assert(robot.getColor() == eRed);

  // Définition de la position du robot et vérification des coordonnées
  robot.setPosition(5, 10);
  Position position = robot.getPosition();
  assert(position.getX() == 5);
  assert(position.getY() == 10);

  std::cout << "Tous les tests ont réussi !" << std::endl;
  
  /* Format to use for tests*/
}

int main(void)
{
  /* Format to use for tests*/
  // testX();
  /* Format to use for tests*/

  //test_position();
  //test_robot();
  test_shape();
}

