#pragma once
#include "Menu.h"

class MenuHlavni : public Menu
{
public:
    Commands set;
    Preklad transl;

    MenuHlavni(Profily& data) : Menu(data, hlavni_e, 4, 9, 9, 15)
    {
        Preklad trans;

        HlavniVykresleni(data);
    }

    //-----------------------  Input  -----------------------//

    int Rozhodovac(Profily& data);

    //-----------------------  Vykresleni  -----------------------//

    void HlavniVykresleni(Profily& data);
    void LogoHlavniVykresleni();
    void TextHlavniVykresleni(Profily& data);

private:
};