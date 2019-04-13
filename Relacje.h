#ifndef RELACJEH
#define RELACJEH
#include "Lista.h"

struct Historia *znajdzR(struct Historia *h);
// szukamy elementu ktory ma zapisana energie oraz jest w relacji z historia h
// + kompresja sciezki

int zmienEnergie(struct Lista *zapis, struct Historia *h, unsigned long long int energia);
// znajdujemy praojca w relacji i zmieniamy mu energie

int zrownaj(struct Historia *h, struct Lista *zapisA, struct Lista *zapisB);
// EQUAL historia_a historia_b, zwraca 1 gdy jest OK, 0 gdy nie jest 

#endif
