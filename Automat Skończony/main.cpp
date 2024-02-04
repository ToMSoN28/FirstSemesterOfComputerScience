#include <stdio.h>
#include "winbgi2.h"
#include <stdlib.h>

int ilec(int liczba)
{
	int i = 1;
	for (i; liczba > 1; i++)
	{
		liczba = liczba / 10;
	}
	return (i);
}

int zmianaStanu(int v[],int q , int i)
{
	int nq;
	if (q == 3 && v[i] == 0) nq = 1;
	if (q == 3 && v[i] == 1) nq = 2;

	if (q == 1 && v[i] == 0) nq = 3;
	if (q == 1 && v[i] == 1) nq = 0;

	if (q == 0 && v[i] == 0) nq = 2;
	if (q == 0 && v[i] == 1) nq = 1;

	if (q == 2 && v[i] == 0) nq = 0;
	if (q == 2 && v[i] == 1) nq = 3;

	return (nq);
}

void stan3()			//FUNKCJE GRAFICZNE
{
	circle(400, 400, 50);
	outtextxy(395, 395, "q3");
}

void stan1()			//FUNKCJE GRAFICZNE
{
	circle(400, 100, 50);
	outtextxy(395, 95, "q1");
}

void stan0()			//FUNKCJE GRAFICZNE
{
	circle(100, 100, 50);
	outtextxy(95, 95, "q0");
}

void stan2()			//FUNKCJE GRAFICZNE
{
	circle(100, 400, 50);
	circle(100, 400, 45);
	outtextxy(95, 395, "q2");
}


void grafistan(int q)   //FUNKCJE GRAFICZNE
{
	if (q == 0) stan0();
	if (q == 1) stan1();
	if (q == 2) stan2();
	if (q == 3) stan3();
}

void graf()   //FUNKCJE GRAFICZNE
{
	setgray(1);
	{//przejœcie 23
		line(150, 400, 350, 400);
		line(150, 400, 200, 350);
		line(150, 400, 200, 450);
		line(350, 400, 300, 350);
		line(350, 400, 300, 450);
		outtextxy(245, 375, "'1'");
	}
	{//przejscie 01
		line(150, 100, 350, 100);
		line(150, 100, 200, 50);
		line(150, 100, 200, 150);
		line(350, 100, 300, 50);
		line(350, 100, 300, 150);
		outtextxy(245, 105, "'1'");
	}
	{//przejscie 02
		line(100, 150, 100, 350);
		line(100, 150, 50, 200);
		line(100, 150, 150, 200);
		line(100, 350, 50, 300);
		line(100, 350, 150, 300);
		outtextxy(105, 245, "'0'");
	}
	{//przejœcie 13
		line(400, 150, 400, 350);
		line(400, 150, 350, 200);
		line(400, 150, 450, 200);
		line(400, 350, 350, 300);
		line(400, 350, 450, 300);
		outtextxy(370, 245, "'0'");
	}
	{
		stan3();
		stan2();
		stan1();
		stan0();
		outtextxy(380, 455, "START");
	}
	
}

void main()
{
	char licz[CHAR_MAX];
	int liczba=0;
	int n;
	int *v;
	int q, nq;

	char* wczytaj = licz;
	printf("Wczytaj ciag: ");
	do
	{
		*wczytaj = getchar();
		wczytaj++;
	}
	while (*(wczytaj-1) != '\n');

	*wczytaj = 0;

	graphics(500, 500); //przestrzeñ graficzna


	q = 3;	//stan pocz¹tkowy
	n = 0;
	while (licz[n]==48 || licz[n]==49)
	{
		n++;
	}
	v = (int*)malloc(n * sizeof(int));
	for (int i = n - 1; i >= 0; i--)	//zamiana wczytanej liczby na tablicê
	{
		v[i] = licz[i]-48;
	}

	printf("Stan poczatkowy to: %d\n", q);
	animate(1);
	graf();
	setcolor(0.5);
	stan3();
	for (int i = 0; i < n; i++)
	{
		animate(1);
		graf();
		nq = zmianaStanu(v, q, i);
		printf("Wartosc przejsca: %d	", v[i]);
		printf("Stan: %d\n", nq);
		setcolor(0.5);
		grafistan(nq);
		q = nq;
	}
	graf();
	setcolor(0.5);
	grafistan(q);
	animate(1);
	if (q==2) printf("Ciag zaakceptowany");
	else printf("Ciag NIEzaakceptowany\nAktualny stan to: q%d jest zaznaczony na zielono",q);
	wait();
}