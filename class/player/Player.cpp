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
string Player::getName()
{
    return this->player_name;
}

int Player::getTotalMove()
{
    return this->total_move;
}

int Player::getAnnouncedMove()
{
    return this->announced_move;
}

int Player::getPoint()
{
    return this->point;
}

// methode
// total move
void Player::resetMove()
{
    this->total_move = 0;
}

void Player::resetPoint()
{
    this->point = 0;
}

void Player::addMove()
{
    this->total_move += 1;
}

// announced move
void Player::resetAnnouncedMove()
{
    this->announced_move = 0;
}

void Player::setAnnouncedMove()
{
    cout << "How many move do you need to reache the tile : " << endl;
    int move;
    cin >> move;
    this->announced_move = move;
}

// point
void Player::addPoint()
{
    this->point += 1;
}