#include <stdexcept>
#include "box.h"

Box::Box()
{
    for (int i = 0; i < 4; i++)
    {
        this->walls[i] = false;
    }

    this->corner = eNoCorner;
    this->robot = nullptr;
    this->tile = nullptr;
}

bool Box::getWall(Direction dir) const
{
    return this->walls[dir];
}

Robot *Box::getRobot() const
{
    if (!(this->hasRobot()))
    {
        throw std::runtime_error("[Box, \"getRobot\"] Getting robot while there are none");
    }
    else
    {
        return robot;
    }
}

Tile *Box::getTile() const
{
    if (!(this->hasTile()))
    {
        throw std::runtime_error("[Box, \"getTile\"] Getting tile while there are none");
    }
    else
    {
        return tile;
    }
}

cornerType Box::getCorner()
{
    if ((this->corner == eNoCorner))
    {
        if (walls[eTop] &&
            walls[eLeft])
        {
            this->corner = eTL;
        }
        else if (walls[eTop] &&
                 walls[eRight])
        {
            this->corner = eTR;
        }
        else if (walls[eBottom] &&
                 walls[eLeft])
        {
            this->corner = eBL;
        }
        else if (walls[eBottom] &&
                 walls[eRight])
        {
            this->corner = eBR;
        }
    }
    return this->corner;
}

void Box::setWall(Direction dir)
{
    this->walls[dir] = WALL;
}

void Box::setRobot(Robot *_robot)
{
    this->robot = _robot;
}

void Box::setTile(Tile *_tile)
{
    this->tile = _tile;
}

void Box::setCorner(cornerType cornerT)
{

    this->corner = cornerT;
}

bool Box::hasRobot() const
{
    if (robot == nullptr)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

bool Box::hasTile() const
{
    if (tile == nullptr)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

bool Box::canGoToNextBox(Direction dir) const
{
    if (this->walls[dir] == WALL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Box::hasReachGoal() const
{
    if (hasRobot() && hasTile())
    {
        Robot currentRobot = *this->robot;
        Tile currentTile = *this->tile;
        if (((currentRobot.getColor() == currentTile.getColor()) || (eMulticolor == tile->getColor())) &&
            currentTile.isGoal())
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

bool Box::willExceedTwoWalls(cornerType cornerT)
{
    cornerType currentCorner = this->getCorner();
    if (currentCorner == eNoCorner)
    {
        return false;
    }
    return (cornerT != currentCorner);
}
