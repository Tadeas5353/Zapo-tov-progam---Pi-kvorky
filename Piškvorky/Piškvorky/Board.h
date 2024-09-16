#include <string>
#include "Pole.h"
#include "CheckW.h"
#include "WCheck.h"
#include "Pboard.h"
#include "Tech.h"
using namespace std;

class hraci_plocha {
public:

	int heigth;
	int width;
	char** plocha;
	int natahu;
	bool dohrano;
	int vitez;
	int Souper;
	int k_vyhre;

	void zaloz() {
		plocha = new char* [heigth];
		for (int i = 0; i < heigth; ++i) {
			plocha[i] = new char[width];
		}

		for (int i = 0; i < heigth; ++i) {
			for (int j = 0; j < width; ++j) {

				plocha[i][j] = 46;
			}
		}
	}

	void vypis() {
		for (int i = 0; i < heigth + 1; ++i)
		{
			if (i == 0)
			{
				for (int j = 0; j < width + 1; ++j) {
					if (j == 0)
					{
						printf("×");
					}
					else
					{
						char pismeno = abecedni_prevod(j);
						printf("%c", pismeno);
					}
				}
			}
			else
			{
				for (int j = 0; j < width + 1; ++j) {
					if (j == 0)
					{
						printf("%d", i - 1);
					}
					else
					{
						printf("%c", plocha[i - 1][j - 1]);
					}
				}
			}
			printf("\n");
		}
	}

	void nekdo_vyhral()
	{
		vitez = natahu;
		dohrano = true;
	}

	policko startovni_tah_bota()
	{
		int pocet_poli;
		int cislo;
		vector <policko> policka;

		for (int i = heigth / 2 - 1; i < heigth / 2 + 1; ++i) {
			for (int j = width / 2 - 1; j < width / 2 + 1; ++j) {
				if (plocha[i][j] == 46)
				{
					policko nove = nove_policko(j + 65, i);
					policka.insert(policka.end(), nove);
				}

			}
		}
		pocet_poli = size(policka);
		cislo = nahodne_cislo(pocet_poli);
		return(policka[cislo]);
	}

	policko nove_policko(int X, int Y)
	{
		policko nove;
		nove.symbol = plocha[Y][X];
		nove.souradnice_x = X;
		nove.souradnice_y = Y;
		return nove;
	}

