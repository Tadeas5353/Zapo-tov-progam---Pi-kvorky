int nahodne_cislo(int N) {
	static bool inicializovano = false;
	if (!inicializovano) {
		std::srand(std::time(nullptr));
		inicializovano = true;
	}
	return std::rand() % N;
}

char abecedni_prevod(int cislo)
{
	return cislo + 64;
}

std::string Tvorpolicko(char znak, int cislo) 
{
	std::string cisloStr = std::to_string(cislo);
	std::string vysledek = znak + cisloStr;
	return vysledek;
}

int mensi(int Prvni, int Druhy) {
	if (Prvni < Druhy)
		return Prvni;
	else
		return Druhy;
};