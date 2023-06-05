#include <iostream>
#include <cassert>
#include "Position.h"

using namespace std;

// Constructeurs
Position::Position(){
  this->x = 0;
  this->y = 0;
}
Position::Position(int _x, int _y){
  this->x = _x;
  this->y = _y;
}

//Accesseurs
int Position::getX(){
  return this->x;
}
int Position::getY(){
  return this->y;
}

// Mutateurs
void Position::setX(int _x){
  assert(_x >= 0 && _x <= 16);
  this->x = _x;
}
void Position::setY(int _y){
  assert(_y >= 0 && _y <= 16);
  this->y = _y;
}