	policko tah_bota()
	{
		vector <policko> policka = {};
		vector <policko> dobra_pole = {};

		int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
		int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

		for (int i = 0; i < heigth; ++i) {
			for (int j = 0; j < width; ++j) {
				if (plocha[i][j] == 46)
				{
					policko nove = nove_policko(j + 65, i);
					policka.insert(policka.end(), nove);
				}
			}
		}

		int pocet_poli = size(policka);
		int cislo;
		int X;
		int Y;

		switch (Souper)
		{
		case 1:

			cislo = nahodne_cislo(pocet_poli);
			return(policka[cislo]);
			break;

		case 2:

			if (pocet_poli == width * heigth)
			{
				return startovni_tah_bota();
			}

			for (auto i = policka.begin(); i != policka.end();)
			{
				X = i->souradnice_x - 65;
				Y = i->souradnice_y;

				bool smazat = true;

				for (int j = 0; j < 8; ++j) {
					int newX = X + dx[j];
					int newY = Y + dy[j];

					if (newX >= 0 && newX < width && newY >= 0 && newY < heigth) {
						if (plocha[newY][newX] != 46) {
							smazat = false;
							break;
						}
					}
				}

				if (smazat) {
					i = policka.erase(i);
				}
				else {
					++i;
				}
			}

			for (auto i = policka.begin(); i != policka.end();)
			{
				X = i->souradnice_x - 65;
				Y = i->souradnice_y;

				for (int j = 0; j < 8; ++j) {
					int newX = X + dx[j];
					int newY = Y + dy[j];

					if (newX + dx[j] >= 0 && newX + dx[j] < width && newY + dy[j] >= 0 && newY + dy[j] < heigth) {
						if (plocha[newY + dy[j]][newX + dx[j]] == plocha[newY][newX]) {
							policko nove = nove_policko(X + 65, Y);
							dobra_pole.insert(dobra_pole.end(), nove);
						}
					}
				}
				++i;
			}

			policka = pridej_vektor_do_vektoru(dobra_pole, policka, 4);
			dobra_pole.clear();

			for (auto i = policka.begin(); i != policka.end();)
			{
				X = i->souradnice_x - 65;
				Y = i->souradnice_y;

				for (int j = 0; j < 8; ++j) {
					int newX = X + dx[j];
					int newY = Y + dy[j];

					if (newX + 2 * dx[j] >= 0 && newX + 2 * dx[j] < width && newY + 2 * dy[j] >= 0 && newY + 2 * dy[j] < heigth) {
						if (plocha[newY + dy[j]][newX + dx[j]] == plocha[newY][newX] == plocha[newY + 2 * dy[j]][newX + 2 * dx[j]]) {
							policko nove = nove_policko(X + 65, Y);
							dobra_pole.insert(dobra_pole.end(), nove);
						}
					}
				}
				++i;
			}

			policka = pridej_vektor_do_vektoru(dobra_pole, policka, 10);

			pocet_poli = size(policka);
			cislo = nahodne_cislo(pocet_poli);
			return(policka[cislo]);

			break;

		case 3:

			for (auto i = policka.begin(); i != policka.end();)
			{
				X = i->souradnice_x - 65;
				Y = i->souradnice_y;

				bool smazat = true;

				for (int j = 0; j < 8; ++j) {
					int newX = X + dx[j];
					int newY = Y + dy[j];

					if (newX >= 0 && newX < width && newY >= 0 && newY < heigth) {
						if (plocha[newY][newX] != 46) {
							smazat = false;
							break;
						}
					}
				}

				if (smazat) {
					i = policka.erase(i);
				}
				else {
					++i;
				}
			}

			if (pocet_poli == width * heigth)
			{
				return startovni_tah_bota();
			}

			char** zkusebni_plocha;
			char symbol_pocitace;
			char symbol_hrace;
			policko trefa;

			if (natahu == 1)
			{
				symbol_pocitace = 79;
				symbol_hrace = 120;
			}
			else
			{
				symbol_pocitace = 120;
				symbol_hrace = 79;
			}

			/* Ovìøení toho, zda nelze vyhrát */

			bool lze_vyhrat = false;

			for (auto i = policka.begin(); i != policka.end();)
			{
				zkusebni_plocha = pseudoplocha(plocha, width, heigth, i->souradnice_x - 65, i->souradnice_y, symbol_pocitace);
				lze_vyhrat = zkontroluj_vyhru(zkusebni_plocha, i->souradnice_x - 65, i->souradnice_y, k_vyhre, width, heigth);
				if (lze_vyhrat)
				{
					trefa = nove_policko(i->souradnice_x, i->souradnice_y);
					return trefa;
				}
				++i;
			}

			bool souper_muze_vyhrat = false;

			/* Zabrání soupeøi ve výhøe */

			for (auto i = policka.begin(); i != policka.end();)
			{
				souper_muze_vyhrat = false;
				zkusebni_plocha = pseudoplocha(plocha, width, heigth, i->souradnice_x - 65, i->souradnice_y, symbol_hrace);
				souper_muze_vyhrat = zkontroluj_vyhru(zkusebni_plocha, i->souradnice_x - 65, i->souradnice_y, k_vyhre, width, heigth);
				if (souper_muze_vyhrat)
				{
					policko nove = nove_policko(i->souradnice_x, i->souradnice_y);
					dobra_pole.insert(dobra_pole.end(), nove);
				}
				++i;
			}

			pocet_poli = size(dobra_pole);
			if (pocet_poli != 0)
			{
				cislo = nahodne_cislo(pocet_poli);
				return(dobra_pole[cislo]);
			}

			/* Hledání nejlepších tahù */

			dobra_pole.clear();
			lze_vyhrat = false;
			souper_muze_vyhrat = false;
			int kolikrat_lze_vyhrat = 0;
			int j;
			int k;

			if (k_vyhre != 3)
			{
				for (auto i = policka.begin(); i != policka.end();)
				{
					zkusebni_plocha = pseudoplocha(plocha, width, heigth, i->souradnice_x - 65, i->souradnice_y, symbol_pocitace);
					kolikrat_lze_vyhrat = check_win(zkusebni_plocha, i->souradnice_x - 65, i->souradnice_y, k_vyhre - 1, width, heigth, 1);
					policko nove = nove_policko(i->souradnice_x, i->souradnice_y);
					for (k = 0; k < 3000*kolikrat_lze_vyhrat; ++k)
					{
						dobra_pole.insert(dobra_pole.end(), nove);
					}
					++i;
				}

				for (auto i = policka.begin(); i != policka.end();)
				{
					zkusebni_plocha = pseudoplocha(plocha, width, heigth, i->souradnice_x - 65, i->souradnice_y, symbol_hrace);
					kolikrat_lze_vyhrat = check_win(zkusebni_plocha, i->souradnice_x - 65, i->souradnice_y, k_vyhre - 1, width, heigth, 1);
					policko nove = nove_policko(i->souradnice_x, i->souradnice_y);
					for (k = 0; k < 1000*kolikrat_lze_vyhrat; ++k)
					{
						dobra_pole.insert(dobra_pole.end(), nove);
					}
					++i;
				}

				if (k_vyhre == 5)
				{

					for (auto i = policka.begin(); i != policka.end();)
					{
						zkusebni_plocha = pseudoplocha(plocha, width, heigth, i->souradnice_x - 65, i->souradnice_y, symbol_pocitace);
						kolikrat_lze_vyhrat = check_win(zkusebni_plocha, i->souradnice_x - 65, i->souradnice_y, 3, width, heigth, 2);
						policko nove = nove_policko(i->souradnice_x, i->souradnice_y);
						for (k = 0; k < 30*kolikrat_lze_vyhrat; ++k)
						{
							dobra_pole.insert(dobra_pole.end(), nove);
						}
						++i;
					}

					for (auto i = policka.begin(); i != policka.end();)
					{
						zkusebni_plocha = pseudoplocha(plocha, width, heigth, i->souradnice_x - 65, i->souradnice_y, symbol_hrace);
						kolikrat_lze_vyhrat = check_win(zkusebni_plocha, i->souradnice_x - 65, i->souradnice_y, 3, width, heigth, 2);
						policko nove = nove_policko(i->souradnice_x, i->souradnice_y);
						for (k = 0; k < 25*kolikrat_lze_vyhrat; ++k)
						{
							dobra_pole.insert(dobra_pole.end(), nove);
						}
						++i;
					}
				}
			}

			int newX;
			int newY;

			for (auto i = policka.begin(); i != policka.end();)
			{
				X = i->souradnice_x - 65;
				Y = i->souradnice_y;

				for (j = 0; j < 8; ++j) {
					newX = X + dx[j];
					newY = Y + dy[j];

					if (newX >= 0 && newX < width && newY >= 0 && newY < heigth) {
						if (symbol_pocitace == plocha[newY][newX])
						{
							policko nove = nove_policko(X + 65, Y);
							for (k = 0; k < 5; ++k)
							{
								dobra_pole.insert(dobra_pole.end(), nove);
							}
						}
					}
				}
				++i;
			}

			policka = pridej_vektor_do_vektoru(dobra_pole, policka, 1);

			pocet_poli = size(policka);
			cislo = nahodne_cislo(pocet_poli);
			return(policka[cislo]);

			break;
		}
	}
};