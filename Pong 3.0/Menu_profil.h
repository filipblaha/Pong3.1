#pragma once
#include "Menu.h"
class Menu_profil : public Menu
{
    public:
        Commands set;
        Profily profil;
        Preklad transl;

    Menu_profil() : Menu(profil_e, 10, 8, 8)
    {
        Preklad transl;
        nastav_spodni_zavoru();
        aktual_nazev_profilu_start();
        vykresleni_profil();
    }


    int vstup_menu(int strana);
    void vykresleni_profil();
private:
    void nastav_spodni_zavoru();
};

