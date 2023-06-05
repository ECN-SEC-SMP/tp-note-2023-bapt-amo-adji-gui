#include "board.h"
#include "../../constants.h"
#include <iostream>
using namespace std;

/*********************************PRIVATE********************************/
void Board::addExternalWalls()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        boxBoard[0][i].setWall(eTop);                 // x = 0, y = i          ==> First row
        boxBoard[BOARD_SIZE - 1][i].setWall(eBottom); // x = BOARD_SIZE, y = i ==> Last row
        boxBoard[i][0].setWall(eLeft);                // x = i, y = 0          ==> First column
        boxBoard[i][BOARD_SIZE - 1].setWall(eRight);  // x = i, y = BOARD_SIZE ==> Last column
    }
}

void Board::addCenterSquare()
{
    addCorner(boxBoard, ((BOARD_SIZE / 2) - 1), ((BOARD_SIZE / 2) - 1), eTL, true);
    addCorner(boxBoard, ((BOARD_SIZE / 2) - 1), (BOARD_SIZE / 2), eTR, true);
    addCorner(boxBoard, (BOARD_SIZE / 2), ((BOARD_SIZE / 2) - 1), eBL, true);
    addCorner(boxBoard, (BOARD_SIZE / 2), (BOARD_SIZE / 2), eBR, true);
}

void Board::addInsideWalls()
{
    srand(time(NULL));
    int j = 0;
    int val1 = 0;
    int val2 = 0;
    // Iterates four time for the four edges
    while (j < 4)
    {
        // Creates two value [val1, val2] ∈ [0, BOARD_SIZE - 1 - 1]² = [0, BOARD_SIZE - 2]²
        do
        {
            val1 = rand() % (BOARD_SIZE / 2);
            val2 = rand() % (BOARD_SIZE / 2) + (BOARD_SIZE / 2) - 1;
        } while (val1 == val2);

        switch (j)
        {
        // Top edge
        case 0:
            addOneWall(this->boxBoard, eRight, 0, val1);
            addOneWall(this->boxBoard, eRight, 0, val2);
            break;

        // Bottom edge
        case 1:
            addOneWall(this->boxBoard, eRight, (BOARD_SIZE - 1), val1);
            addOneWall(this->boxBoard, eRight, (BOARD_SIZE - 1), val2);
            break;

        // Left edge
        case 2:
            addOneWall(this->boxBoard, eBottom, val1, 0);
            addOneWall(this->boxBoard, eBottom, val2, 0);
            break;

        // Right edge
        case 3:
            addOneWall(this->boxBoard, eBottom, val1, (BOARD_SIZE - 1));
            addOneWall(this->boxBoard, eBottom, val2, (BOARD_SIZE - 1));
            break;

        default:
            std::runtime_error("[Board, \"addInsideWalls\"] j value should not go above 3");
            break;
        }
        j++;
    }
}

void Board::addCorners()
{
    // Generates the seed based on actual time
    srand(time(NULL));
    int x = 0;
    int offsetX = 0;
    int y = 0;
    int offsetY = 0;

    int i = 0;
    int j = 0;

    cornerType corner = cornerType(0);

    // Loops through the 4 quarters
    while (j < 4)
    {
        // Loops through the 4 corners we have to place
        while (i < 4)
        {
            // Generate new values until a valid corner is placed
            // with a valid location
            do
            {
                x = (rand() % (BOARD_SIZE / 2)) + offsetX;
                y = (rand() % (BOARD_SIZE / 2)) + offsetY;
                corner = cornerType(i);
            } while (addCorner(boxBoard, x, y, corner, false) == false);
            i++;
        }
        i = 0;
        j++;

        // Adds the offset so that the generated values
        // correspond to a quarter
        switch (j)
        {
        case 1:
            offsetX = (BOARD_SIZE / 2);
            offsetY = 0;
            break;

        case 2:
            offsetX = 0;
            offsetY = (BOARD_SIZE / 2);
            break;
        case 3:
            offsetX = (BOARD_SIZE / 2);
            offsetY = (BOARD_SIZE / 2);
        default:
            break;
        }
    }

    // Generates the seventeen corner of the board (placed anywhere on the board)
    do
    {
        x = rand() % (BOARD_SIZE);
        y = rand() % (BOARD_SIZE);
        corner = cornerType(rand() % 4);
    } while (addCorner(boxBoard, x, y, corner, false) == false);
}
/*********************************PRIVATE********************************/

/*********************************PUBLIC*********************************/
Board::Board()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            boxBoard[i][j] = Box();
        }
    }

    this->addExternalWalls();
    this->addCenterSquare();
    this->addInsideWalls();
    this->addCorners();
}

void Board::renderDebugBoard()
{
    // Display of a box
    // #####
    // #   #
    // #####
    for (int x = 0; x < BOARD_SIZE; x++)
    {
        int y = 0;

        // First row of the boxes on this column
        for (y = 0; y < BOARD_SIZE; y++)
        {
            if (y == 0)
            {
                cout << "|";
            }

            if (boxBoard[x][y].getWall(eTop) || boxBoard[x][y].getWall(eLeft))
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }

            if (boxBoard[x][y].getWall(eTop))
            {
                cout << "###";
            }
            else
            {
                cout << "   ";
            }

            if (boxBoard[x][y].getWall(eTop) || boxBoard[x][y].getWall(eRight))
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }

            cout << "|";
        }

        cout << endl;

        // Second row of the boxes on this column
        for (y = 0; y < BOARD_SIZE; y++)
        {
            if (y == 0)
            {
                cout << "|";
            }

            if (boxBoard[x][y].getWall(eLeft))
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }

            // Robots and tiles should be displayed here...
            cout << "   ";

            if (boxBoard[x][y].getWall(eRight))
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }

            cout << "|";
        }

        cout << endl;

        // Third and last row of the boxes on this column
        for (y = 0; y < BOARD_SIZE; y++)
        {
            if (y == 0)
            {
                cout << "|";
            }

            if (boxBoard[x][y].getWall(eBottom) || boxBoard[x][y].getWall(eLeft))
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }

            if (boxBoard[x][y].getWall(eBottom))
            {
                cout << "###";
            }
            else
            {
                cout << "   ";
            }

            if (boxBoard[x][y].getWall(eBottom) || boxBoard[x][y].getWall(eRight))
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }

            cout << "|";
        }

        cout << endl;
        for (y = 0; y < BOARD_SIZE; y++)
        {
            if (y == 0)
            {
                cout << "+-----+";
            }
            else
            {
                cout << "-----+";
            }
        }
        cout << endl;
    }
}
/*********************************PUBLIC*********************************/