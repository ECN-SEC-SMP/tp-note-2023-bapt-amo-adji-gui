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
    Player();
    // accesseur
    string get_name();
    int get_total_move();
    int get_announced_move();
    int get_point();

    // methode
    // total move
    void reset_move();
    void add_move();
    
    // announced_move
    void reset_announced_move();
    void set_announced_move();

    // point
    void add_point();
    void reset_point();
    
};

#endif