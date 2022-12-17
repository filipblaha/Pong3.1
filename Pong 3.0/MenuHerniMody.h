#pragma once
#include "Menu.h"

class MenuHerniMody : public Menu
{
public:
    Commands set;
    Profily profil;
    Preklad transl;

    MenuHerniMody() : Menu(hlavni_e, 4, 10, 10, 14)
    {
        Preklad trans;
    }

    //-----------------------  Input  -----------------------//

    int Rozhodovac(Profily& data, int prikaz);

    //-----------------------  Vykresleni  -----------------------//

    void MenuHerniModyVykresleni(Profily& data);
    void TextHerniModyVykresleni(Profily& data);

private:
};