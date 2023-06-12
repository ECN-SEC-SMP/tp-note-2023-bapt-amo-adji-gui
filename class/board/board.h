#ifndef _BOARD_H_
#define _BOARD_H_

#include "../box/box.h"

class Board
{
private:
    /*
    The board itself containing separate boxes
    boxBoard[x][y]
    origin: [x = 0, y = 0] is on top left corner
    */
    Box boxBoard[BOARD_SIZE][BOARD_SIZE];

    /*
    Private methods to generate the board randomly called by the constructor
    These methods depends on helper.h functions
    */

    /**
     * @brief   This method adds the external walls of the board
     * @details This method adds all of the wall that define the edge of the board by iterating
     *          over each edges and assigning the good wall
     */
    void addExternalWalls();

    /**
     * @brief   This method adds the center square
     * @details This method adds the four corners that constitute the center square
     *
     */
    void addCenterSquare();

    /**
     * @brief   This methods add the inside walls
     * @details This methods iterate over the four edges to generate the 2 insides walls. \n
     *          It generates two random numbers until they are not equal two ensure not adding two
     *          times the same wall.
     * @note    This method should be called before "addCorners()"
     */
    void addInsideWalls();

    /**
     * @brief   This method add the 17 corners of the board.
     * @details This methods iterates over the four quadrants of the board. It tries to add a random
     *          corner at a random location [x, y] ∈ [0, (BOARD_SIZE / 2) + offset]². \n
     *          If it fails it reiterates until a valid corner and a valid location is generated.
     *          This process is then done four times for the four quadrant. The quadrant selection is determined
     *          by the offset.
     *          At the end it adds the 17 corner by generating random location [x, y] ∈ [0, BOARD_SIZE]².
     */
    void addCorners();

    // // TODO: Add the two methods
    // void initRobots();
    // void initTiles();

public:
    /**
     * @brief   Construct a new Board:: Board object
     * @details This constructor initializes the board and generate the walls for it. \n
     *          It generate the following walls: \n
     *              - External walls. \n
     *              - Center square. \n
     *              - Inside walls. \n
     *              - Corners.
     */
    Board();

    // TODO: Create the function (calling helper ?)
    void renderBoard();
    void renderDebugBoard();

    // // TODO: Add the two methods
    // // As documentation says : 0=move_done, 1=can_t_go_there, 2=goal_reached
    int move(Color robotColor, Direction dir);
};

#endif //_BOARD_H_