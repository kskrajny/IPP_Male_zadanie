#ifndef LISTAC
#define LISTAC
#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"

struct Lista *stworzListe(int a)
//Tworzymy liste do zapisu historii, zapisujemy od pierwszego elementu listy
{
    struct Lista *l = malloc(sizeof(struct Lista));
    if(l == NULL)
    {
        return NULL;
    }
    l->nast = NULL;
    l->w = a;
    return l;
}

int wstawdoListy(int a, struct Lista *l)
//wstawia za l, w praktyce uzywamy tylko wsatwiania na koniec listy
{
    l->nast = malloc(sizeof(struct Lista));
    if(l->nast == NULL)
    {
        return 1;
    }
    l->nast->nast = NULL;
    l->nast->w = a;
    return 0;
}

void zwolnijListe(struct Lista *l)
{
    struct Lista *pom;
    while(l != NULL)
    {
        pom = l;
        l=l->nast;
        free(pom);
    }
}

#endif
