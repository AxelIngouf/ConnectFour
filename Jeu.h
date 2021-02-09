#ifndef JEU_H
#define JEU_H
#define lines 6
#define columns 7

class Jeu
{
    public:
        Jeu();
        Jeu(int gameMode, int gameDifficulty);
        virtual ~Jeu();
        void gameTurn(int playerColumnChoice);
        int insertToken(int columnTarget);
        int verif_victoire();
        int verif_entier();
        int getTile(int line, int column);
        void setTile(int line, int column, int value);
        int getPlayerTurn();
        int getMode();
        int getDifficulty();

    protected:

    private:
        int jeu[lines][columns];
        int playerTurn;
        int mode;
        int difficulty;
};

#endif // JEU_H
