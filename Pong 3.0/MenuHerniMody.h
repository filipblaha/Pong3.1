#pragma once
#include "Menu.h"

class MenuHerniMody : public Menu
{
public:
    Commands set;
    Preklad transl;

    MenuHerniMody(Profily& data) : Menu(data, hlavni_e, 4, 10, 10, 14)
    {
        Preklad trans;

        MenuHerniModyVykresleni(data);
    }

    //-----------------------  Input  -----------------------//

    int Rozhodovac(Profily& data, int prikaz);

    //-----------------------  Vykresleni  -----------------------//

    void MenuHerniModyVykresleni(Profily& data);
    void TextHerniModyVykresleni(Profily& data);

private:
};