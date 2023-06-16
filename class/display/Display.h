/*
https://www.makeuseof.com/windows-alt-codes/

https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
*/


#include "../board/board.h"
#include "../../constants.h"

/**
 * @brief Print a colored smiley to represent the different robot
 *
 * @param robot
 */
void print_robot(Robot robot);

/**
 * @brief print a tile with the coresponding shape and color
 *
 * @param tile
 */
void print_tile(Tile tile);

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
void print_board(Board table);
