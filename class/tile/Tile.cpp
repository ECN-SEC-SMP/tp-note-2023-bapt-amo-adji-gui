#include <iostream>
#include <cassert>
#include "Tile.h"
#include "../../constants.h"

using namespace std;

Tile::Tile()
{
    this->shape = Shape(0);
    this->color = Color(0);
    this->goal = false;
}

Tile::Tile(Shape _shape, Color _color)
{
    this->shape = _shape;
    this->color = _color;
    this->goal = false;
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

void Tile::setGoal()
{
    this->goal = true;
}

bool Tile::isGoal() const
{
    return this->goal;
}