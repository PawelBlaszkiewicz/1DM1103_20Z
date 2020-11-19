#include "studenci.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void wypisz(student dane[100], int n)
{
    int i;
    for(int i=0;i<n;i++)
    {
        printf("Student: %s - %s %s, z przedmiotu [%s] %s za ECTS %d otrzymał %.1f \n",
        dane[i].nr_albumu, dane[i].imie, dane[i].nazwisko,
        dane[i].kod_przed, dane[i].nazwa_przed,
        dane[i].ects, dane[i].ocena
        );
    }
}

int wczytaj(student dane[100], char *fnazwa )
{
    FILE *fin=fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor,1023,fin);
    sscanf(bufor, "%d", &cnt);
    
    //fgets(bufor,1023,fin);
    // fscanf(fin ,"%d", &cnt);

    for(int i=0;i<cnt;i++)
    {
        fgets(bufor , 1023 , fin);
        //  printf("%s", bufor);

        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);

        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przed, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przed, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt;
}

int znajdz_przedmiot(char *szukany_nrp, char nr_przedmiotow[100][10], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(szukany_nrp, nr_przedmiotow[i]) == 0)
        return i;
    }
    return -1;
}

int znajdz(char *szukany_nr, char nr_albumow[100][10], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(szukany_nr, nr_albumow[i]) == 0)
        return i;
    }
    return -1;
}