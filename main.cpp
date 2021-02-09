#include <windows.h>
#include <iostream>

#include "Jeu.h"
#include "Interface.h"

using namespace std;

int main(int argc, char *argv[])
{
    Interface screen;
    int choice=0;
    int playerColumnChoice;

    while(choice != -1) {
        if(choice == 0) {
            screen.showMenu();
            choice = screen.selectChoice();
        }
        if(choice > 0){
            if(choice == 1)
                screen.showDifficultySelection();
            int difficulty = (choice == 1)?screen.selectDifficulty():0;
            Jeu game(choice, difficulty);
            screen.showGame(game);
            do {
                if(game.getMode() == 2 || game.getPlayerTurn() == 1)
                    playerColumnChoice = screen.clickedColumn();
                game.gameTurn(playerColumnChoice);
                screen.oneGameTurn(game);
            } while(!game.verif_victoire());
            screen.showVictory(game);
            if(screen.choixFinPartie() == 2)
                choice = 0;

        }
    }

    return 0;
}
