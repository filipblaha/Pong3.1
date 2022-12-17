#pragma once
#include "Menu.h"

class MenuHlavni : public Menu
{
public:
    Commands set;
    Profily profil;
    Preklad transl;

    MenuHlavni() : Menu(hlavni_e, 4, 10, 10, 14)
    {
        Preklad trans;
    }

    //-----------------------  Input  -----------------------//

    int Rozhodovac(Profily& data, int prikaz);

    //-----------------------  Vykresleni  -----------------------//

    void HlavniVykresleni(Profily& data);
    void TextHlavniVykresleni(Profily& data);

private:
};