#pragma once
#include "Menu.h"

class MenuVzhledPlosiny : public Menu
{
public:
    Commands set;
    Profily profil;
    Preklad transl;

    MenuVzhledPlosiny() : Menu(hlavni_e, 6, 9, 9, 13, 6, 26)
    {
        Preklad trans;

        potrebna_uroven = { 0,1,2,3,4,5 };
        NacteniSkiny();
    }

    //-----------------------  Input  -----------------------//

    int VstupMenu(Profily& data, int strana);
    int Rozhodovac(Profily& data, int prikaz);

    //-----------------------  Vykresleni  -----------------------//

    void VzhledPlosinyVykresleni(Profily& data);
    void TextVzhledPlosinyVykresleni(Profily& data);
    void OznaceniVykresleni();
    void OznaceniSmazani();
    void NacteniSkiny();
    void NedostatecnaUrovenVykresleni();

private:
    vector<int> potrebna_uroven;
    vector<wstring> skiny;
};