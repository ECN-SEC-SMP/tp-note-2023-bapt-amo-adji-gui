#include <iostream>
#include "../Position.h"

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
  pos1.setY(17); //Assertion (error du programme)
  pos2.setX(15);
  pos2.setY(12);

  // Affichage des coordonnées modifiées
  cout << "Position 1 : x = " << pos1.getX() << ", y = " << pos1.getY() << endl;
  cout << "Position 2 : x = " << pos2.getX() << ", y = " << pos2.getY() << endl;

  /* Format to use for tests*/
}

int main(void)
{
  /* Format to use for tests*/
  // testX();
  /* Format to use for tests*/

  test_position();
}

