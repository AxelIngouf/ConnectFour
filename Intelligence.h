#ifndef INTELLIGENCE_H
#define INTELLIGENCE_H
#include <stdlib.h>
#include "Jeu.h"


class Intelligence
{
    public:
        Intelligence();
        virtual ~Intelligence();
        int ia(Jeu jeu);

    protected:

    private:
};

#endif // INTELLIGENCE_H
