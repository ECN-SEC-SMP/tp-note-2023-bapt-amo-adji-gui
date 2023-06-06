#include "Player.h"

using namespace std;

// constructeur
Player::Player()
{
    cout << "Enter player name :" << endl;
    string name;
    cin >> name;
    this->player_name = name;
}

// accesseur
string Player::get_name()
{
    return this->player_name;
}

int Player::get_total_move()
{
    return this->total_move;
}

int Player::get_announced_move()
{
    return this->announced_move;
}

int Player::get_point()
{
    return this->point;
}

// methode
// total move
void Player::reset_moves()
{
    this->total_move = 0;
}

void Player::add_move()
{
    this->total_move += 1;
}

// announced move
void Player::reset_announced_move()
{
    this->announced_move = 0;
}

void Player::set_announced_move()
{
    cout << "How many move do you need to reache the tile : " << endl;
    int move;
    cin >> move;
    this->announced_move = move;
}

// point
void Player::add_point()
{
    this->point += 1;
}