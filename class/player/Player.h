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
    //constructeur 
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
    string get_name();

    /**
     * @brief Get the total move object
     * 
     * @return int 
     */
    int get_total_move();

    /**
     * @brief Get the announced move object
     * 
     * @return int 
     */
    int get_announced_move();

    /**
     * @brief Get the point object
     * 
     * @return int 
     */
    int get_point();

    // methode
    // total move

    /**
     * @brief Reset the number of total move to 0 
     * 
     */
    void reset_move();

    /**
     * @brief Add a move to total move value
     * 
     */
    void add_move();
    
    // announced_move
    /**
     * @brief Reset the number of annonced move to 0 at each turn
     * 
     */
    void reset_announced_move();

    /**
     * @brief Set the announced move object
     * 
     */
    void set_announced_move();

    // point
    /**
     * @brief Add a point to the player 
     * 
     */
    void add_point();

    /**
     * @brief reset the number of point to 0 
     * 
     */
    void reset_point();
};

#endif