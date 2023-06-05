#include <iostream>
#ifndef Position_h
#define Position_h

using namespace std;

class Position {
  private :
    int x;
    int y;

  public :
    // Constructeurs
    Position();
    Position(int _x, int _y);

    // Accesseurs
    int getX();
    int getY();

    //Mutateurs
    void setX(int _x);
    void setY(int _y);

};

#endif