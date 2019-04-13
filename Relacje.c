#include "Relacje.h"
#include "Drzewo.h"
#include "Lista.h"
#include <stdlib.h>
#include <stdio.h>
//RELACJE

struct Historia *znajdzR(struct Historia *h)
// szukamy elementu ktory ma zapisana energie oraz jest w relacji z historia h
// + kompresja sciezki
{
    struct Historia *pom = h;
    struct Historia *pom1;
    while(pom->ojciecR != NULL)
    {
        pom=pom->ojciecR;
    }
    while(h->ojciecR != NULL)
//podpinamy wszystkie napotkane elementy do tego z zapisana energia
    {
        pom1 = h->ojciecR;
        h->ojciecR = pom;
        if(h->dopuszczalny == 0)
//jesli ktorys z elementow jest niedopuszczalny to jest tez w liscie kosz,
//zwalniamy go i podpinamy odpowiednio sasiadow
        {
            (h->popsmiec)->nastsmiec = h->nastsmiec;
            free(h);
        }
        h = pom1;
    }
    return pom;
}


int zmienEnergie(struct Lista *zapis, struct Historia *h, unsigned long long int energia)
// znajdujemy praojca w relacji i zmieniamy mu energie
{
    if(energia < 1)
    {
        return 0;
    }
    struct Historia *a = znajdzwDrzewie(h, zapis);
    if(a != NULL && a->dopuszczalny == 1)
    {
        a = znajdzR(a);
        a->energia = energia;
        return 1;
    }
    return 0;
// jesli obiekt reprezentujacy zapis nie istnieje lub jest niedopuszczalny zwracamy 0
}

int zrownaj(struct Historia *h, struct Lista *zapisA, struct Lista *zapisB)
// EQUAL historia_a historia_b, zwraca 1 gdy jest OK, 0 gdy nie jest
{
    struct Historia *a = znajdzwDrzewie(h, zapisA);
    struct Historia *b = znajdzwDrzewie(h, zapisB);
    if(a == b && a != NULL && a->dopuszczalny == 1)
//gdy sa takie same nie trzeba nic zmieniac, to nie blad
    {
        return 1;
    }
    if(a != NULL && a->dopuszczalny == 1 && b != NULL && b->dopuszczalny == 1)
//obydwie musza byc dopuszczalne
    {
        a = znajdzR(a);
        b = znajdzR(b);
        unsigned long long int energia;
        if(a == b)
//gdy sa juz w relacji nie trzeba nic zmieniac, to nie blad
        {
            return 1;
        }
        if(a->energia == 0 && b->energia == 0)
//Jesli nie sa w relacji i zadna nie ma energii to blad
        {
            return 0;
        }
        if(a->energia != 0 && b->energia != 0)
//przeliczamy energie, wersja 1
        {
            int c = 0;
            if(a->energia%2 == 1 && b->energia%2 == 1)
            {
                c = 1;
            }
            energia = a->energia/2 + b->energia/2 + c;
        }
        else
        {
            if(a->energia == 0 || b->energia == 0)
//przeliczamy energie, wersja 2
            {
                energia = a->energia + b->energia;
            }
        }
        a->energia = 0;
        a->ojciecR = b;
        b->energia = energia;
        return 1;
    }
    return 0;
//jesli byl blad
}
