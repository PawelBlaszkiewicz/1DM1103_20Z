struct macierz{
    int r;
    int c;
    float **data;
};

void uwolnij(struct macierz *m);

struct macierz *wczytaj(FILE *fin);

void wypisz(struct macierz *m);