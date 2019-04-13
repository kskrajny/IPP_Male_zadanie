#ifndef KOSZH
#define KOSZH
struct Historia *stworzKosz();
//Tworzymy pusty element listy kosz, w tej liscie beda historie wyrzucone z glownego drzewa

void wstawdoSmieci(struct Historia *nowy, struct Historia *smieci);
//wstawia element nowy do listy kosz, przypina za elementem smieci

void zwolnijKosz(struct Historia *h);
//zwalnia pamiec

#endif
