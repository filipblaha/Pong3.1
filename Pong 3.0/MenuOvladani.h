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

        OvladaniVykresleni(JazykSet());
    }
    std::vector<std::wstring> text;

    //-----------------------  Input  -----------------------//

    int VstupMenu(int strana);
    int Rozhodovac(int prikaz);

    //-----------------------  Vykresleni  -----------------------//

    void OvladaniVykresleni(int jazyk);
    void TextOvladaniVykresleni(int jazyk);

private:
};