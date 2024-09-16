int check_win(char** plocha, int X, int Y, int K_vyhre, int width, int heigth, int rozdil)
{
	int pocitadlo = 0;
	char symbol = plocha[Y][X];

	switch (K_vyhre)
	{

	case 3:
		/* Kontrola doprava */
		if (X + 2 < width)
		{
			if (plocha[Y][X + 1] == symbol && plocha[Y][X + 2] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola doleva */
		if (X - 2 >= 0)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X - 2] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola do stran */
		if (X - 1 >= 0 && X + 1 < width)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X + 1] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola nahoru */
		if (Y - 2 >= 0)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y - 2][X] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola dolù */
		if (Y + 2 < heigth)
		{
			if (plocha[Y + 1][X] == symbol && plocha[Y + 2][X] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola svisle */
		if (Y - 1 >= 0 && Y + 1 < heigth)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y + 1][X] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=X nahoru */
		if (X + 2 < width && Y - 2 >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y - 2][X + 2] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=X dolù */
		if (X - 2 >= 0 && Y + 2 < heigth)
		{
			if (plocha[Y + 1][X - 1] == symbol && plocha[Y + 2][X - 2] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=X */
		if (X - 1 >= 0 && Y + 1 < heigth && X + 1 < width && Y - 1 >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y + 1][X - 1] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=-X nahoru */
		if (X - 2 >= 0 && Y - 2 >= 0)
		{
			if (plocha[Y - 1][X - 1] == symbol && plocha[Y - 2][X - 2] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=-X dolù */
		if (X + 2 < width && Y + 2 < heigth)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y + 2][X + 2] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=X */
		if (X - 1 >= 0 && Y + 1 < heigth && X + 1 < width && Y - 1 >= 0)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y - 1][X - 1] == symbol)
			{
				pocitadlo++;
			}
		}

		break;

	case 4:

		/* Kontrola doprava */
		if (X + 3 + rozdil < width)
		{
			if (plocha[Y][X + 1] == symbol && plocha[Y][X + 2] == symbol && plocha[Y][X + 3] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola doleva */
		if (X - 3 - rozdil >= 0)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X - 2] == symbol && plocha[Y][X - 3] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola do stran */
		if (X - 2 - rozdil >= 0 && X + 1 + rozdil < width)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X - 2] == symbol && plocha[Y][X + 1] == symbol)
			{
				pocitadlo++;
			}
		}
		if (X - 1 - rozdil >= 0 && X + 2 + rozdil < width)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X + 1] == symbol && plocha[Y][X + 2] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola nahoru */
		if (Y - 3 - rozdil >= 0)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y - 2][X] == symbol && plocha[Y - 3][X] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola dolù */
		if (Y + 3 + rozdil < heigth)
		{
			if (plocha[Y + 1][X] == symbol && plocha[Y + 2][X] == symbol && plocha[Y + 3][X] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola svisle */
		if (Y - 2 - rozdil >= 0 && Y + 1 + rozdil < heigth)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y - 2][X] == symbol && plocha[Y + 1][X] == symbol)
			{
				pocitadlo++;
			}
		}
		if (Y - 1 - rozdil >= 0 && Y + 2 + rozdil < heigth)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y + 1][X] == symbol && plocha[Y + 2][X] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=X nahoru */
		if (X + 3 + rozdil < width && Y - 3 - rozdil >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y - 2][X + 2] == symbol && plocha[Y - 3][X + 3] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=X dolù */
		if (X - 3 - rozdil >= 0 && Y + 3 + rozdil < heigth)
		{
			if (plocha[Y + 1][X - 1] == symbol && plocha[Y + 2][X - 2] == symbol && plocha[Y + 3][X - 3] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=X */
		if (X - 2 - rozdil >= 0 && Y + 2 + rozdil < heigth && X + 2 + rozdil < width && Y - 1 - rozdil >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y - 2][X + 2] == symbol && plocha[Y + 1][X - 1] == symbol)
			{
				pocitadlo++;
			}
		}
		if (X - 1 - rozdil >= 0 && Y + 1 + rozdil < heigth && X + 2 + rozdil < width && Y - 2 - rozdil >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y + 1][X - 1] == symbol && plocha[Y + 2][X - 2] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=-X nahoru */
		if (X - 3 - rozdil >= 0 && Y - 3 - rozdil >= 0)
		{
			if (plocha[Y - 1][X - 1] == symbol && plocha[Y - 2][X - 2] == symbol && plocha[Y - 3][X - 3] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=-X dolù */
		if (X + 3 + rozdil < width && Y + 3 + rozdil < heigth)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y + 2][X + 2] == symbol && plocha[Y + 3][X + 3] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=-X */
		if (X - 2 - rozdil >= 0 && Y + 2 + rozdil < heigth && X + 1 + rozdil < width && Y - 1 - rozdil >= 0)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y + 2][X + 2] == symbol && plocha[Y - 1][X - 1] == symbol)
			{
				pocitadlo++;
			}
		}
		if (X - 1 - rozdil >= 0 && Y + 1 + rozdil < heigth && X + 2 + rozdil < width && Y - 2 - rozdil >= 0)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y - 1][X - 1] == symbol && plocha[Y - 2][X - 2] == symbol)
			{
				pocitadlo++;
			}
		}

		break;

	case 5:

		/* Kontrola doprava */
		if (X + 4 + rozdil < width)
		{
			if (plocha[Y][X + 1] == symbol && plocha[Y][X + 2] == symbol && plocha[Y][X + 3] == symbol && plocha[Y][X + 4] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola doleva */
		if (X - 4 - rozdil >= 0)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X - 2] == symbol && plocha[Y][X - 3] == symbol && plocha[Y][X - 4] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola do stran */
		if (X - 3 - rozdil >= 0 && X + 1 + rozdil < width)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X - 2] == symbol && plocha[Y][X - 3] == symbol && plocha[Y][X + 1] == symbol)
			{
				pocitadlo++;
			}
		}
		if (X - 2 - rozdil >= 0 && X + 2 + rozdil < width)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X - 2] == symbol && plocha[Y][X + 1] == symbol && plocha[Y][X + 2] == symbol)
			{
				pocitadlo++;
			}
		}
		if (X - 1 - rozdil >= 0 && X + 3 + rozdil < width)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X + 1] == symbol && plocha[Y][X + 2] == symbol && plocha[Y][X + 3] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola nahoru */
		if (Y - 4 - rozdil >= 0)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y - 2][X] == symbol && plocha[Y - 3][X] == symbol && plocha[Y - 4][X] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola dolù */
		if (Y + 4 + rozdil < heigth)
		{
			if (plocha[Y + 1][X] == symbol && plocha[Y + 2][X] == symbol && plocha[Y + 3][X] == symbol && plocha[Y + 4][X] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola svisle */
		if (Y - 3 - rozdil >= 0 && Y + 1 + rozdil < heigth)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y - 2][X] == symbol && plocha[Y - 3][X] == symbol && plocha[Y + 1][X] == symbol)
			{
				pocitadlo++;
			}
		}
		if (Y - 2 - rozdil >= 0 && Y + 2 + rozdil < heigth)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y - 2][X] == symbol && plocha[Y + 1][X] == symbol && plocha[Y + 2][X] == symbol)
			{
				pocitadlo++;
			}
		}
		if (Y - 1 - rozdil >= 0 && Y + 3 + rozdil < heigth)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y + 1][X] == symbol && plocha[Y + 2][X] == symbol && plocha[Y + 3][X] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=X nahoru */
		if (X + 4 + rozdil < width && Y - 4 - rozdil >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y - 2][X + 2] == symbol && plocha[Y - 3][X + 3] == symbol && plocha[Y - 4][X + 4] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=X dolù */
		if (X - 4 - rozdil >= 0 && Y + 4 + rozdil < heigth)
		{
			if (plocha[Y + 1][X - 1] == symbol && plocha[Y + 2][X - 2] == symbol && plocha[Y + 3][X - 3] == symbol && plocha[Y + 4][X - 4] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=X */
		if (X - 3 - rozdil >= 0 && Y + 3 + rozdil < heigth && X + 1 + rozdil < width && Y - 1 - rozdil >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y - 2][X + 2] == symbol && plocha[Y - 3][X + 3] == symbol && plocha[Y + 1][X - 1] == symbol)
			{
				pocitadlo++;
			}
		}
		if (X - 2 - rozdil >= 0 && Y + 2 + rozdil < heigth && X + 2 + rozdil < width && Y - 2 - rozdil >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y - 2][X + 2] == symbol && plocha[Y + 1][X - 1] == symbol && plocha[Y + 2][X - 2] == symbol)
			{
				pocitadlo++;
			}
		}
		if (X - 1 - rozdil >= 0 && Y + 1 + rozdil < heigth && X + 3 + rozdil < width && Y - 3 - rozdil >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y + 1][X - 1] == symbol && plocha[Y + 2][X - 2] == symbol && plocha[Y + 3][X - 3] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=-X nahoru */
		if (X - 4 - rozdil >= 0 && Y - 4 - rozdil >= 0)
		{
			if (plocha[Y - 1][X - 1] == symbol && plocha[Y - 2][X - 2] == symbol && plocha[Y - 3][X - 3] == symbol && plocha[Y - 4][X - 4] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=-X dolù */
		if (X + 4 + rozdil < width && Y + 4 + rozdil < heigth)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y + 2][X + 2] == symbol && plocha[Y + 3][X + 3] == symbol && plocha[Y + 4][X + 4] == symbol)
			{
				pocitadlo++;
			}
		}

		/* Kontrola po pøímce Y=-X */
		if (X - 3 - rozdil >= 0 && Y + 3 + rozdil < heigth && X + 1 + rozdil < width && Y - 1 - rozdil >= 0)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y + 2][X + 2] == symbol && plocha[Y + 3][X + 3] == symbol && plocha[Y - 1][X - 1] == symbol)
			{
				pocitadlo++;
			}
		}
		if (X - 2 - rozdil >= 0 && Y + 2 + rozdil < heigth && X + 2 + rozdil < width && Y - 2 - rozdil >= 0)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y + 2][X + 2] == symbol && plocha[Y - 1][X - 1] == symbol && plocha[Y - 2][X - 2] == symbol)
			{
				pocitadlo++;
			}
		}
		if (X - 1 - rozdil >= 0 && Y + 1 + rozdil < heigth && X + 3 + rozdil < width && Y - 3 - rozdil >= 0)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y - 1][X - 1] == symbol && plocha[Y - 2][X - 2] == symbol && plocha[Y - 3][X - 3] == symbol)
			{
				pocitadlo++;
			}
		}

		break;
	}

	return pocitadlo;
}