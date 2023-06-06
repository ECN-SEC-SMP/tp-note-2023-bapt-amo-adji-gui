#include <iostream>
#include <cassert>
#include "Tile.h"
#include "../../constants.h"

using namespace std;

Tile::Tile()
{
    this->shape = Shape(0);
    this->color = Color(0);
}

Tile::Tile(Shape _shape, Color _color)
{
    this->shape = _shape;
    this->color = _color;
}

Shape Tile::getShape() const
{
    return shape;
}

void Tile::setShape(Shape _shape)
{
    this->shape = _shape;
}

Color Tile::getColor() const
{
    return this->color;
}

void Tile::setColor(Color _color)
{
    this->color = _color;
}