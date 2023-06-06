#include "../../constants.h"

#ifndef Tile_h
#define Tile_h

class Tile
{
private:
  Shape shape;
  Color color;

public:
  // Constructeurs
  Tile();
  Tile(Shape _shape, Color _color);

  // Accesseurs
  Color getColor() const;
  Shape getShape() const;

  // Mutateurs
  void setColor(Color _color);
  void setShape(Shape _shape);
};

#endif