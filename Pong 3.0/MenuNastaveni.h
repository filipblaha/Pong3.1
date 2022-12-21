#pragma once
#include "Menu.h"

class MenuNastaveni : public Menu
{
public:

    MenuNastaveni(Profily& data) : Menu(data, nastaveni_e, 4, 10, 10, 14)
    {
        Preklad trans;

        SpodniZavoraSet(0);

        NastaveniVykresleni(data, 0);
    }

    //-----------------------  Input  -----------------------//

    int Rozhodovac(Profily& data);

    //-----------------------  Vykresleni Menu  -----------------------//

    void NastaveniVykresleni(Profily& data, bool balic);

private: ///////////////////////////////////  PRIVATE  /////////////////////////////////////////
    //-----------------------  Vykresleni  -----------------------//

    void TextNastaveniVykresleni(Profily& data, bool balic);

    //-----------------------  Set -----------------------//

    void SpodniZavoraSet(bool balic);
};