#ifndef _HELPER_H_
#define _HELPER_H_

#include "../box/box.h"

/**
 * @brief This function checks if the current coordinates represent an edge of the board.
 *
 * @param x The x coordinate to check for.
 * @param y The y coordinate to check for.
 * @retval true  The coordinates are representing an edge.
 * @retval false The coordinates are NOT representing an edge.
 */
bool isAnEdge(int x, int y);

/**
 * @brief   This function add a wall at specific [x, y] coordinates.
 * @details Since two boxes are sharing a common wall we have to add the "other side"
 *          of the wall as well. The edge cases are for the edge of the board were
 *          there are no side walls to share (e.g. for the top row there is no upper box, and so on).
 *
 * @param[in] boxBoard  The 2d array board that contains all the boxes
 * @param[in] dir       The direction of the wall (e.g. [top, bottom, left, right])
 * @param[in] x         The x coordinate of the box
 * @param[in] y         The y coordinate of the box
 * @retval true         The wall was added succesfuly
 * @retval false        x or y is not in range [0; BOARD_SIZE]
 */
bool addOneWall(Box (*boxBoard)[BOARD_SIZE], Direction dir, int x, int y);

/**
 * @brief   This function add a corner to a box, depending on the type of the corner
 * @details This function ensures that we are able to put the corner. It checks that the corner type
 *          does not touch any nearby walls. If so it will return an error.
 *
 * @param[in] boxBoard  The 2d array board that contains all the boxes
 * @param[in] x         The x coordinate of the box
 * @param[in] y         The y coordinate of the box
 * @param[in] cornerT   The type of corner
 * @retval true         The corner is valid and has been added
 * @retval false        The corner is unvalid (e.g. touching a wall) and has not been added
 */
bool addCorner(Box (*boxBoard)[BOARD_SIZE], int x, int y, cornerType cornerT, bool override);

/**
 * @brief   Add a top left corner to a specific box at coordinates [x, y]
 * @details This function checks all the nearby walls that could touch the top left corner
 *          It ensures that those walls are not conflicting and if so it adds the corner. \n
 *          This function add as well the common walls between boxes by calling "addOneWall()" function
 *          once all the checks are done and the corner is ready to be added
 *
 * @param[in] boxBoard  The 2d array board that contains all the boxes
 * @param[in] x         The x coordinate of the box
 * @param[in] y         The y coordinate of the box
 * @return true         The corner is valid and has been added
 * @return false        The corner is unvalid (e.g. touching a wall) and has not been added
 */
bool addTLCorner(Box (*boxBoard)[BOARD_SIZE], int x, int y, bool override);

/**
 * @brief   Add a top right corner to a specific box at coordinates [x, y]
 * @details This function checks all the nearby walls that could touch the top right corner
 *          It ensures that those walls are not conflicting and if so it adds the corner. \n
 *          This function add as well the common walls between boxes by calling "addOneWall()" function
 *          once all the checks are done and the corner is ready to be added
 *
 * @param[in] boxBoard  The 2d array board that contains all the boxes
 * @param[in] x         The x coordinate of the box
 * @param[in] y         The y coordinate of the box
 * @return true         The corner is valid and has been added
 * @return false        The corner is unvalid (e.g. touching a wall) and has not been added
 */
bool addTRCorner(Box (*boxBoard)[BOARD_SIZE], int x, int y, bool override);

/**
 * @brief   Add a bottom right corner to a specific box at coordinates [x, y]
 * @details This function checks all the nearby walls that could touch the bottom right corner
 *          It ensures that those walls are not conflicting and if so it adds the corner. \n
 *          This function add as well the common walls between boxes by calling "addOneWall()" function
 *          once all the checks are done and the corner is ready to be added
 *
 * @param[in] boxBoard  The 2d array board that contains all the boxes
 * @param[in] x         The x coordinate of the box
 * @param[in] y         The y coordinate of the box
 * @return true         The corner is valid and has been added
 * @return false        The corner is unvalid (e.g. touching a wall) and has not been added
 */
bool addBRCorner(Box (*boxBoard)[BOARD_SIZE], int x, int y, bool override);

/**
 * @brief   Add a bottom left corner to a specific box at coordinates [x, y]
 * @details This function checks all the nearby walls that could touch the bottom left corner
 *          It ensures that those walls are not conflicting and if so it adds the corner. \n
 *          This function add as well the common walls between boxes by calling "addOneWall()" function
 *          once all the checks are done and the corner is ready to be added
 *
 * @param[in] boxBoard  The 2d array board that contains all the boxes
 * @param[in] x         The x coordinate of the box
 * @param[in] y         The y coordinate of the box
 * @return true         The corner is valid and has been added
 * @return false        The corner is unvalid (e.g. touching a wall) and has not been added
 */
bool addBLCorner(Box (*boxBoard)[BOARD_SIZE], int x, int y, bool override);

#endif