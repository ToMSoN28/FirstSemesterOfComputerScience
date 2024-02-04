#include <stdio.h>
#include <stdlib.h>

int main()
{
    int poz = 0;
    int t[100];
    int m = 0, n = 0;
    int stan = 0;
    int wynik = 0;
    char z;

    printf("Emulgator Maszyny Turinga obliczjacy roznice wlasciwa:\n");
    printf("dla parametrow zakodowanych unarnie\n");
    printf("Postac MT: M=({q0,q1,q2,q3,q4,q5,q6},{0,1},{0,1,B},d,q0,B,0)\n");
    printf("Tablica przejsc:\n");
    printf("---------------------------------------\n");
    printf("| d  |    0     |    1     |    B     |\n");
    printf("---------------------------------------\n");
    printf("| q0 | (q1,B,P) | (q5,B,P) |    --    |\n");
    printf("| q1 | (q1,),P) | (q2,1,P) |    --    |\n");
    printf("| q2 | (q3,1,L) | (q2,1,P) | (q4,B,L) |\n");
    printf("| q3 | (q3,0,L) | (q3,1,L) | (q0,B,P) |\n");
    printf("| q4 | (q4,0,L) | (q4,B,L) | (q6,0,P) |\n");
    printf("| q5 | (q5,B,P) | (q5,B,P) | (q6,B,P) |\n");
    printf("| q6 |    --    |    --    |    --    |\n");
    printf("---------------------------------------\n");


    printf("Podaj dwie liczby aby sprawdzic poprawnosc odemowania:\n");
    printf("m=");
    scanf_s ("%d", &m);
    printf("n=");
    scanf_s("%d", &n);
    if (m + n + 1 > 100)
    {
        printf("Ograniczenie w tasmie! m+n moze wynosic maksymalnie 99!");
        return (1);
    }
    else
    {

        for (int i = 0; i < m; i++)
            t[i] = 0;

        t[m] = 1;

        for (int i = m + 1; i < m + n + 1; i++)
            t[i] = 0;

        t[m + n + 1] = 2;


        printf("\n Wygenerowana tasma: ");
        for (int i = 0; i < m + n + 1; i++)
        {
            printf("%d", t[i]);
        }
        printf("\nNa ekrania wypisane sa opisy chwilowe z zaznaczona czytana komorka\n\n");


        while (0 == 0)
        {
            //wypisanie opisów chwilowych
            for (int i = 0; i < m + n + 2; i++)
            {
                if (i == poz) printf("(");
                if (t[i] != 2)
                {
                    printf("%d", t[i]);
                }
                if (i == poz) printf("q%d)",stan);
            }
            printf("\n");


            if (stan == 0)
            {
                if (t[poz] == 0)
                {
                    stan = 1;   //zmiana stanu
                    t[poz] = 2; //zmiana wartości
                    poz += 1;   //zmaiana komurki
                }
                else if (t[poz] == 1)
                {
                    stan = 5;
                    t[poz] = 2;
                    poz += 1;
                }
                else if (t[poz] == 2)
                {
                    break;
                }
            }
            else if (stan == 1)
            {
                if (t[poz] == 0)
                {
                    stan = 1;
                    t[poz] = 0;
                    poz += 1;
                }
                else if (t[poz] == 1)
                {
                    t[poz] = 1;
                    stan = 2;
                    poz += 1;
                }
                else if (t[poz] == 2)
                {
                    break;
                }
            }
            else if (stan == 2)
            {
                if (t[poz] == 0)
                {
                    stan = 3;
                    t[poz] = 1;
                    poz -= 1;
                }
                else if (t[poz] == 1)
                {
                    stan = 2;
                    t[poz] = 1;
                    poz += 1;
                }
                else if (t[poz] == 2)
                {
                    stan = 4;
                    t[poz] = 2;
                    poz -= 1;
                }
            }
            else if (stan == 3)
            {
                if (t[poz] == 0)
                {
                    stan = 3;
                    t[poz] = 0;
                    poz -= 1;
                }
                else if (t[poz] == 1)
                {
                    stan = 3;
                    t[poz] = 1;
                    poz -= 1;
                }
                else if (t[poz] == 2)
                {
                    stan = 0;
                    t[poz] = 2;
                    poz += 1;
                }
            }
            else if (stan == 4)
            {
                if (t[poz] == 0)
                {
                    stan = 4;
                    t[poz] = 0;
                    poz -= 1;
                }
                else if (t[poz] == 1)
                {
                    stan = 4;
                    t[poz] = 2;
                    poz -= 1;
                }
                else if (t[poz] == 2)
                {
                    stan = 6;
                    t[poz] = 0;
                    poz += 1;
                }
            }
            else if (stan == 5)
            {
                if (t[poz] == 0)
                {
                    stan = 5;
                    t[poz] = 2;
                    poz += 1;
                }
                else if (t[poz] == 1)
                {
                    stan = 5;
                    t[poz] = 2;
                    poz += 1;
                }
                else if (t[poz] == 2)
                {
                    stan = 6;
                    t[poz] = 2;
                    poz += 1;
                }
            }
            else if (stan == 6)
            {
                break;
            }
        }
        for (int i = 1; i < m + n + 1; i++)
        {
            if (t[i] == 0) wynik++;
        }
        printf("roznica wlasciwa wynosi: %d\n", wynik);
        if (m - n == wynik) printf("wynik taki sam jak roznica obliczona arytmetycznie\nwejscie zaakceptowane\n");
        else printf("wynik ROZNY jak roznica obliczona arytmetycznie\n");
    }
}
