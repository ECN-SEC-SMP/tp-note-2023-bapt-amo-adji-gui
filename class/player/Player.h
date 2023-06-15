#include <iostream>
using namespace std;

#ifndef class_player_h
#define class_player_h

class Player
{
private:
    string player_name;
    int total_move = 0;
    int announced_move = 0;
    int point = 0;

public:
    // constructeur
    /**
     * @brief Construct a new Player object
     *
     */
    Player();

    // accesseur
    /**
     * @brief Get the name object
     *
     * @return string The name of the registered player
     */
    string getName();

    /**
     * @brief Get the total move object
     *
     * @return int
     */
    int getTotalMove();

    /**
     * @brief Get the announced move object
     *
     * @return int
     */
    int getAnnouncedMove();

    /**
     * @brief Get the point object
     *
     * @return int
     */
    int getPoint();

    // methode
    // total move

    /**
     * @brief Reset the number of total move to 0
     *
     */
    void resetMove();

    /**
     * @brief Add a move to total move value
     *
     */
    void addMove();

    // announced_move
    /**
     * @brief Reset the number of annonced move to 0 at each turn
     *
     */
    void resetAnnouncedMove();

    /**
     * @brief Set the announced move object
     *
     */
    void setAnnouncedMove();

    // point
    /**
     * @brief Add a point to the player
     *
     */
    void addPoint();

    /**
     * @brief reset the number of point to 0
     *
     */
    void resetPoint();
};

#endif