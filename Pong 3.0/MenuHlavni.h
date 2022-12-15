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

        HlavniVykresleni(JazykSet());
    }
    vector<wstring> text;

    //-----------------------  Input  -----------------------//

    int Rozhodovac(int prikaz);

    //-----------------------  Vykresleni  -----------------------//

    void HlavniVykresleni(int jazyk);
    void TextHlavniVykresleni(int jazyk);

private:
};