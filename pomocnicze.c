#ifndef POMOC
#define POMOC
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "pomocnicze.h"

unsigned long long int czyenergia()// zwraca 1 jesli wczytano energie z dobrego zakresu, 0 to blad, ERROR
{
    int a = getchar();
    unsigned int pom;
    unsigned long long int energia = 0;
    while(a > 47 && a < 58)
    {
        for (int i=1; i<10; i++)
        {
            if(ULLONG_MAX - i*energia < energia )
            {
                return 0;
            }
        }
        energia = 10*energia;
        pom = a - 48;
        if(ULLONG_MAX - energia < pom)
        {
            return 0;
        }
        energia = energia + a - 48;
        a = getchar();
    }
    if(a != '\n')
    {
        return 0;
    }
    return energia;
}
int czyslowo(int *tab, int *pom, int n)
// porownuje tablice tab i pom, zwraca 1 jesli sa identyczne do elementu n-tego
{
    for(int i=0; i<n; i++)
    {
        if(pom[i] != tab[i])
        {
            return 0;
        }
    }
    return 1;
}

int znajdzslowo(int *a, int D[], int En[], int V[], int Eq[], int R[])
// 0 gdy blad, liczby od 1 do 5 gdy dobre slowo, a = ' ' na koncu
{
    int tab[7];
    tab[0] = *a;
    int i=1;
    while(*a != ' ' && i<7 && *a != '\n' && *a != EOF)
    {
        *a = getchar();
        tab[i] = *a;
        i++;
    }
    if(*a == '\n' || *a == EOF)
    {
        return 0;
    }
    if(*a == 'E')
    {
        *a = getchar();
// poprawka dla przypadku DECLARE
    }
    while(i<7)
    {
        tab[i] = ' ';
// uzupelniamy reszte aby miec pewnosc ze nie bedzie bledu
        i++;
    }
    if(*a != ' ')
    {
        return 0;
    }
    if(czyslowo(tab, D, 7) == 1)
    {
        return 1;
    }
    if(czyslowo(tab, En, 6) == 1)
    {
        return 2;
    }
    if(czyslowo(tab, V, 5) == 1)
    {
        return 3;
    }
    if(czyslowo(tab, Eq, 5) == 1)
    {
        return 4;
    }
    if(czyslowo(tab, R, 6) == 1)
    {
        return 5;
    }
    return 0;
}
#endif
