#pragma once
#include "Menu.h"

class MenuProfil : public Menu
{
public:
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
    //-----------------------  Input / Output  -----------------------//

    int VstupMenu(Profily& data);
    void Rozhodovac(Profily &data, int prikaz, int inkrement = 0);

    //-----------------------  Vykresleni Menu  -----------------------//

    void ProfilVykresleni(Profily& data);
    void OtazkaVykresleni();
    void OtazkaSmazani();

private: ///////////////////////////////////  PRIVATE  /////////////////////////////////////////
    //-----------------------  Set  -----------------------//

    void SpodniZavoraSet(Profily data);
    void OznaceniSet(Profily data);
    string NazevProfiluSet();

    //-----------------------  Vykresleni  -----------------------//

    void TextProfilVykresleni(Profily& data);
    void ZadejProfilVykresleni();
    void RamecekSmazani();
    void RamecekVykresleni();
};

