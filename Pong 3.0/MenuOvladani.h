#pragma once
#include "Menu.h"

class MenuOvladani : public Menu
{
public:
    Commands set;
    Profily profil;
    Preklad transl;

    MenuOvladani() : Menu(hlavni_e, 4, 12, 12, 15)
    {
        Preklad trans;
    }

    //-----------------------  Input  -----------------------//

    int VstupMenu(int strana);
    int Rozhodovac(Profily &data, int prikaz);

    //-----------------------  Vykresleni  -----------------------//

    void OvladaniVykresleni(Profily& data);
    void TextOvladaniVykresleni(Profily& data);

private:
};