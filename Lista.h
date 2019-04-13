#ifndef LISTAH
#define LISTAH

struct Lista{
struct Lista *nast;
int w;
};

struct Lista *stworzListe(int a);
//Tworzymy liste do zapisu historii, zapisujemy od pierwszego elementu listy

int wstawdoListy(int a, struct Lista *l);
//wstawia za l, w praktyce uzywamy tylko wsatwiania na koniec listy

void zwolnijListe(struct Lista *l);

#endif


