#include "../../constants.h"

#ifndef Robot_h
#define Robot_h

class Robot
{
private:
  Color color;

public:
  // Constructeurs
  Robot();
  Robot(Color _color);

  // Accesseurs
  Color getColor() const;

  // Mutateurs
  void setColor(Color _color);
  void setShape(Shape _shape);
};

#endif