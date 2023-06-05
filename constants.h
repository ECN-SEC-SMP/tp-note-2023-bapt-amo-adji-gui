#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#define BOARD_SIZE 16
#define WALL true

enum Shape
{
    eTriangle = 0,
    eSquare = 1,
    eCircle = 2,
    eStar = 3,
};

enum cornerType
{
    eNoCorner = -1,
    eTL = 0,
    eTR,
    eBL,
    eBR,
};

enum Color
{
    eBlue = 0,
    eRed = 1,
    eYellow = 2,
    eGreen = 3,
    eMulticolor = 4,
};

enum Direction
{
    eTop = 0,
    eBottom,
    eLeft,
    eRight,
    eDirSize,
};

#endif