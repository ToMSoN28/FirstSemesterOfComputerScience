#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int tab[42][20];
	int hp = 41;
	int n=5;
	int pos = 0;

	srand(time(NULL));

	//instrukcja
	printf("Program wypisze n lancuchow gramatyki bezkontekstowej\n");
	printf("opisanej S->aS|abS|e\n");
	printf("Podaj liczbê lancuchow. Maxymalna liczba lancuchow to 20!\n");
	printf("n=");

	scanf_s ("%d", &n);

	while (n > 20)
	{
		printf("za duza wartosc n! Maxymalna to 20!\nn=");
		scanf_s("%d", &n);
	}
	//tworzenie tablicy
	for (int i = 0; i < n; i++)
	{
		tab[hp][i] = 0;
		pos = 0;
		for (int j = 0; j < i; j++)
		{
			if (rand() % 2 == 0)
			{
				tab[pos][i] = 1;
				pos++;
				tab[hp][i]++;
			}
			else
			{
				tab[pos][i] = 1;
				tab[pos+1][i] = 2;
				pos=pos+2;
				tab[hp][i] += 2;
			}
		}
		tab[pos][i] = 3;
	}



	//sortowanie wielkoœciowe
	for (int i = 1; i < n; i++)
	{
		int tmp = tab[hp][i];
		for (int j = i - 1; tab[hp][j] > tmp; j--)
		{
			for (int k = 0; k < hp; k++)
			{
				tmp = tab[k][j];
				tab[k][j] = tab[k][j+1];
				tab[k][j+1] = tmp;
			}
			tmp = tab[hp][j];
			tab[hp][j] = tab[hp][j + 1];
			tab[hp][j + 1] = tmp;
			
		}
	}

	//sortowanie tablicy alf
	int pomoc = 0;
	for (int i = 0; i < n-1; i++)
	{
		if (tab[hp][i] == tab[hp][i+1])
		{
			for (int j = 0; j < tab[hp][i]; j++)
			{
				if (tab[j][i] < tab[j][i + 1]) break;
				if (tab[j][i] > tab[j][i+1])
				{
					for (int k = 0; k < tab[hp][i]; k++)
					{
						pomoc = tab[k][i];
						tab[k][i] = tab[k][i+1];
						tab[k][i+1] = pomoc;
					}
					break;
				}
			}
			//i--;
		}
	}


	//drukowanie tabloicy
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		printf("%d.	", i);
		while (tab[j][i] != 3)
		{
			if (tab[j][i] == 1) printf("a");
			if (tab[j][i] == 2) printf("b");
			j++;
		}
		printf("	\n");
	}
}