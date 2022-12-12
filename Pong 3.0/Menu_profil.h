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
        vykresleni_profil(set_jazyk());

    }
    std::vector<std::wstring> t;

    int vstup_menu(int strana);
    void vykresleni_profil(int jazyk);
    void vykresleni_otazka();

    void rozhodovac(int prikaz, int inkrement = 0);
private:
    void nastav_spodni_zavoru();
    void nastav_oznaceni();
    void vykresleni_nazev_profilu();
    void smazani_v_ramecku();
    std::string zadani_nazvu_profilu();
};

