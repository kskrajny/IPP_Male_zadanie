#ifndef POMOC
#define POMOC
int czyslowo(int *tab, int *pom, int n);
// porownuje tablice tab i pom, zwraca 1 jesli sa identyczne do elementu n-tego

int znajdzslowo(int *a, int D[], int En[], int V[], int Eq[], int R[]);
// 0 gdy blad, liczby od 1 do 5 gdy dobre slowo, a = ' ' na koncu

unsigned long long int czyenergia();
// zwraca 1 jesli wczytano energie z dobrego zakresu, 0 to blad, ERROR

#endif
