#pragma once
#include "Menu.h"

class MenuProfil : public Menu
{
public:
    Commands set;
    Preklad transl;
    MenuProfil()
    {}
    MenuProfil(Profily& data) : Menu(data, profil_e, 10, 7, 7)
    {
        Preklad transl;

        SpodniZavoraSet(data);
        oznaceni.at(y) = 7;
        AktualNazevProfilu(data, 0, 0);

        data.VybraniProfilu(0);
        ProfilVykresleni(data);
    }

    //-----------------------  Input  -----------------------//

    int VstupMenu(Profily& data);
    void Rozhodovac(Profily &data, int prikaz, int inkrement = 0);

    //-----------------------  Vykresleni (public)  -----------------------//

    void ProfilVykresleni(Profily& data);
    void RamecekVykresleni();
    void TextProfilVykresleni(Profily& data);
    void OtazkaVykresleni();

private:

    //-----------------------  Set  -----------------------//

    void SpodniZavoraSet(Profily data);
    void OznaceniSet(Profily data);
    string NazevProfiluSet();

    //-----------------------  Vykresleni (private)  -----------------------//

    void ZadejProfilVykresleni();
    void RamecekSmazani();
};

