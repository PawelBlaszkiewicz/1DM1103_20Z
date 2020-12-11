#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"baza.h"


int main(int argc, char **argv)
{
    sbaza *baza;
    baza = wczytaj_baze(argv[1]);

    if(strcmp("list_students", argv[2]) == 0)
    {
        listuj_studentow(baza);
        if(argv[3])
        zapisz_baze(argv[3], baza);
        zwolnij(baza);
    }
    
    else if(strcmp("add_student", argv[2])==0)
    {
        baza->lista_studentow = dodaj_s(baza, argv[3], argv[4], argv[5], argv[6]);
        if(argv[7])
        zapisz_baze(argv[7], baza);
        zwolnij(baza);
    }

    else if(strcmp("add_course", argv[2])==0)
    {
        baza->lista_przedmiotow=dodaj_p(baza, argv[3], argv[4], argv[5]);
        if(argv[6])
        zapisz_baze(argv[6], baza);
        zwolnij(baza);
    }

    else if(strcmp("add_student_to_course", argv[2])==0)
    {
        baza->lista_ocen=dodaj_o(baza, argv[3], argv[4], argv[5], argv[6]);
        if(argv[7])
        zapisz_baze(argv[7], baza);
        zwolnij(baza);
    }

    else if(strcmp("sort+_students", argv[2])==0)
    {
        baza->lista_studentow=sortuj_przez_wybieranie_wgore(baza->lista_studentow);
        listuj_studentow(baza);
        if(argv[3])
        zapisz_baze(argv[3], baza);
        zwolnij(baza);
    }

    else if(strcmp("sort-_students", argv[2])==0)
    {
        baza->lista_studentow=sortuj_przez_wybieranie_wdol(baza->lista_studentow);
        listuj_studentow(baza);
        if(argv[3])
        zapisz_baze(argv[3], baza);
        zwolnij(baza);
    }

    else if(strcmp("sort_course_cod", argv[2])==0)
    {
        baza->lista_przedmiotow=sortuj_przez_wybieranie_przedmioty(baza->lista_przedmiotow);
        listuj_przedmioty(baza);
        if(argv[3])
        zapisz_baze(argv[3], baza);
        zwolnij(baza);
    }

    else if(strcmp("sort_course_name", argv[2])==0)
    {
        baza->lista_przedmiotow=sortuj_przez_wybieranie_przedmiotynazwa(baza->lista_przedmiotow);
        listuj_przedmioty(baza);
        if(argv[3])
        zapisz_baze(argv[3], baza);
        zwolnij(baza);
    }

    else if(strcmp("choose_marks_bycode", argv[2])==0)
    {
        baza->lista_ocen=flitrujkod(baza->lista_ocen, argv[3]);
        printf("Oceny z Przedmiotu o kodzie %s to:\n", baza->lista_ocen->kod_przedmiotu);
        wypiszoceny(baza->lista_ocen);
        if(argv[4])
        zapisz_baze(argv[4], baza);
        zwolnij(baza);
    }

    else if(strcmp("choose_marks_bystudent", argv[2])==0)
    {
        baza->lista_ocen=flitrujstudent(baza->lista_ocen, argv[3]);
        printf("Oceny studenta z albumem %s to:\n", baza->lista_ocen->nr_albumu);
        wypiszoceny(baza->lista_ocen);
        if(argv[4])
        zapisz_baze(argv[4], baza);
        zwolnij(baza);
    }

    return 0;
}
