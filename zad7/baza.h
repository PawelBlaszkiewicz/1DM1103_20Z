#ifndef _BAZA_H
#define _BAZA_H
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct _student
{
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;

    struct _student *nast;
}student;

typedef struct _Przedmiot{
    char * kod_przedmiotu;
    char * nazwa_przedmiotu;
    char * semestr;
    struct _Przedmiot *next;
}Przedmiot;

typedef struct _Ocena
{
    char *nr_albumu;
    char *kod_przedmiotu;
   // student *s;
    char *ocena;
    char *komentarz;
    struct _Ocena *nastep;
}Ocena;


typedef struct _sbaza
{
    struct _student *lista_studentow; //glowa listy
    struct _Przedmiot *lista_przedmiotow;
    struct _Ocena *lista_ocen;

}sbaza;

sbaza * wczytaj_baze(char *nazwa_pliku);


void zapisz_baze(char *nazwa_pliku, sbaza * baza);


void  listuj_studentow(sbaza *baza);

void listuj_przedmioty(sbaza *baza);

void listuj_oceny(sbaza *baza);

student *  dodaj_s(sbaza *baza, char *a, char *b, char *c, char *d);

Przedmiot * dodaj_p(sbaza *baza, char *a, char *b, char *c);

Ocena *  dodaj_o(sbaza *baza, char *a, char *b, char *c, char *d);

void zwolnij(sbaza * baza);

#endif