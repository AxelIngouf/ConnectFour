#ifndef INTERFACE_H
#define INTERFACE_H
#include <SDL2/SDL.h>
#include <SDL2/sdl_image.h>
#include <SDL2/sdl_mixer.h>

#include "Jeu.h"


class Interface
{
    public:
        Interface();
        virtual ~Interface();
        void showMenu();
        void showDifficultySelection();
        void showGame(Jeu jeu);
        void showVictory(Jeu jeu);
        void oneGameTurn(Jeu jeu);
        int clickedColumn();
        int selectChoice();
        int selectDifficulty();
        int choixFinPartie();

    protected:

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event event;
        SDL_Surface *joueur1 = NULL,
                    *joueur2 = NULL,
                    *ia = NULL,
                    *prouge = NULL,
                    *pbleu = NULL,
                    *vide = NULL,
                    *fond = NULL,
                    *hard = NULL,
                    *easy = NULL,
                    *matchnul = NULL,
                    *quitter = NULL,
                    *restart = NULL,
                    *win = NULL,
                    *plat = NULL,
                    *multi = NULL,
                    *solo = NULL;
        SDL_Rect    posjoueur1,
                    posjoueur2,
                    posia,
                    posprouge,
                    pospbleu,
                    posvide,
                    posfond,
                    poshard,
                    poseasy,
                    posmatchnul,
                    posquitter,
                    posrestart,
                    posplat,
                    posmulti,
                    possolo,
                    poswin,
                    posjgagnant,
                    posj1,
                    posj2;
        SDL_Texture *j1Texture = NULL,
                    *j2Texture = NULL,
                    *iaTexture = NULL,
                    *prougeTexture = NULL,
                    *pbleuTexture = NULL,
                    *videTexture = NULL,
                    *fondTexture = NULL,
                    *hardTexture = NULL,
                    *easyTexture = NULL,
                    *matchnulTexture = NULL,
                    *quitterTexture = NULL,
                    *restartTexture = NULL,
                    *winTexture = NULL,
                    *platTexture = NULL,
                    *multiTexture = NULL,
                    *soloTexture = NULL;
};

#endif // INTERFACE_H
