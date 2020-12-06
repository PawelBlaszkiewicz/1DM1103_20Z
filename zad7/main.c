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
    return 0;
}
