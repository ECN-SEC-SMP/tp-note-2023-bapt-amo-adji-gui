#include <iostream>
using namespace std;

#ifndef class_player_h
#define class_player_h

class player{
    private : 
        string player_name;
        int total_move = 0;
        int announced_move = 0;
        int point = 0;

        void add_move;

    public : 
    //constructeur 
    player();
    //accesseur 
    string get_name();
    int get_total_move();
    int get_announced_move();
    int get_point();

    //methode
    //total move 
    void set_name();
    void reset_moves();

    // announced_move
    void reset_announced_move();
    void set_annonced_move(int move_nb);

    //point 
    void add_point();
};

#endif