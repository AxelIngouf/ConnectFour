#include "Interface.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

Interface::Interface()
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow("Puissance 4", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 720, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if(!window)
    {
        std::cout << "SDL Error : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    atexit(SDL_Quit);

    // Renderer

    renderer = SDL_CreateRenderer(window, -1, 0);

    if(!renderer)
    {
        std::cout << "SDL Error : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    prouge = IMG_Load("assets/redToken.png");
    if (prouge == NULL)
    {
        std::cout << "Probleme lors du chargement d'une image : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    pbleu = IMG_Load("assets/blueToken.png");
    if (pbleu == NULL)
    {
        std::cout << "Probleme lors du chargement d'une image : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    vide = IMG_Load("assets/void.png");
    if (vide == NULL)
    {
        std::cout << "Probleme lors du chargement d'une image : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    joueur1 = IMG_Load("assets/perso2.png");
    if (joueur1 == NULL)
    {
        std::cout << "Probleme lors du chargement d'une image : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    joueur2 = IMG_Load("assets/perso.png");
    if (joueur2 == NULL)
    {
        std::cout << "Probleme lors du chargement d'une image : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    ia = IMG_Load("assets/ia.png");
    if (ia == NULL)
    {
        std::cout << "Probleme lors du chargement d'une image : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    solo = IMG_Load("assets/1j.png");
    if (!solo)
    {
        std::cout << "Probleme lors du chargement d'une image : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    multi = IMG_Load("assets/2j.png");
    if (!multi)
    {
        std::cout << "Probleme lors du chargement d'une image : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    fond = IMG_Load("assets/menu.png");
    if (!fond)
    {
        std::cout << "Probleme lors du chargement d'une image : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    plat = IMG_Load("assets/bg.jpg");
    if (!plat)
    {
        std::cout << "Probleme lors du chargement d'une image : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    win = IMG_Load("assets/gagnant.png");
    if (!win)
    {
        std::cout << "Probleme lors du chargement d'une image : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    restart = IMG_Load("assets/restart.png");
    if (!restart)
    {
        std::cout << "Probleme lors du chargement d'une image : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    quitter = IMG_Load("assets/quitter.png");
    if (!quitter)
    {
        std::cout << "Probleme lors du chargement d'une image : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    matchnul = IMG_Load("assets/matchnul.png");
    if (!matchnul)
    {
        std::cout << "Probleme lors du chargement d'une image : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    easy = IMG_Load("assets/easy.png");
    if (!easy)
    {
        std::cout << "Probleme lors du chargement d'une image : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    hard = IMG_Load("assets/hard.png");
    if (!hard)
    {
        std::cout << "Probleme lors du chargement d'une image : " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    int window_width = SDL_GetWindowSurface(window)->w;
    int window_height = SDL_GetWindowSurface(window)->h;

        // Image de fond
    posfond.x = (window_width - fond->w) / 2;
    posfond.y = (window_height - fond->h) / 2;
    posplat.x = (window_width - plat->w) / 2;
    posplat.y = (window_height - plat->h) / 2;

    // Boutons du menu
    possolo.x = (window_width - solo->w)/2;
    possolo.y = (window_height - solo->h)/2 +80;
    posmulti.x = (window_width - multi->w)/2;
    posmulti.y = (window_height - multi->h)/2 +200;
    poseasy.x = (window_width - easy->w)/2-150;
    poseasy.y = (window_height - easy->h)/2+100;
    poshard.x = (window_width - hard->w)/2+130;
    poshard.y = (window_height - hard->h)/2+100;
    posquitter.x = (window_width - quitter->w)/2;
    posquitter.y = (window_height - quitter->h)/2+300;

    // Interface de fin de partie
    posjgagnant.x = (window_width - joueur1->w)/2-150;
    posjgagnant.y = (window_height - joueur1->h)/2-205;
    poswin.x = (window_width - win->w)/2+100;
    poswin.y = (window_height - win->h)/2-205;
    posrestart.x = (window_width - restart->w)/2+150;
    posrestart.y = (window_height - restart->h)/2;
    posmatchnul.x = (window_width - matchnul->w)/2;
    posmatchnul.y = (window_height - matchnul->h)/2-205;

    SDL_Surface* windowSurface = SDL_GetWindowSurface(window);

    SDL_BlitSurface(joueur1,0,windowSurface,&posj1);
    SDL_BlitSurface(joueur2,0,windowSurface,&posj2);
    SDL_BlitSurface(ia,0,windowSurface,&posj2);
    SDL_BlitSurface(fond,0,windowSurface,&posfond);
    SDL_BlitSurface(plat,0,windowSurface,&posplat);
    SDL_BlitSurface(solo,0,windowSurface,&possolo);
    SDL_BlitSurface(multi,0,windowSurface,&posmulti);
    SDL_BlitSurface(quitter,0,windowSurface,&posquitter);
    SDL_BlitSurface(easy,0,windowSurface,&poseasy);
    SDL_BlitSurface(hard,0,windowSurface,&poshard);
    SDL_BlitSurface(restart,0,windowSurface,&posrestart);
    SDL_BlitSurface(matchnul,0,windowSurface,&posmatchnul);
    SDL_BlitSurface(win,0,windowSurface,&poswin);
    j1Texture = SDL_CreateTextureFromSurface(renderer, joueur1);
    j2Texture = SDL_CreateTextureFromSurface(renderer, joueur2);
    iaTexture = SDL_CreateTextureFromSurface(renderer, ia);
    prougeTexture = SDL_CreateTextureFromSurface(renderer, prouge);
    pbleuTexture = SDL_CreateTextureFromSurface(renderer, pbleu);
    videTexture = SDL_CreateTextureFromSurface(renderer, vide);
    fondTexture = SDL_CreateTextureFromSurface(renderer, fond);
    platTexture = SDL_CreateTextureFromSurface(renderer, plat);
    soloTexture = SDL_CreateTextureFromSurface(renderer, solo);
    multiTexture = SDL_CreateTextureFromSurface(renderer, multi);
    quitterTexture = SDL_CreateTextureFromSurface(renderer, quitter);
    easyTexture = SDL_CreateTextureFromSurface(renderer, easy);
    hardTexture = SDL_CreateTextureFromSurface(renderer, hard);
    restartTexture = SDL_CreateTextureFromSurface(renderer, restart);
    matchnulTexture = SDL_CreateTextureFromSurface(renderer, matchnul);
    winTexture = SDL_CreateTextureFromSurface(renderer, win);
    SDL_FreeSurface(matchnul);
    SDL_FreeSurface(restart);
    SDL_FreeSurface(solo);
    SDL_FreeSurface(win);
    SDL_FreeSurface(plat);
    SDL_FreeSurface(fond);
    SDL_FreeSurface(quitter);

}

Interface::~Interface()
{
    SDL_FreeSurface(easy);
    SDL_FreeSurface(hard);
    SDL_FreeSurface(multi);
    SDL_FreeSurface(pbleu);
    SDL_FreeSurface(prouge);
    SDL_FreeSurface(vide);
    SDL_FreeSurface(joueur1);
    SDL_FreeSurface(joueur2);
    SDL_FreeSurface(ia);
    SDL_DestroyTexture(j1Texture);
    SDL_DestroyTexture(j2Texture);
    SDL_DestroyTexture(iaTexture);
    SDL_DestroyTexture(prougeTexture);
    SDL_DestroyTexture(pbleuTexture);
    SDL_DestroyTexture(videTexture);
    SDL_DestroyTexture(fondTexture);
    SDL_DestroyTexture(platTexture);
    SDL_DestroyTexture(soloTexture);
    SDL_DestroyTexture(multiTexture);
    SDL_DestroyTexture(quitterTexture);
    SDL_DestroyTexture(easyTexture);
    SDL_DestroyTexture(hardTexture);
    SDL_DestroyTexture(restartTexture);
    SDL_DestroyTexture(matchnulTexture);
    SDL_DestroyTexture(winTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Interface::showMenu() {
    int window_width = SDL_GetWindowSurface(window)->w;
    int window_height = SDL_GetWindowSurface(window)->h;
    posquitter.x = (window_width - quitter->w)/2;
    posquitter.y = (window_height - quitter->h)/2+300;

    SDL_RenderCopy(renderer, platTexture, NULL, &posplat);
    SDL_RenderCopy(renderer, fondTexture, NULL, &posfond);
    SDL_RenderCopy(renderer, soloTexture, NULL, &possolo);
    SDL_RenderCopy(renderer, multiTexture, NULL, &posmulti);
    SDL_RenderCopy(renderer, quitterTexture, NULL, &posquitter);
    SDL_RenderPresent(renderer);
}

void Interface::showDifficultySelection() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, platTexture, NULL, &posplat);
    SDL_RenderCopy(renderer, easyTexture, NULL, &poseasy);
    SDL_RenderCopy(renderer, hardTexture, NULL, &poshard);
    SDL_RenderPresent(renderer);
}

void Interface::showGame(Jeu jeu) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, platTexture, NULL, &posplat);
    SDL_RenderCopy(renderer, j1Texture, NULL, &posj1);
    if(jeu.getMode() == 1) {
        SDL_RenderCopy(renderer, iaTexture, NULL, &posj2);
    } else {
        SDL_RenderCopy(renderer, j2Texture, NULL, &posj2);
    }
    SDL_RenderPresent(renderer);
}

void Interface::showVictory(Jeu jeu) {
    int window_width = SDL_GetWindowSurface(window)->w;
    int window_height = SDL_GetWindowSurface(window)->h;
    posquitter.x = (window_width - quitter->w)/2-150;
    posquitter.y = (window_height - quitter->h)/2;

    SDL_Surface* windowSurface = SDL_GetWindowSurface(window);
    SDL_RenderCopy(renderer, restartTexture, NULL, &posrestart);
    SDL_RenderCopy(renderer, quitterTexture, NULL, &posquitter);
    SDL_RenderCopy(renderer, winTexture, NULL, &poswin);
    if(jeu.verif_victoire() == 1) {
        SDL_BlitSurface(joueur1,0,windowSurface,&posjgagnant);
        SDL_RenderCopy(renderer, j1Texture, NULL, &posjgagnant);
    } else if(jeu.getMode() == 1) {
        SDL_BlitSurface(ia,0,windowSurface,&posjgagnant);
        SDL_RenderCopy(renderer, iaTexture, NULL, &posjgagnant);
    } else {
        SDL_BlitSurface(joueur2,0,windowSurface,&posjgagnant);
        SDL_RenderCopy(renderer, j2Texture, NULL, &posjgagnant);
    }
    SDL_RenderPresent(renderer);
}

void Interface::oneGameTurn(Jeu jeu) {

    int joueur = jeu.getPlayerTurn();
    int mode = jeu.getMode();

    SDL_Rect position;
    position.y = 210;
    for (int i=0 ; i< lines; i++)
    {
        position.x = 17;
        for (int j=0 ; j < columns ; j++)
        {
            int currentValue = jeu.getTile(i, j);
            if (currentValue == 1) {
                SDL_BlitSurface(prouge, NULL, SDL_GetWindowSurface(window), &position);
                SDL_RenderCopy(renderer, prougeTexture, NULL, &position);
            } else if (currentValue == 2) {
                SDL_BlitSurface(pbleu, NULL, SDL_GetWindowSurface(window), &position);
                SDL_RenderCopy(renderer, pbleuTexture, NULL, &position);
            } else {
                SDL_BlitSurface(vide, NULL, SDL_GetWindowSurface(window), &position);
                SDL_RenderCopy(renderer, videTexture, NULL, &position);
            }
            position.x += 84;
        }
            position.y += 82;
    }

    position.x = 485;
    position.y = 40;
    if (joueur == 1) {
        SDL_BlitSurface(joueur1, NULL, SDL_GetWindowSurface(window), &position);
        SDL_RenderCopy(renderer, j1Texture, NULL, &position);
    } else if (joueur == 2 && mode == 2) {
        SDL_BlitSurface(joueur2, NULL, SDL_GetWindowSurface(window), &position);
        SDL_RenderCopy(renderer, j2Texture, NULL, &position);
    } else {
        SDL_BlitSurface(ia, NULL, SDL_GetWindowSurface(window), &position);
        SDL_RenderCopy(renderer, iaTexture, NULL, &position);
        SDL_RenderPresent(renderer);
        Sleep(500);
    }

    position.x = 0;
    position.y = 0;
    SDL_RenderPresent(renderer);
}

// Checks which column is selected with the mouse
int Interface::clickedColumn() {
    bool test_co = false;
    int x, y, co=0;
    srand(time(NULL));
    SDL_Event event;
    while (!test_co){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_MOUSEBUTTONDOWN) {
                SDL_GetMouseState(&x,&y);
                if(y>100){
                    for(int i=1;i<=7;i++){
                        if(x>7+84*(i-1) && x<7+84*(i)){
                            co = i;
                            test_co=true;
                        }
                    }
                }
            }
        }
    }

    return co-1;
}

int Interface::selectChoice() {
    int choice = 0, x, y;
    SDL_Event event;
    while(choice == 0) {
        while (SDL_PollEvent(&event))
        {

            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                choice = -1;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        choice = -1;
                    }
                    break;
                }
            case SDL_MOUSEBUTTONDOWN:
                {
                    SDL_GetMouseState(&x,&y);
                    if(x>possolo.x && y>possolo.y && x<possolo.x+solo->w && y<possolo.y+solo->h){
                        choice=1;
                    }
                    if(x>posmulti.x && y>posmulti.y && x<posmulti.x+multi->w && y<posmulti.y+multi->h){
                        choice=2;
                    }
                    if(x>posquitter.x && y>posquitter.y && x<posquitter.x+quitter->w && y<posquitter.y+quitter->h){
                        choice = -1;
                    }
                }
            } // end switch
        }
    }
    return choice;
}

int Interface::selectDifficulty() {
    int x, y, choice = 0;
    while(!choice){
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_GetMouseState(&x,&y);
                if(x>poseasy.x && y>poseasy.y && x<poseasy.x+easy->w && y<poseasy.y+easy->h){
                    choice=1;
                }
                if(x>poshard.x && y>poshard.y && x<poshard.x+hard->w && y<poshard.y+hard->h){
                    choice=2;
                }
            }
        }
    }

    return choice;
}

int Interface::choixFinPartie() {
    int x, y, choice = 0;
    while(!choice){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_GetMouseState(&x,&y);
                if(x>posrestart.x && y>posrestart.y && x<posrestart.x+restart->w && y<posrestart.y+restart->h){
                    choice=1;
                }
                if(x>posquitter.x && y>posquitter.y && x<posquitter.x+quitter->w && y<posquitter.y+quitter->h){
                    choice=2;
                }
            }
        }
    }

    return choice;
}
