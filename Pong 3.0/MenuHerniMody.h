#pragma once
#include "Menu.h"

class MenuHerniMody : public Menu
{
public:

    MenuHerniMody(Profily& data) : Menu(data, hlavni_e, 4, 10, 10, 10)
    {
        Preklad trans;

        MenuHerniModyVykresleni(data);
    }

    //-----------------------  Vykresleni Menu  -----------------------//

    void MenuHerniModyVykresleni(Profily& data);

    //-----------------------  Input  -----------------------//

    int Rozhodovac(Profily& data);


private: ///////////////////////////////////  PRIVATE  /////////////////////////////////////////
    //-----------------------  Vykresleni  -----------------------//

    void TextHerniModyVykresleni(Profily& data);
};