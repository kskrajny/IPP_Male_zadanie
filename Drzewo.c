#ifndef DRZEWOC
#define DRZEWOC
#include "Drzewo.h"
#include "Lista.h"
#include "Kosz.h"
#include <stdlib.h>

// DRZEWO
struct Historia *stworzDrzewo()
//Tworzymy pusty korzen drzewa historii
{
    struct Historia *h = malloc(sizeof(struct Historia));
    if(h == NULL)
    {
        return NULL;
    }
    for(int i=0; i<4; i++)
    {
        h->potomkowie[i] = NULL;
    }
    h->energia = 0;
    h->dopuszczalny = -1;
// tylko korzen ma dopuszczalnosc -1
    h->ojciecR = NULL;
    return h;
}

struct Historia *stworzHistorie()
//tworzymy obiekt typu Historia
{
    struct Historia *h = malloc(sizeof(struct Historia));
    if(h == NULL)
    {
        return NULL;
    }
    for(int i=0; i<4; i++)
    {
        h->potomkowie[i] = NULL;
    }
    h->energia = 0;
    h->dopuszczalny = 1;
    h->ojciecR = NULL;
    return h;
}

int wstawdoDrzewa(struct Lista *zapis, struct Historia *h, struct Historia *kosz)
//Declare, zwraca 1 jesli malloc dal NULLa,
//wstawia do listy smieci, aby pozniej pozna bylo zwolnic pamiec bez rekurencji
{

    struct Historia *pom;
    while(zapis != NULL)
//zapis to lista w ktorej zawarty jest zapis historii
    {
        int a = zapis->w;
        pom = h->potomkowie[a];
        if(pom == NULL)
        {
            h->potomkowie[a] = stworzHistorie();
            h = h->potomkowie[a];
	    wstawdoSmieci(h, kosz);
            if(h == NULL)
            {
                return 1;
            }
        }
        else
        {
            h = h->potomkowie[a];
        }
        zapis = zapis->nast;
    }
    return 0;
}

struct Historia *znajdzwDrzewie(struct Historia *h, struct Lista *zapis)
// zwraca szukana historie lub NULLa jak po drodze takiego napotka
{
    while(zapis != NULL)
    {
        h = h->potomkowie[zapis->w];
        zapis = zapis->nast;
        if(h == NULL)
        {
            return NULL;
        }
    }
    return h;
}


void odznaczDrzewo(struct Historia *h, struct Lista *zapis)
//Remove, odcina od drzewa
{
    while(zapis->nast!=NULL && h!=NULL)
    {
        h = h->potomkowie[zapis->w];
        zapis = zapis->nast;
    }
    if(h!= NULL)
    {
        h->potomkowie[zapis->w] = NULL;
    }
}
#endif

