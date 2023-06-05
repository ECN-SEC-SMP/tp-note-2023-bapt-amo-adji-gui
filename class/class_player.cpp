#include "class_player.h"

using namespace std;

// constructeur 
player::player(){
    cout << "type player name" <<endl ;
    cin >> string name;
    this -> player_name =  name; 
}

// accesseur 
string player::get_name(){
    return this -> player_name;
}

int player::get_total_move(){
    return this -> total_move;
}
    
int player::get_announced_move(){
    return this -> announced_move;
}

int player::get_point(){
    return this -> point;
}

// methode
// total move
void player::reset_move(){
    this -> total_move = 0;
}

void player::add_move(){
    this -> total_move += 1; 
}

//announced move
void player::reset_announced_move(){
    this -> announced_move = 0;
}

void player::set_announced_move(int move_nb){
    cout  << "How many move do you need to reache the tile" << endl; 
    cin >> int move;
    this -> announced_move = move; 
}

//point 
void player::add_point(){
    this -> point += 1;
}