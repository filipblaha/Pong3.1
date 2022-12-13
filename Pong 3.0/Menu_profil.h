#pragma once
#include "Menu.h"

class Menu_profil : public Menu
{
public:
    Commands set;
    Profily profil;
    Preklad transl;

    Menu_profil() : Menu(profil_e, 10, 8, 8)
    {
        Preklad transl;
      
        SpodniZavoraSet();
        AktualNazevProfiluSTART();
        ProfilVykresleni(JazykSet());
    }
    std::vector<std::wstring> t;

    //-----------------------  Input  -----------------------//

    int VstupMenu(int strana);
    void Rozhodovac(int prikaz, int inkrement = 0);

    //-----------------------  Vykresleni (public)  -----------------------//

    void ProfilVykresleni(int jazyk);
    void TextProfilVykresleni(int jazyk);
    void OtazkaVykresleni();

private:

    //-----------------------  Set  -----------------------//

    void SpodniZavoraSet();
    void OznaceniSet();
    std::string NazevProfiluSet();

    //-----------------------  Vykresleni (private)  -----------------------//

    void NazevProfiluVykresleni();
    void RamecekSmazani();
};

