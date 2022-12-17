#pragma once
#include "Menu.h"

class MenuNastaveni : public Menu
{
public:
    Commands set;
    Profily profil;
    Preklad transl;

    MenuNastaveni() : Menu(nastaveni_e, 4, 10, 10, 14)
    {
        Preklad trans;

        balic = 0;

        SpodniZavoraSet();
    }

    //-----------------------  Input  -----------------------//

    int Rozhodovac(Profily& data, int prikaz);

    //-----------------------  Vykresleni  -----------------------//

    void NastaveniVykresleni(Profily& data);
    void TextNastaveniVykresleni(Profily& data);

    //-----------------------  Set -----------------------//

    void SpodniZavoraSet();

private:
    bool balic;
};