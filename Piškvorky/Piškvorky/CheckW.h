bool zkontroluj_vyhru(char** plocha, int X, int Y, int K_vyhre, int width, int heigth)
{
	char symbol = plocha[Y][X];

	switch (K_vyhre)
	{

	case 3:
		/* Kontrola doprava */
		if (X + 2 < width)
		{
			if (plocha[Y][X + 1] == symbol && plocha[Y][X + 2] == symbol)
			{
				return true;
			}
		}

		/* Kontrola doleva */
		if (X - 2 >= 0)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X - 2] == symbol)
			{
				return true;
			}
		}

		/* Kontrola do stran */
		if (X - 1 >= 0 && X + 1 < width)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X + 1] == symbol)
			{
				return true;
			}
		}

		/* Kontrola nahoru */
		if (Y - 2 >= 0)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y - 2][X] == symbol)
			{
				return true;
			}
		}

		/* Kontrola dolù */
		if (Y + 2 < heigth)
		{
			if (plocha[Y + 1][X] == symbol && plocha[Y + 2][X] == symbol)
			{
				return true;
			}
		}

		/* Kontrola svisle */
		if (Y - 1 >= 0 && Y + 1 < heigth)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y + 1][X] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=X nahoru */
		if (X + 2 < width && Y - 2 >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y - 2][X + 2] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=X dolù */
		if (X - 2 >= 0 && Y + 2 < heigth)
		{
			if (plocha[Y + 1][X - 1] == symbol && plocha[Y + 2][X - 2] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=X */
		if (X - 1 >= 0 && Y + 1 < heigth && X + 1 < width && Y - 1 >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y + 1][X - 1] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=-X nahoru */
		if (X - 2 >= 0 && Y - 2 >= 0)
		{
			if (plocha[Y - 1][X - 1] == symbol && plocha[Y - 2][X - 2] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=-X dolù */
		if (X + 2 < width && Y + 2 < heigth)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y + 2][X + 2] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=X */
		if (X - 1 >= 0 && Y + 1 < heigth && X + 1 < width && Y - 1 >= 0)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y - 1][X - 1] == symbol)
			{
				return true;
			}
		}

		break;

	case 4:

		/* Kontrola doprava */
		if (X + 3 < width)
		{
			if (plocha[Y][X + 1] == symbol && plocha[Y][X + 2] == symbol && plocha[Y][X + 3] == symbol)
			{
				return true;
			}
		}

		/* Kontrola doleva */
		if (X - 3 >= 0)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X - 2] == symbol && plocha[Y][X - 3] == symbol)
			{
				return true;
			}
		}

		/* Kontrola do stran */
		if (X - 2 >= 0 && X + 1 < width)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X - 2] == symbol && plocha[Y][X + 1] == symbol)
			{
				return true;
			}
		}
		if (X - 1 >= 0 && X + 2 < width)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X + 1] == symbol && plocha[Y][X + 2] == symbol)
			{
				return true;
			}
		}

		/* Kontrola nahoru */
		if (Y - 3 >= 0)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y - 2][X] == symbol && plocha[Y - 3][X] == symbol)
			{
				return true;
			}
		}

		/* Kontrola dolù */
		if (Y + 3 < heigth)
		{
			if (plocha[Y + 1][X] == symbol && plocha[Y + 2][X] == symbol && plocha[Y + 3][X] == symbol)
			{
				return true;
			}
		}

		/* Kontrola svisle */
		if (Y - 2 >= 0 && Y + 1 < heigth)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y - 2][X] == symbol && plocha[Y + 1][X] == symbol)
			{
				return true;
			}
		}
		if (Y - 1 >= 0 && Y + 2 < heigth)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y + 1][X] == symbol && plocha[Y + 2][X] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=X nahoru */
		if (X + 3 < width && Y - 3 >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y - 2][X + 2] == symbol && plocha[Y - 3][X + 3] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=X dolù */
		if (X - 3 >= 0 && Y + 3 < heigth)
		{
			if (plocha[Y + 1][X - 1] == symbol && plocha[Y + 2][X - 2] == symbol && plocha[Y + 3][X - 3] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=X */
		if (X - 2 >= 0 && Y + 2 < heigth && X + 2 < width && Y - 1 >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y - 2][X + 2] == symbol && plocha[Y + 1][X - 1] == symbol)
			{
				return true;
			}
		}
		if (X - 1 >= 0 && Y + 1 < heigth && X + 2 < width && Y - 2 >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y + 1][X - 1] == symbol && plocha[Y + 2][X - 2] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=-X nahoru */
		if (X - 3 >= 0 && Y - 3 >= 0)
		{
			if (plocha[Y - 1][X - 1] == symbol && plocha[Y - 2][X - 2] == symbol && plocha[Y - 3][X - 3] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=-X dolù */
		if (X + 3 < width && Y + 3 < heigth)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y + 2][X + 2] == symbol && plocha[Y + 3][X + 3] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=-X */
		if (X - 2 >= 0 && Y + 2 < heigth && X + 1 < width && Y - 1 >= 0)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y + 2][X + 2] == symbol && plocha[Y - 1][X - 1] == symbol)
			{
				return true;
			}
		}
		if (X - 1 >= 0 && Y + 1 < heigth && X + 2 < width && Y - 2 >= 0)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y - 1][X - 1] == symbol && plocha[Y - 2][X - 2] == symbol)
			{
				return true;
			}
		}

		break;

	case 5:

		/* Kontrola doprava */
		if (X + 4 < width)
		{
			if (plocha[Y][X + 1] == symbol && plocha[Y][X + 2] == symbol && plocha[Y][X + 3] == symbol && plocha[Y][X + 4] == symbol)
			{
				return true;
			}
		}

		/* Kontrola doleva */
		if (X - 4 >= 0)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X - 2] == symbol && plocha[Y][X - 3] == symbol && plocha[Y][X - 4] == symbol)
			{
				return true;
			}
		}

		/* Kontrola do stran */
		if (X - 3 >= 0 && X + 1 < width)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X - 2] == symbol && plocha[Y][X - 3] == symbol && plocha[Y][X + 1] == symbol)
			{
				return true;
			}
		}
		if (X - 2 >= 0 && X + 2 < width)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X - 2] == symbol && plocha[Y][X + 1] == symbol && plocha[Y][X + 2] == symbol)
			{
				return true;
			}
		}
		if (X - 1 >= 0 && X + 3 < width)
		{
			if (plocha[Y][X - 1] == symbol && plocha[Y][X + 1] == symbol && plocha[Y][X + 2] == symbol && plocha[Y][X + 3] == symbol)
			{
				return true;
			}
		}

		/* Kontrola nahoru */
		if (Y - 4 >= 0)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y - 2][X] == symbol && plocha[Y - 3][X] == symbol && plocha[Y - 4][X] == symbol)
			{
				return true;
			}
		}

		/* Kontrola dolù */
		if (Y + 4 < heigth)
		{
			if (plocha[Y + 1][X] == symbol && plocha[Y + 2][X] == symbol && plocha[Y + 3][X] == symbol && plocha[Y + 4][X] == symbol)
			{
				return true;
			}
		}

		/* Kontrola svisle */
		if (Y - 3 >= 0 && Y + 1 < heigth)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y - 2][X] == symbol && plocha[Y - 3][X] == symbol && plocha[Y + 1][X] == symbol)
			{
				return true;
			}
		}
		if (Y - 2 >= 0 && Y + 2 < heigth)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y - 2][X] == symbol && plocha[Y + 1][X] == symbol && plocha[Y + 2][X] == symbol)
			{
				return true;
			}
		}
		if (Y - 1 >= 0 && Y + 3 < heigth)
		{
			if (plocha[Y - 1][X] == symbol && plocha[Y + 1][X] == symbol && plocha[Y + 2][X] == symbol && plocha[Y + 3][X] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=X nahoru */
		if (X + 4 < width && Y - 4 >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y - 2][X + 2] == symbol && plocha[Y - 3][X + 3] == symbol && plocha[Y - 4][X + 4] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=X dolù */
		if (X - 4 >= 0 && Y + 4 < heigth)
		{
			if (plocha[Y + 1][X - 1] == symbol && plocha[Y + 2][X - 2] == symbol && plocha[Y + 3][X - 3] == symbol && plocha[Y + 4][X - 4] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=X */
		if (X - 3 >= 0 && Y + 1 < heigth && X + 1 < width && Y - 3 >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y - 2][X + 2] == symbol && plocha[Y - 3][X + 3] == symbol && plocha[Y + 1][X - 1] == symbol)
			{
				return true;
			}
		}
		if (X - 2 >= 0 && Y + 2 < heigth && X + 2 < width && Y - 2 >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y - 2][X + 2] == symbol && plocha[Y + 1][X - 1] == symbol && plocha[Y + 2][X - 2] == symbol)
			{
				return true;
			}
		}
		if (X - 1 >= 0 && Y + 3 < heigth && X + 3 < width && Y - 1 >= 0)
		{
			if (plocha[Y - 1][X + 1] == symbol && plocha[Y + 1][X - 1] == symbol && plocha[Y + 2][X - 2] == symbol && plocha[Y + 3][X - 3] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=-X nahoru */
		if (X - 4 >= 0 && Y - 4 >= 0)
		{
			if (plocha[Y - 1][X - 1] == symbol && plocha[Y - 2][X - 2] == symbol && plocha[Y - 3][X - 3] == symbol && plocha[Y - 4][X - 4] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=-X dolù */
		if (X + 4 < width && Y + 4 < heigth)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y + 2][X + 2] == symbol && plocha[Y + 3][X + 3] == symbol && plocha[Y + 4][X + 4] == symbol)
			{
				return true;
			}
		}

		/* Kontrola po pøímce Y=-X */
		if (X - 3 >= 0 && Y + 3 < heigth && X + 1 < width && Y - 1 >= 0)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y + 2][X + 2] == symbol && plocha[Y + 3][X + 3] == symbol && plocha[Y - 1][X - 1] == symbol)
			{
				return true;
			}
		}
		if (X - 2 >= 0 && Y + 2 < heigth && X + 2 < width && Y - 2 >= 0)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y + 2][X + 2] == symbol && plocha[Y - 1][X - 1] == symbol && plocha[Y - 2][X - 2] == symbol)
			{
				return true;
			}
		}
		if (X - 1 >= 0 && Y + 1 < heigth && X + 3 < width && Y - 3 >= 0)
		{
			if (plocha[Y + 1][X + 1] == symbol && plocha[Y - 1][X - 1] == symbol && plocha[Y - 2][X - 2] == symbol && plocha[Y - 3][X - 3] == symbol)
			{
				return true;
			}
		}

		break;
	}

	return false;
}