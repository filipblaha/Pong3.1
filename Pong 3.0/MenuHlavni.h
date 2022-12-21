#pragma once
#include "Menu.h"

class MenuHlavni : public Menu
{
public:

    MenuHlavni(Profily& data) : Menu(data, hlavni_e, 4, 9, 9, 15)
    {
        Preklad trans;

        HlavniVykresleni(data);
    }

    //-----------------------  Input  -----------------------//

    int Rozhodovac(Profily& data);

    //-----------------------  Vykresleni Menu  -----------------------//

    void HlavniVykresleni(Profily& data);

private: ///////////////////////////////////  PRIVATE  /////////////////////////////////////////
    //-----------------------  Vykresleni  -----------------------//

    void LogoHlavniVykresleni();
    void TextHlavniVykresleni(Profily& data);
};