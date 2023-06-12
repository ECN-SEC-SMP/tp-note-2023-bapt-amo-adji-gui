#include "gameController.h"
#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

// Constructeurs
gameController::gameController(void)
{
    this->player1 = Player();
    this->player2 = Player();
    this->player3 = Player();
    this->player4 = Player();
    this->board = Board();
    this->playersAMove = {
        player1.getAnnouncedMove(),
        player2.getAnnouncedMove(),
        player3.getAnnouncedMove(),
        player4.getAnnouncedMove(),
    };
}

// Getter
Player gameController::getPlayer1(void) const { return player1; }
Player gameController::getPlayer2(void) const { return player2; }
Player gameController::getPlayer3(void) const { return player3; }
Player gameController::getPlayer4(void) const { return player4; }
Board gameController::getBoard(void) const { return board; }
list<int> gameController::getList(void) const { return playersAMove; }

// Methodes
void gameController::launchGame(void)
{
    std::srand(std::time(NULL));
    Board NewBoard = getBoard();
    Player p1 = getPlayer1();
    Player p2 = getPlayer2();
    Player p3 = getPlayer3();
    Player p4 = getPlayer4();
    // choix de l'objectif
    Tile tileToReach = Tile();
    tileToReach.setColor(static_cast<Color>(rand() % 5));
    tileToReach.setShape(static_cast<Shape>(rand() % 4));
    // TODO: Enable the rendering once done
    // NewBoard.renderBoard();
}
void gameController::getInput(void)
{
    list<int> List = getList();
    List.sort();
    int min = *List.begin();
    // Durée totale du chronomètre en secondes
    int dureeChronometre = 60;

    auto startTime = std::chrono::steady_clock::now();
    auto endTime = startTime + std::chrono::seconds(dureeChronometre);

    while (std::chrono::steady_clock::now() < endTime)
    {
        std::chrono::duration<double> tempsRestant =
            endTime - std::chrono::steady_clock::now();
        int secondesRestantes = static_cast<int>(tempsRestant.count());

        std::cout << "Temps restant : " << secondesRestantes << " secondes"
                  << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "Le chronomètre est terminé !" << std::endl;
}
