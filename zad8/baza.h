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

    struct _student *poprz;
    struct _student *nast;
}student;

typedef struct _Przedmiot{
    char * kod_przedmiotu;
    char * nazwa_przedmiotu;
    char * semestr;

    struct _Przedmiot *pop;
    struct _Przedmiot *next;
}Przedmiot;

typedef struct _Ocena
{
    char *nr_albumu;
    char *kod_przedmiotu;
   // student *s;
    char *ocena;
    char *komentarz;
    struct _Ocena *poprzedni;
    struct _Ocena *nastep;
}Ocena;


typedef struct _sbaza
{
    struct _student *lista_studentow; //glowa listy
    struct _Przedmiot *lista_przedmiotow;
    struct _Ocena *lista_ocen;

}sbaza;

sbaza * wczytaj_baze(char *nazwa_pliku);




student *ostatni(student *glowa);
student * usun(student *glowa, student *el);
student *najwiekszy(student *el);
student *sortuj_przez_wybieranie_wgore(student *glowa);
student *najmniejszy(student *el);
student *sortuj_przez_wybieranie_wdol(student *glowa);



Przedmiot *ostatnip(Przedmiot *glowa);
Przedmiot * usunp(Przedmiot *glowa, Przedmiot *el);
Przedmiot *najmniejszyp(Przedmiot *el);
Przedmiot *sortuj_przez_wybieranie_przedmioty(Przedmiot *glowa);
Przedmiot *najmniejszypnazwa(Przedmiot *el);
Przedmiot *sortuj_przez_wybieranie_przedmiotynazwa(Przedmiot *glowa);


Ocena * flitrujkod(Ocena *glowa, char *kodzik);
void wypiszoceny(Ocena *glowa);
Ocena * flitrujstudent(Ocena *glowa, char *kodzik);




void zapisz_baze(char *nazwa_pliku, sbaza * baza);


void  listuj_studentow(sbaza *baza);

void listuj_przedmioty(sbaza *baza);

void listuj_oceny(sbaza *baza);

student *  dodaj_s(sbaza *baza, char *a, char *b, char *c, char *d);

Przedmiot * dodaj_p(sbaza *baza, char *a, char *b, char *c);

Ocena *  dodaj_o(sbaza *baza, char *a, char *b, char *c, char *d);

void zwolnij(sbaza * baza);

#endif