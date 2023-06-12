#include <iostream>
#include <list> // classe list (conteneur)
using namespace std;
#pragma once

#include "../board/board.h"
#include "../player/Player.h"
#include "../tile/Tile.h"

class gameController
{
private:
    Player player1, player2, player3, player4;
    Board board;
    list<int> playersAMove{100, 100, 100, 100};

public:
    // constructeurs
    gameController();
    // Getter
    Player getPlayer1() const;
    Player getPlayer2() const;
    Player getPlayer3() const;
    Player getPlayer4() const;
    Board getBoard() const;
    list<int> getList() const;
    // Setter
    // void setLis(int r);

    // Methodes
    // Constructs board, players(getName) and initializes timer
    void launchGame();

    // Manage the game
    void getInput();
};
