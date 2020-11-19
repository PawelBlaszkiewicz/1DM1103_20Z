typedef struct student{
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student;

int wczytaj( student dane[100], char *fnazwa );

int znajdz_przedmiot(char *szukany_nrp, char nr_przedmiotow[100][10], int n);

int znajdz(char *szukany_nr, char nr_albumow[100][10], int n);

void wypisz( student dane[100], int n);