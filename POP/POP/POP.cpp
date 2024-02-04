#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char listaA[10][20];
	char listaB[10][20];
	char ciagA[200];
	char ciagB[200];
	int ileelel = 0;
	int ilei = 0;
	int indx[20];

	printf("Do programu nalezy wprowadzic dwie listy a nastepnie ciag indeksow\nprogram sprawdzi czy utworzone ciagi sa takie same oraz wypisze je na ekranie.\n\n");

	printf("Podaj liczbe elemantow list: ");
	scanf_s("%d", &ileelel);

	for (int i = 0; i < ileelel; i++)
	{
		printf("%d. elemant listy A: ", i+1);
		scanf_s("%s", listaA[i],19);
	}
	printf("\n");
	for (int i = 0; i < ileelel; i++)
	{
		printf("%d. elemant listy B: ", i+1);
		scanf_s("%s", listaB[i],19);
	}

	printf("\nPodaj liczbe indexow: ");
	scanf_s("%d", &ilei);

	for (int i = 0; i < ilei; i++)
	{
		printf("%d. index: ", i+1);
		scanf_s("%d", &indx[i]);
	}

	strcpy_s(ciagA, listaA[indx[0]-1]);
	strcpy_s(ciagB, listaB[indx[0]-1]);
	for (int i = 1; i < ilei; i++)
	{
		strcat_s(ciagA, listaA[indx[i]-1]);
		strcat_s(ciagB, listaB[indx[i]-1]);
	}

	printf("\nCiag powstaly z listy A: %s\n", ciagA);
	printf("Ciag powstaly z listy B: %s\n", ciagB);

	if (strcmp(ciagA, ciagB) != 0) printf("Ciagi sa nie zgodne\n");
	else printf("Ciagi sa zgodne\n");
}

