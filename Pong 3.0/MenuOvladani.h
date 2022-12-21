#pragma once
#include "Menu.h"

class MenuOvladani : public Menu
{
public:

    MenuOvladani(Profily& data) : Menu(data, hlavni_e, 4, 12, 12, 15)
    {
        Preklad trans;

        OvladaniVykresleni(data);
    }

    //-----------------------  Input  -----------------------//

    int VstupMenu();
    void Rozhodovac(Profily &data);

    //-----------------------  Vykresleni Menu -----------------------//

    void OvladaniVykresleni(Profily& data);

private: ///////////////////////////////////  PRIVATE  /////////////////////////////////////////
    //-----------------------  Input  -----------------------//

    void ZmenaOvladaniSmazani(int poradi);
    char ZmenaOvladani();

    //-----------------------  Vykresleni  -----------------------//

    void TextOvladaniVykresleni(Profily& data);


    //-----------------------  Znak Check -----------------------//

    vector<wstring> BlbyZnakyCheck(Profily& data);
};