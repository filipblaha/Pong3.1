#include "Menu.h"
#include "HerniMody.h"

class Intro : public HerniMody
{
public:

	Intro()
	{
		mic.x_d = mic.x = 1;
		mic.y_d = mic.y = 16;
		bomba.x_d = bomba.x = 13;
		bomba.y_d = bomba.y = 17;
		mic.ax = 1;
		mic.ay = -1;
		bomba.ax = -2;
		bomba.ay = -1;

		set.Prechod(delka, vyska);
		set.SetFont(delka, vyska);
		set.SetWindow(delka, vyska - 2);
		VykresleniStart();
		VykresleniHoupacka(0);
		VykresleniObjekt(bomba_e, bomba.x, bomba.y, bomba.skin);
		VykresleniBlokyIntro();

		Sleep(1000);
		
		IntroDo();
	}
	~Intro()
	{}

	bool IntroDo();

private:
	Menu menu;
	Plosina plosina;
	Mic mic;
	Bomba bomba;
	Commands set;

	int delka = pole.delka + 1;
	int vyska = pole.vyska + 1;

	bool VstupIntro();

	void VykresleniStart();
	void VykresleniHoupacka(int poloha);
	void SmazaniHoupacka();
	void VykresleniBlokyIntro();
	void VykresleniVybuchIntro(int vzdalenost);
	void RozbitiBlokuIntro(int x, int y, int stupen);
	void VykresleniLogoIntro();
};