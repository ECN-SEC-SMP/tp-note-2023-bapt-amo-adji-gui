#include <stdexcept>
#include <iostream>
#include "Display.h"

using namespace std;

/**
 * @brief Print a colored smiley to represent the different robot
 *
 * @param robot
 */

void print_robot(Robot robot)
{
    if (robot.getColor() == 0)
    { // blue robot
        std::cout << "\033[1;34m☻\033[0m\n";
    }
    else if (robot.getColor() == 1)
    { // red robot
        std::cout << "\033[1;31m☻\033[0m\n";
    }
    else if (robot.getColor() == 2)
    { // yellow robot
        std::cout << "\033[1;33m☻\033[0m\n";
    }
    else if (robot.getColor() == 3)
    { // green robot
        std::cout << "\033[1;32m☻\033[0m\n";
    }
}

/**
 * @brief print a tile with the coresponding shape and color
 *
 * @param tile
 */
void print_tile(Tile tile)
{
    // Triangle tile
    if (tile.getShape() == 0)
    {
        if (tile.getColor() == 0)
        { // blue tile
            std::cout << "\033[1;34m▲\033[0m\n";
        }
        else if (tile.getColor() == 1)
        { // red tile
            std::cout << "\033[1;31m▲\033[0m\n";
        }
        else if (tile.getColor() == 2)
        { // yellow tile
            std::cout << "\033[1;33m▲\033[0m\n";
        }
        else if (tile.getColor() == 3)
        { // green tile
            std::cout << "\033[1;32m▲\033[0m\n";
        }
    }
    // Square tile
    else if (tile.getShape() == 1)
    {
        if (tile.getColor() == 0)
        { // blue tile
            std::cout << "\033[1;34m■\033[0m\n";
        }
        else if (tile.getColor() == 1)
        { // red tile
            std::cout << "\033[1;31m■\033[0m\n";
        }
        else if (tile.getColor() == 2)
        { // yellow tile
            std::cout << "\033[1;33m■\033[0m\n";
        }
        else if (tile.getColor == 3)
        { // green tile
            std::cout << "\033[1;32m■\033[0m\n";
        }
    }
    // Round tile
    else if (tile.getShape() == 2)
    {
        if (tile.getColor() == 0)
        { // blue tile
            std::cout << "\033[1;34m•\033[0m\n";
        }
        else if (tile.getColor() == 1)
        { // red tile
            std::cout << "\033[1;31m•\033[0m\n";
        }
        else if (tile.getColor() == 2)
        { // yellow tile
            std::cout << "\033[1;33m•\033[0m\n";
        }
        else if (tile.getColor() == 3)
        { // green tile
            std::cout << "\033[1;32m•\033[0m\n";
        }
    }
    // star tile
    else if (tile.getShape() == 3)
    {
        if (tile.getColor() == 0)
        { // blue tile
            std::cout << "\033[1;34m★\033[0m\n";
        }
        else if (tile.getColor() == 1)
        { // red tile
            std::cout << "\033[1;31m★\033[0m\n";
        }
        else if (tile.getColor() == 2)
        { // yellow tile
            std::cout << "\033[1;33m★\033[0m\n";
        }
        else if (tile.getColor() == 3)
        { // green tile
            std::cout << "\033[1;32m★\033[0m\n";
        }
    }
}

/**
 * @brief print the board in the shell
 *
 * @param table
 *
 * @details To print the board we print boxes line by line.
 * A box is :
 * ╔═══╗
 * ║ ☺ ║
 * ╚═══╝
 * To print any line of box we divide the line in 3.
 * First line print the top of any boxes of the line.
 * Second line print the centre part of the boxes of the line withe the tile or
 * the robot. Third line print the bottom part of the boxes if the line.
 */
