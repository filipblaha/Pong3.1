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
        TextNastaveniVykresleni(JazykSet());

    }
    std::vector<std::wstring> text;

    //-----------------------  Input  -----------------------//

    int Rozhodovac(int prikaz);

    //-----------------------  Vykresleni  -----------------------//

    void TextNastaveniVykresleni(int jazyk);

    //-----------------------  Set -----------------------//

    void SpodniZavoraSet();

private:
    bool balic;
};