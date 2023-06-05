#include "helper.h"
#include "../box/box.h"
#include "../../constants.h"
#include <stdexcept>
#include <iostream>

bool isAnEdge(int x, int y)
{
    if (x == 0 ||
        x == (BOARD_SIZE - 1) ||
        y == 0 ||
        y == (BOARD_SIZE - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool addOneWall(Box (*boxBoard)[BOARD_SIZE], Direction dir, int x, int y)
{
    if (x > (BOARD_SIZE - 1) ||
        y > (BOARD_SIZE - 1) ||
        x < 0 ||
        y < 0)
    {
        // Did fail because x or y was not in range...
        return false;
    }

    switch (dir)
    {
    case eBottom:
        boxBoard[x][y].setWall(eBottom);
        // We add the touching wall, if it is not a border box
        if (x < (BOARD_SIZE - 1))
        {
            boxBoard[x + 1][y].setWall(eTop);
        }
        break;
    case eTop:
        boxBoard[x][y].setWall(eTop);
        // We add the touching wall, if it is not a border box
        if (x > 0)
        {
            boxBoard[x - 1][y].setWall(eBottom);
        }
        break;
    case eRight:
        boxBoard[x][y].setWall(eRight);
        // We add the touching wall, if it is not a border box
        if (y < (BOARD_SIZE - 1))
        {
            boxBoard[x][y + 1].setWall(eLeft);
        }
        break;
    case eLeft:
        boxBoard[x][y].setWall(eLeft);
        // We add the touching wall, if it is not a border box
        if (y > 0)
        {
            boxBoard[x][y - 1].setWall(eRight);
        }
        break;
    default:
        std::runtime_error("[Board, \"addOneWall\"] Direction input is wrong");
        break;
    }

    return true;
}

bool addCorner(Box (*boxBoard)[BOARD_SIZE], int x, int y, cornerType cornerT, bool override)
{
    switch (cornerT)
    {
    case eTL:
        return addTLCorner(boxBoard, x, y, override);
        break;
    case eTR:
        return addTRCorner(boxBoard, x, y, override);
        break;
    case eBL:
        return addBLCorner(boxBoard, x, y, override);
        break;
    case eBR:
        return addBRCorner(boxBoard, x, y, override);
        break;
    default:
        break;
    }
}

bool addTLCorner(Box (*boxBoard)[BOARD_SIZE], int x, int y, bool override)
{
    // Edge is an easy case : we can't add a corner here without creating a "trap"
    if (isAnEdge(x, y))
        return false;

    // If there is already an edge of this type here
    if (boxBoard[x][y].getCorner() == eTL)
        return false;

    if (!override)
    {
        for (int i = (x - 1); i <= (x + 1); i++)
        {
            for (int j = (y - 1); j <= (y + 1); j++)
            {
                if (boxBoard[i][j].getCorner() != eNoCorner)
                {
                    return false;
                }
            }
        }
    }

    // Box topBox = boxBoard[x - 1][y];
    // Box bottomBox = boxBoard[x + 1][y];
    // Box leftBox = boxBoard[x][y - 1];
    // Box rightBox = boxBoard[x][y + 1];

    // if (leftBox.willExceedTwoWalls(eTL) ||
    //     rightBox.willExceedTwoWalls(eTL) ||
    //     topBox.willExceedTwoWalls(eTL) ||
    //     bottomBox.willExceedTwoWalls(eTL))
    //     return false;

    // if (leftBox.getCorner() == eTR ||
    //     leftBox.getCorner() == eBR)
    //     return false;

    // if (topBox.getCorner() == eBL ||
    //     topBox.getCorner() == eBR)
    //     return false;

    // if (!(rightBox.getCorner() == eBR ||
    //       rightBox.getCorner() == eNoCorner))
    //     return false;

    // if (!(bottomBox.getCorner() == eBR ||
    //       bottomBox.getCorner() == eNoCorner))
    //     return false;

    boxBoard[x][y].setCorner(eTL);
    // Add walls to the current box
    // The shared wall are updated as well
    addOneWall(boxBoard, eTop, x, y);
    addOneWall(boxBoard, eLeft, x, y);
    return true;
}

bool addTRCorner(Box (*boxBoard)[BOARD_SIZE], int x, int y, bool override)
{
    if (isAnEdge(x, y))
        return false;

    // If there is already an edge of this type here
    if (boxBoard[x][y].getCorner() == eTR)
        return false;

    if (!override)
    {
        for (int i = (x - 1); i <= (x + 1); i++)
        {
            for (int j = (y - 1); j <= (y + 1); j++)
            {
                if (boxBoard[i][j].getCorner() != eNoCorner)
                {
                    return false;
                }
            }
        }
    }

    // Box topBox = boxBoard[x - 1][y];
    // Box bottomBox = boxBoard[x + 1][y];
    // Box leftBox = boxBoard[x][y - 1];
    // Box rightBox = boxBoard[x][y + 1];
    // Box topRightBox = boxBoard[x - 1][y + 1];

    // if (rightBox.getCorner() == eTL ||
    //     rightBox.getCorner() == eBL)
    //     return false;

    // if (topBox.getCorner() == eBL ||
    //     topBox.getCorner() == eBR)
    //     return false;

    // if (topRightBox.getCorner() == eBL)
    //     return false;

    // if (leftBox.getCorner() != (eBL || eNoCorner))
    //     return false;

    // if (bottomBox.getCorner() != (eBL || eNoCorner))
    //     return false;

    boxBoard[x][y].setCorner(eTR);
    // Add walls to the current box
    // The shared wall are updated as well
    addOneWall(boxBoard, eTop, x, y);
    addOneWall(boxBoard, eRight, x, y);
    return true;
}

bool addBRCorner(Box (*boxBoard)[BOARD_SIZE], int x, int y, bool override)
{
    if (isAnEdge(x, y))
        return false;

    // If there is already an edge of this type here
    if (boxBoard[x][y].getCorner() == eBR)
        return false;

    if (!override)
    {
        for (int i = (x - 1); i <= (x + 1); i++)
        {
            for (int j = (y - 1); j <= (y + 1); j++)
            {
                if (boxBoard[i][j].getCorner() != eNoCorner)
                {
                    return false;
                }
            }
        }
    }

    // Box topBox = boxBoard[x - 1][y];
    // Box bottomBox = boxBoard[x + 1][y];
    // Box leftBox = boxBoard[x][y - 1];
    // Box rightBox = boxBoard[x][y + 1];
    // Box bottomRightBox = boxBoard[x + 1][y + 1];

    // if (rightBox.getCorner() == eTL ||
    //     rightBox.getCorner() == eBL)
    //     return false;

    // if (bottomBox.getCorner() == eTL ||
    //     bottomBox.getCorner() == eTR)
    //     return false;

    // if (bottomRightBox.getCorner() == eTL)
    //     return false;

    // if (topBox.getCorner() != (eTL || eNoCorner))
    //     return false;

    // if (leftBox.getCorner() != (eTL || eNoCorner))
    //     return false;

    boxBoard[x][y].setCorner(eBR);
    // Add walls to the current box
    // The shared wall are updated as well
    addOneWall(boxBoard, eBottom, x, y);
    addOneWall(boxBoard, eRight, x, y);
    return true;
}

bool addBLCorner(Box (*boxBoard)[BOARD_SIZE], int x, int y, bool override)
{
    if (isAnEdge(x, y))
        return false;

    // If there is already an edge of this type here
    if (boxBoard[x][y].getCorner() == eBL)
        return false;

    if (!override)
    {
        for (int i = (x - 1); i <= (x + 1); i++)
        {
            for (int j = (y - 1); j <= (y + 1); j++)
            {
                if (boxBoard[i][j].getCorner() != eNoCorner)
                {
                    return false;
                }
            }
        }
    }

    // Box topBox = boxBoard[x - 1][y];
    // Box bottomBox = boxBoard[x + 1][y];
    // Box leftBox = boxBoard[x][y - 1];
    // Box rightBox = boxBoard[x][y + 1];
    // Box bottomLeftBox = boxBoard[x + 1][y + 1];

    // if (leftBox.getCorner() == eTR ||
    //     leftBox.getCorner() == eBR)
    //     return false;

    // if (bottomBox.getCorner() == eTL ||
    //     bottomBox.getCorner() == eTR)
    //     return false;

    // if (bottomLeftBox.getCorner() == eTR)
    //     return false;

    // if (rightBox.getCorner() == (eNoCorner || eTR))
    //     return false;

    // if (topBox.getCorner() == (eNoCorner || eTR))
    //     return false;

    boxBoard[x][y].setCorner(eBL);
    // Add walls to the current box
    // The shared wall are updated as well
    addOneWall(boxBoard, eBottom, x, y);
    addOneWall(boxBoard, eLeft, x, y);
    return true;
}