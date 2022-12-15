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

        MenuHerniModyVykresleni(JazykSet());
    }
    vector<wstring> text;

    //-----------------------  Input  -----------------------//

    int Rozhodovac(int prikaz);

    //-----------------------  Vykresleni  -----------------------//

    void MenuHerniModyVykresleni(int jazyk);
    void TextHerniModyVykresleni(int jazyk);

private:
};