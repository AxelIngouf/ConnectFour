#include <iostream>

#include "Jeu.h"
#include "Intelligence.h"

Jeu::Jeu()
{
    for(int i = 0; i < lines; i++) {
        for(int j = 0; j < columns; j++) {
            jeu[i][j] = 0;
        }
    }
    playerTurn = 1;
    mode=1;
}

Jeu::Jeu(int m, int d)
{
    mode = m;
    difficulty = d;
    for(int i = 0; i < lines; i++) {
        for(int j = 0; j < columns; j++) {
            jeu[i][j] = 0;
        }
    }
    playerTurn = 1;
}

Jeu::~Jeu()
{

}

void Jeu::gameTurn(int playerColumnChoice) {
    Intelligence ai;
    int columnTarget=0;
    do {
        if(playerTurn == 2 && mode == 1) { // AI Turn
            columnTarget = ai.ia(*this);
        } else {
            columnTarget = playerColumnChoice;
        }
    } while(insertToken(columnTarget) < 0);
    if(playerTurn == 1)
        playerTurn = 2;
    else
        playerTurn = 1;
}

//return -1 if the insertion is illegal, 1 or 2 if the game is over, 0 if not
int Jeu::insertToken(int columnTarget) {
    int result = -1, lineTarget = lines - 1;
    while(result < 0 && lineTarget >= 0) {
        if(columnTarget >= 0 && columnTarget < columns && jeu[lineTarget][columnTarget]==0){
                jeu[lineTarget][columnTarget]=playerTurn;
            result = verif_victoire();
        }
        lineTarget--;
    }
    return result;
}

int Jeu::verif_victoire() {

    // Ligne
    for (int i=0;i<lines;i++)
    {
        for (int j=0;j<columns-3;j++)
        {
            if (jeu[i][j] == 1 && jeu[i][j+1] == 1 && jeu[i][j+2] == 1 && jeu[i][j+3] == 1 )
              return 1;
            if (jeu[i][j] == 2 && jeu[i][j+1] == 2 && jeu[i][j+2] == 2 && jeu[i][j+3] == 2)
              return 2;
        }
    }


    // Colonne
    for (int i=3;i<lines;i++)
    {
        for (int j=0;j<columns;j++)
        {
            if (jeu[i][j] == 1 && jeu[i-1][j] == 1 && jeu[i-2][j] == 1 && jeu[i-3][j] == 1 )
              return 1;
            if (jeu[i][j] == 2 && jeu[i-1][j] == 2 && jeu[i-2][j] == 2 && jeu[i-3][j] == 2)
              return 2;
        }
    }

    // Diagonale gauche
    for (int i=0;i<lines-3;i++)
    {
        for (int j=0;j<columns-3;j++)
        {
            if (jeu[i][j] == 1 && jeu[i+1][j+1] == 1 && jeu[i+2][j+2] == 1 && jeu[i+3][j+3] == 1 )
              return 1;
            if (jeu[i][j] == 2 && jeu[i+1][j+1] == 2 && jeu[i+2][j+2] == 2 && jeu[i+3][j+3] == 2)
              return 2;
        }
    }

    // Diagonale droite
    for (int i=0;i<lines-3;i++)
    {
        for (int j=3;j<columns;j++)
        {
            if (jeu[i][j] == 1 && jeu[i+1][j-1] == 1 && jeu[i+2][j-2] == 1 && jeu[i+3][j-3] == 1 )
              return 1;
            if (jeu[i][j] == 2 && jeu[i+1][j-1] == 2 && jeu[i+2][j-2] == 2 && jeu[i+3][j-3] == 2)
              return 2;
        }
    }

    return 0;
}

int Jeu::verif_entier() {
    for(int i=0;i<lines;i++)
    {
        for(int j=0;j<columns;j++)
        {
            if(jeu[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

int Jeu::getTile(int line, int column) {
    return jeu[line][column];
}

void Jeu::setTile(int line, int column, int value) {
    jeu[line][column] = value;
}

int Jeu::getPlayerTurn() {

    return playerTurn;
}

int Jeu::getMode() {
    return mode;
}

int Jeu::getDifficulty() {
    return difficulty;
}
