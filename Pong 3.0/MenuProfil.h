#pragma once
#include "Menu.h"

class MenuProfil : public Menu
{
public:
    Commands set;
    Profily profil;
    Preklad transl;

    MenuProfil() : Menu(profil_e, 10, 8, 8)
    {
        Preklad transl;

        SpodniZavoraSet();
        AktualNazevProfiluSTART();
    }

    //-----------------------  Input  -----------------------//

    int VstupMenu(Profily& data, int strana);
    void Rozhodovac(Profily &data, int prikaz, int inkrement = 0);

    //-----------------------  Vykresleni (public)  -----------------------//

    void ProfilVykresleni(Profily& data);
    void TextProfilVykresleni(Profily& data);
    void OtazkaVykresleni();

private:

    //-----------------------  Set  -----------------------//

    void SpodniZavoraSet();
    void OznaceniSet();
    string NazevProfiluSet();

    //-----------------------  Vykresleni (private)  -----------------------//

    void NazevProfiluVykresleni();
    void RamecekSmazani();
};

