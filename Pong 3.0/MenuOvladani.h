#pragma once
#include "Menu.h"

class MenuOvladani : public Menu
{
public:
    Commands set;
    Preklad transl;

    MenuOvladani(Profily& data) : Menu(data, hlavni_e, 4, 12, 12, 15)
    {
        Preklad trans;

        OvladaniVykresleni(data);
    }

    //-----------------------  Input  -----------------------//

    int VstupMenu();
    void Rozhodovac(Profily &data);

    void ZmenaOvladaniSmazani(int poradi);
    char ZmenaOvladani();

    //-----------------------  Vykresleni  -----------------------//

    void OvladaniVykresleni(Profily& data);
    void TextOvladaniVykresleni(Profily& data);

private:

    //-----------------------  Znak Check -----------------------//

    vector<wstring> BlbyZnakyCheck(Profily& data);
};