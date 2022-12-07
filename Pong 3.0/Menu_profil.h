#pragma once
#include "Menu.h"
#include "Preklad.h"
class Menu_profil : public Menu
{
    public:
    Commands set;
    Preklad transl;

    Menu_profil() : Menu(profil_e, 10, 8, 8, 17)
    {
        vykresleni_profil();
    }
    void vykresleni_profil();
};

