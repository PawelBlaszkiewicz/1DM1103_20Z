#include "studenci.h"
#include"dziekanat.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv)
{
    student dane[100];
    int ile;

    ile = wczytaj(dane, argv[1]);


    if(strcmp(argv[2],"student")==0)
    {
        najlepszy_student(dane,ile);
    }
    if(strcmp(argv[2],"najgorsza")==0)
    {
        przedmioty(dane,ile);
    }
    if(strcmp(argv[2],"najlepsza")==0)
    {
        przedmiotnaj(dane,ile);
    }
}