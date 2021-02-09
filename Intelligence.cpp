#include "Intelligence.h"
#include <iostream>

Intelligence::Intelligence()
{

}

Intelligence::~Intelligence()
{
    //dtor
}

int Intelligence::ia(Jeu jeu) {
    int interdit[columns]={0},jouer,sortie;

    if(jeu.getDifficulty()==2){
        // L'ia vérifie si elle peut gagner
        for(int i=0;i<lines;i++){
            for(int j=0;j<columns;j++){

            if (jeu.getTile(i, j)==0 && jeu.getTile(i+1, j)!=0 && jeu.getTile(i-1, j)==0){
                jeu.setTile(i, j, 2);
                if(jeu.verif_victoire()==2){
                    jouer=1;
                }
                jeu.setTile(i, j, 0);
            }
            if (jouer == 1)
                return j;
            }
        }

        // L'ia vérifie si le joueur peut gagner, si oui elle le bloque
        for(int i=0;i<lines;i++){
            for(int j=0;j<columns;j++){

            if (jeu.getTile(i, j)==0){
                jeu.setTile(i, j, 1);
                if(jeu.verif_victoire()==1){
                    jouer=1;
                }
                jeu.setTile(i, j, 0);
            }
            if (jouer == 1 && jeu.getTile(i+1, j)==0){
                // Si la colonne peut faire gagner le joueur si elle est jouée, l'ia s'interdit d'y jouer
                interdit[j] = 1;
                jouer = 0;
            }
            else if (jouer == 1)
                return j;
            }
        }


        // Si l'ia n'a pas de coup qui peut la faire gagner ou empêcher le joueur de gagner, elle joue stratégiquement
        for(int i=0;i<lines;i++){
            for(int j=0;j<columns;j++){

                // Blocage joueur ligne
                if(jeu.getTile(i, j)==1 && jeu.getTile(i, j+1)==1){
                    if((jeu.getTile(i+1, j+2)!=0 || i>lines-1) && jeu.getTile(i, j+2)==0 && !interdit[j+2])
                        return j+2;
                    if((jeu.getTile(i+1, j-1)!=0 || i>lines-1) && jeu.getTile(i, j-1)==0 && !interdit[j-1])
                        return j-1;
                }


                // Allongement colonne
                if (jeu.getTile(i, j)==0 && jeu.getTile(i+1, j)==0 && i-1>=0){
                    jeu.setTile(i, j, 2);
                    jeu.setTile(i+1, j, 2);
                    if(jeu.verif_victoire()==2)
                        jouer=1;
                    jeu.setTile(i, j, 0);
                    jeu.setTile(i+1, j, 0);
                }
                if (jouer == 1 && !interdit[j])
                    return j;
                else
                    jouer=0;


                // Allongement ligne droite
                if (jeu.getTile(i, j)==0 && jeu.getTile(i, j+1)==0){
                    jeu.setTile(i, j, 2);
                    jeu.setTile(i, j+1, 2);
                    if(jeu.verif_victoire()==2)
                        jouer=1;
                    jeu.setTile(i, j, 0);
                    jeu.setTile(i, j+1, 0);
                }
                if (jouer == 1) {
                    if(!interdit[j+1])
                        return j+1;
                    else if(!interdit[j])
                        return j;
                    else
                        jouer=0;
                }


                // Allongement ligne gauche
                if (jeu.getTile(i, j)==0 && jeu.getTile(i, j-1)==0){
                    jeu.setTile(i, j, 2);
                    jeu.setTile(i, j-1, 2);
                    if(jeu.verif_victoire()==2)
                        jouer=1;
                    jeu.setTile(i, j, 0);
                    jeu.setTile(i, j-1, 0);
                }
                if (jouer == 1) {
                    if(!interdit[j-1])
                        return j-1;
                    else if(!interdit[j])
                        return j;
                    else
                        jouer=0;
                }


                // Allongement diagonale gauche
                if (jeu.getTile(i, j)==0 && jeu.getTile(i-1, j-1)==0){
                    jeu.setTile(i, j, 2);
                    jeu.setTile(i-1, j-1, 2);
                    if(jeu.verif_victoire()==2)
                        jouer=1;
                    jeu.setTile(i, j, 0);
                    jeu.setTile(i-1, j-1, 0);
                }
                if (jouer == 1) {
                    if(!interdit[j-1])
                        return j-1;
                    else if(!interdit[j])
                        return j;
                    else
                        jouer=0;
                }


                // Allongement diagonale droite
                if (jeu.getTile(i, j)==0 && jeu.getTile(i-1, j+1)==0){
                    jeu.setTile(i, j, 2);
                    jeu.setTile(i-1, j+1, 2);
                    if(jeu.verif_victoire()==2)
                        jouer=1;
                    jeu.setTile(i, j, 0);
                    jeu.setTile(i-1, j+1, 0);
                }
                if (jouer == 1) {
                    if(!interdit[j+1])
                        return j+1;
                    else if(!interdit[j+2])
                        return j+2;
                    else
                        jouer=0;
                }


            }
        }
    }
    int i=0;
    do
    {
        i++;
        sortie=rand()%columns;
    } while((jeu.getTile(0, sortie) != 0 || interdit[sortie]) && i < 20);
    return sortie;
}