void print_board(Board table)
{
    for (int i = 0; BOARD_SIZE; i++)
    {
        int k = 0;
        while (k < 3)
        {
            if (k == 0)
            {
                for (int j = 0; 15; j++)
                {
                    if (j == 0)
                    {
                        if (table[i][j].getWall(eTop) == 1 &&
                            table[i][j].getWall(eLeft) == 1 && i == 0)
                            std::cout << "╔═══";

                        else if (table[i][j].getWall(eTop) == 1 &&
                                 table[i][j].getWall(eLeft) == 1 && i != 0)
                            std::cout << "╠═══";

                        else if (table[i][j].getWall(eTop) == 0 &&
                                 table[i][j].getWall(eLeft) == 1)
                            std::cout << "║   ";

                        else
                            std::cout << "no configured (if j = 0  k = 0)";
                    }

                    else if (j == 15)
                    {
                        if (table[i][j].getWall(eTop) == 1 &&
                            table[i][j].getWall(eright) == 1 &&
                            table[i][j].getWall(eLeft) == 0 && i == 0)
                            std::cout << "═════╗" << endl;

                        else if (table[i][j].getWall(eTop) == 1 &&
                                 table[i][j].getWall(eright) == 1 &&
                                 table[i][j].getWall(eLeft) == 1 && i == 0)
                            std::cout << "╦════╗" << endl;

                        else if (table[i][j].getWall(eTop) == 1 &&
                                 table[i][j].getWall(eright) == 1 &&
                                 table[i][j].getWall(eLeft) == 0 && i != 0)
                            std::cout << " ════╣" << endl;

                        else if (table[i][j].getWall(eTop) == 0 &&
                                 table[i][j].getWall(eright) == 1 &&
                                 table[i][j].getWall(eLeft) == 0 && i != 0)
                            std::cout << "     ║" << endl;

                        else if (table[i][j].getWall(eTop) == 0 &&
                                 table[i][j].getWall(eright) == 1 &&
                                 table[i][j].getWall(eLeft) == 1 &&
                                 table[i][j - 1].getCorner() == eTL)
                            std::cout << "═    ║" << endl;

                        else if (table[i][j].getWall(eTop) == 0 &&
                                 table[i][j].getWall(eright) == 1 &&
                                 table[i][j].getWall(eLeft) == 1 &&
                                 table[i][j - 1].getCorner() == eBR)
                            std::cout << "║    ║" << endl;

                        else if (table[i][j].getWall(eTop) == 0 &&
                                 table[i][j].getWall(eright) == 1 &&
                                 table[i][j].getWall(eLeft) == 1 &&
                                 table[i][j - 1].getCorner() == eTR)
                            std::cout << "╗    ║" << endl;

                        else
                            std::cout << "no configured (if j = 15  k = 0)";
                    }
                    else
                    { // j between 1 and 14
                        if (table[i][j].getWall(eTop) == 1 &&
                            table[i][j].getWall(eright) == 0 &&
                            table[i][j].getWall(eLeft) == 0)
                            std::cout << "═════";

                        else if (table[i][j].getWall(eTop) == 1 &&
                                 (table[i][j].getWall(eright) == 1 ||
                                  table[i][j].getWall(eLeft) == 1) &&
                                 (table[i][j - 1].getCorner() != eBR ||
                                  table[i][j - 1].getCorner() != eBL))
                            std::cout << "╦════";

                        else if (table[i][j].getWall(eTop) == 0 &&
                                 table[i][j].getWall(eright) == 0 &&
                                 table[i][j].getWall(eLeft) == 0)
                            std::cout << "     ";

                        else if (table[i][j].getWall(eTop) == 0 &&
                                 (table[i][j].getWall(eright) == 1 ||
                                  table[i][j].getWall(eLeft) == 1) &&
                                 table[i][j - 1].getCorner() == eTL)
                            std::cout << "╔    ";

                        else if (table[i][j].getWall(eTop) == 0 &&
                                 (table[i][j].getWall(eright) == 1 ||
                                  table[i][j].getWall(eLeft) == 1) table[i][j - 1]
                                         .getCorner() == eTR)
                            std::cout << "╗    ";

                        else if (table[i][j].getWall(eTop) == 0 &&
                                 (table[i][j].getWall(eright) == 1 ||
                                  table[i][j].getWall(eLeft) == 1) table[i][j - 1]
                                         .getCorner() == eTR)
                            std::cout << "║    ";

                        else
                            std::cout << "no configured (if j between 1 and 14 k = 0)";
                    }
                }
            }
            else if (k == 1)
            {
                for (int j = 0; 15; j++)
                {
                    if (j == 0)
                    {
                        if (table[i][j].getWall(eLeft) == 1 ||
                            table[i][j].getWall(eRight) == 1)
                        {
                            if (table[i][j].hasRobot() == 1)
                                std::cout << "║ " << print_robot(table[i][j].getRobot()) << " ";

                            else if (table[i][j].hasRobot() == 0 &&
                                     table[i][j].hasRobot() == 1)
                                std::cout << "║ " << print_tile(table[i][j].getTile()) << " ";

                            else if (table[i][j].hasRobot() == 0 &&
                                     table[i][j].hasRobot() == 0)
                                std::cout << "║   ";
                        }
                        else if (table[i][j].getWall(eRight) == 0 &&
                                 table[i][j].getWall(eLeft) == 0)
                        {

                            if (table[i][j].hasRobot() == 1)
                                std::cout << "  " << print_robot(table[i][j].getRobot()) << " ";

                            else if (table[i][j].hasRobot() == 0 &&
                                     table[i][j].hasRobot() == 1)
                                std::cout << "  " << print_tile(table[i][j].getTile()) << " ";

                            else if (table[i][j].hasRobot() == 0 &&
                                     table[i][j].hasRobot() == 0)
                                std::cout << "    ";
                        }

                        else
                            cout << "no configured (if j = 0  k = 1)";
                    }

                    else if (j == 15)
                    {
                        if (table[i][j].getWall(eright) == 1 &&
                            table[i][j].getWall(eLeft) == 0)
                        {
                            if (table[i][j].hasRobot() == 1)
                                std::cout << "   " << print_robot(table[i][j].getRobot())
                                          << " ║" << endl;

                            else if (table[i][j].hasRobot() == 0 &&
                                     table[i][j].hasRobot() == 1)
                                std::cout << "   " << print_tile(table[i][j].getTile()) << " ║"
                                          << endl;

                            else if (table[i][j].hasRobot() == 0 &&
                                     table[i][j].hasRobot() == 0)
                                std::cout << "     ║" << endl;
                        }

                        else if (table[i][j].getWall(eright) == 1 &&
                                 table[i][j].getWall(eLeft) == 1)
                        {
                            if (table[i][j].hasRobot() == 1)
                                std::cout << "║  " << print_robot(table[i][j].getRobot())
                                          << " ║" << endl;

                            else if (table[i][j].hasRobot() == 0 &&
                                     table[i][j].hasRobot() == 1)
                                std::cout << "║  " << print_tile(table[i][j].getTile()) << " ║"
                                          << endl;

                            else if (table[i][j].hasRobot() == 0 &&
                                     table[i][j].hasRobot() == 0)
                                std::cout << "║    ║" << endl;
                        }
                        else
                            std::cout << "no configured (if j = 15 k = 1)";
                    }
                    else
                    { // j between 1 and 14
                        if (table[i][j].getWall(eright) == 0 &&
                            table[i][j].getWall(eLeft) == 0)
                        {
                            if (table[i][j].hasRobot() == 1)
                                std::cout << "  " << print_robot(table[i][j].getRobot())
                                          << "  ";

                            else if (table[i][j].hasRobot() == 0 &&
                                     table[i][j].hasRobot() == 1)
                                std::cout << "  " << print_tile(table[i][j].getTile()) << "  ";

                            else if (table[i][j].hasRobot() == 0 &&
                                     table[i][j].hasRobot() == 0)
                                std::cout << "     ";
                        }

                        else if (table[i][j].getWall(eright) == 1 ||
                                 table[i][j].getWall(eLeft) == 1)
                        {
                            if (table[i][j].hasRobot() == 1)
                                std::cout << "║ " << print_robot(table[i][j].getRobot())
                                          << "  ";

                            else if (table[i][j].hasRobot() == 0 &&
                                     table[i][j].hasRobot() == 1)
                                std::cout << "║ " << print_tile(table[i][j].getTile()) << "  ";

                            else if (table[i][j].hasRobot() == 0 &&
                                     table[i][j].hasRobot() == 0)
                                std::cout << "     ";
                        }
                        else
                            std::cout << "no configured (if j between 1 and 14 k = 1)";
                    }
                }
            }

            else if (k == 2)
            {
                for (int j = 0; 15; j++)
                {
                    if (j == 0)
                    {
                        if (table[i][j].getWall(eBottom) == 1 &&
                            table[i][j].getWall(eLeft) == 1 && i == 15)
                            std::cout << "╚═══";

                        else if (table[i][j].getWall(eBottom) == 1 &&
                                 table[i][j].getWall(eLeft) == 1 && i != 15)
                            std::cout << "╠═══";

                        else if (table[i][j].getWall(eBottom) == 0 &&
                                 table[i][j].getWall(eLeft) == 1)
                            std::cout << "║   ";

                        else
                            std::cout << "no configured (if j = 0  k = 2)";
                    }

                    else if (j == 15)
                    {
                        if (table[i][j].getWall(eBottom) == 1 &&
                            table[i][j].getWall(eright) == 1 &&
                            table[i][j].getWall(eLeft) == 0 && i == 15)
                            std::cout << "═════╝" << endl;

                        else if (table[i][j].getWall(eBottom) == 1 &&
                                 table[i][j].getWall(eright) == 1 &&
                                 table[i][j].getWall(eLeft) == 1 && i == 15)
                            std::cout << "╩════╝" << endl;

                        else if (table[i][j].getWall(eBottom) == 1 &&
                                 table[i][j].getWall(eright) == 1 &&
                                 table[i][j].getWall(eLeft) == 0 && i != 15)
                            std::cout << " ════╣" << endl;

                        else if (table[i][j].getWall(eBottom) == 0 &&
                                 table[i][j].getWall(eright) == 1 &&
                                 table[i][j].getWall(eLeft) == 0 && i != 15)
                            std::cout << "     ║" << endl;

                        else if (table[i][j].getWall(eBottom) == 0 &&
                                 table[i][j].getWall(eright) == 1 &&
                                 table[i][j].getWall(eLeft) == 1 &&
                                 table[i][j - 1].getCorner() == eBL)
                            std::cout << "═    ║" << endl;

                        else if (table[i][j].getWall(eBottom) == 0 &&
                                 table[i][j].getWall(eright) == 1 &&
                                 table[i][j].getWall(eLeft) == 1 &&
                                 table[i][j - 1].getCorner() == eTR)
                            std::cout << "║    ║" << endl;

                        else if (table[i][j].getWall(eBottom) == 0 &&
                                 table[i][j].getWall(eright) == 1 &&
                                 table[i][j].getWall(eLeft) == 1 &&
                                 table[i][j - 1].getCorner() == eBR)
                            std::cout << "╝    ║" << endl;

                        else
                            std::cout << "no configured (if j = 15  k = 2)";
                    }
                    else
                    { // j between 1 and 14
                        if (table[i][j].getWall(eBottom) == 1 &&
                            table[i][j].getWall(eright) == 0 &&
                            table[i][j].getWall(eLeft) == 0)
                            std::cout << "═════";

                        else if (table[i][j].getWall(eBottom) == 1 &&
                                 (table[i][j].getWall(eright) == 1 ||
                                  table[i][j].getWall(eLeft) == 1) &&
                                 (table[i][j - 1].getCorner() != eBR ||
                                  table[i][j - 1].getCorner() != eBL))
                            std::cout << "╩════";

                        else if (table[i][j].getWall(eBottom) == 0 &&
                                 table[i][j].getWall(eright) == 0 &&
                                 table[i][j].getWall(eLeft) == 0)
                            std::cout << "     ";

                        else if (table[i][j].getWall(eBottom) == 0 &&
                                 (table[i][j].getWall(eright) == 1 ||
                                 table[i][j].getWall(eLeft) == 1) &&
                                 table[i][j - 1].getCorner() == eBL)
                            std::cout << "╚    ";

                        else if (table[i][j].getWall(eBottom) == 0 &&
                                 (table[i][j].getWall(eright) == 1 ||
                                  table[i][j].getWall(eLeft) == 1) table[i][j - 1]
                                         .getCorner() == eBR)
                            std::cout << "╝    ";

                        else if (table[i][j].getWall(eBottom) == 0 &&
                                 (table[i][j].getWall(eright) == 1 ||
                                  table[i][j].getWall(eLeft) == 1) &&
                                 (table[i][j - 1].getCorner() != eBR ||
                                  table[i][j - 1].getCorner() != eBL))
                            std::cout << "║    ";

                        else
                            std::cout << "no configured (if j between 1 and 14 k = 2)";
                    }
                }
            }
            k++;
        }
    }
}
