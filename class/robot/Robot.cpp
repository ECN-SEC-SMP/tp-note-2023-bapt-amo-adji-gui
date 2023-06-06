#include <iostream>
#include <cassert>
#include "Robot.h"
#include "../../constants.h"

#ifndef _ROBOT_H_
#define _ROBOT_H_

Robot::Robot()
{
  this->color = Color(0);
}

Robot::Robot(Color _color)
{
  this->color = _color;
}

Color Robot::getColor() const
{
  return this->color;
}

void Robot::setColor(Color color)
{
  this->color = color;
}

#endif