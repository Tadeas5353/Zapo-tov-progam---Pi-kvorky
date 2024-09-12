char** pseudoplocha(char** plocha, int sirska, int vyska, int X, int Y, char symbol)
{
	char** nova_plocha;

	nova_plocha = new char* [vyska];
	for (int i = 0; i < vyska; ++i) {
		nova_plocha[i] = new char[sirska];
	}

	for (int i = 0; i < vyska; ++i) {
		for (int j = 0; j < sirska; ++j) {
			nova_plocha[i][j] = plocha[i][j];
		}
	}

	nova_plocha[Y][X] = symbol;

	return nova_plocha;
}