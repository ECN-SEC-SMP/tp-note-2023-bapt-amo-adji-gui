#ifndef _BOX_H_
#define _BOX_H_

#include "../../constants.h"
#include "../../constants.h"
#include "../robot/Robot.h"
#include "../tile/Tile.h"

class Box
{

private:
    bool walls[eDirSize];
    cornerType corner;
    Robot *robot;
    Tile *tile;

public:
    // Constructor
    Box();

    // Getters
    bool getWall(Direction dir) const;
    Robot *getRobot() const;
    Tile *getTile() const;
    cornerType getCorner();

    // Setters
    void setWall(Direction dir);
    void setRobot(Robot *_robot);
    void setTile(Tile *_tile);
    void setCorner(cornerType cornerT);

    // Methods
    bool hasRobot() const;
    bool hasTile() const;

    bool canGoToNextBox(Direction dir) const;
    bool hasReachGoal() const;

    bool willExceedTwoWalls(cornerType cornerT);
};

#endif