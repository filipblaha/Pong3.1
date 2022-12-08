#pragma once
#include "Menu.h"
#include "Preklad.h"
class Menu_profil : public Menu
{
    public:
        Commands set;
        Profily profil;
        Preklad transl;

    Menu_profil() : Menu(profil_e, 10, 8, 8, 17)
    {
        Preklad transl;
        vykresleni_profil(urceni_prvniho_profilu());
    }

    void vykresleni_profil(std::wstring prvni_profil_v);
private:
    std::wstring urceni_prvniho_profilu();
};

