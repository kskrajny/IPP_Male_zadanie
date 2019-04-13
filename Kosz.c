#include <stdlib.h>
#include <stdio.h>
#include "Kosz.h"
#include "Drzewo.h"

struct Historia *stworzKosz()
//Tworzymy pusty element listy kosz, w tej liscie beda historie wyrzucone z glownego drzewa
{
    struct Historia *kosz= malloc(sizeof(struct Historia));
    if(kosz == NULL)
    {
        return NULL;
    }
    kosz->popsmiec = NULL;
    kosz->nastsmiec = NULL;
    return kosz;
}

void wstawdoSmieci(struct Historia *nowy, struct Historia *smieci)
//wstawia element nowy do listy kosz, przypina za elementem smieci
{
    struct Historia *pom = smieci->nastsmiec;
    smieci->nastsmiec = nowy;
    nowy->popsmiec = smieci;
    nowy->nastsmiec = pom;
}

void zwolnijKosz(struct Historia *h)
{
    struct Historia *pom;
    while(h != NULL)
    {
        pom = h;
        h=h->nastsmiec;
        free(pom);
    }
}

