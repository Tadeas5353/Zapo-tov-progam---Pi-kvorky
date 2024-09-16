#include <vector>
using namespace std;

class policko {
public:

	char souradnice_x;
	int souradnice_y;
	char symbol;
};

vector <policko> pridej_vektor_do_vektoru(const vector <policko>& tenhle_pridat, vector <policko>& sem_pridat, int kolikrat)
{
	for (const auto& i : tenhle_pridat)
	{
		for (int j = 0; j < kolikrat; ++j)
		{
			policko nove;
			nove.symbol = i.symbol;
			nove.souradnice_x = i.souradnice_x;
			nove.souradnice_y = i.souradnice_y;
			sem_pridat.push_back(nove);
		}
	}

	return sem_pridat;
}