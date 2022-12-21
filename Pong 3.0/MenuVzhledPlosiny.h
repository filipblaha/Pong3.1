#pragma once
#include "Menu.h"

class MenuVzhledPlosiny : public Menu
{
public:

    MenuVzhledPlosiny(Profily& data) : Menu(data, hlavni_e, 6, 9, 9, 13, 6, 26)
    {
        Preklad trans;

        potrebna_uroven = { 0,1,2,3,4,5 };
        skiny = data.NacteniSkiny();

        VzhledPlosinyVykresleni(data);
    }

    //-----------------------  Input  -----------------------//

    int VstupMenu(Profily& data);
    int Rozhodovac(Profily& data);

    //-----------------------  Vykresleni Menu  -----------------------//

    void VzhledPlosinyVykresleni(Profily& data);

private: ///////////////////////////////////  PRIVATE  /////////////////////////////////////////
    vector<int> potrebna_uroven;
    vector<wstring> skiny;

    //-----------------------  Vykresleni  -----------------------//

    void TextVzhledPlosinyVykresleni(Profily& data);
    void SkinyVykresleni(Profily data);
    void OznaceniVykresleni();
    void OznaceniSmazani();
    void NedostatecnaUrovenVykresleni();
};