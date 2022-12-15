#pragma once
#include "Menu.h"

class MenuVzhledPlosiny : public Menu
{
public:
    Commands set;
    Profily profil;
    Preklad transl;

    MenuVzhledPlosiny() : Menu(hlavni_e, 4, 12, 12, 15)
    {
        Preklad trans;

        VzhledPlosinyVykresleni(JazykSet());
    }
    vector<wstring> text;

    bool dostatecna_uroven;

    //-----------------------  Input  -----------------------//

    int VstupMenu(int strana);
    int Rozhodovac(int prikaz);

    //-----------------------  Vykresleni  -----------------------//

    void VzhledPlosinyVykresleni(int jazyk);
    void TextVzhledPlosinyVykresleni(int jazyk);

private:
};