#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include"wczytaj.h"
#include"matma.h"

int main(int argc, char *argv[])
{
    FILE *fin;
    FILE *fout;
    fin=fopen("A.txt", "r");
    struct macierz *mac1;
    struct macierz *mac2;
    struct macierz *ils;

    if(strcmp(argv[1],"sum") == 0)
    {
        fin=fopen(argv[2], "r");
        mac1=wczytaj(fin);
        fin=fopen(argv[3], "r");
        mac2=wczytaj(fin);

        if(mac1->r != mac2->r)
            printf("Macierze %s i %s nie są jednakowych rozmiarów, więc nie można wykonać dodawania\n", argv[2], argv[3]);
        else if(mac1->c != mac2->c)
            printf("Macierze %s i %s nie są jednakowych rozmiarów, więc nie można wykonać dodawania\n", argv[2], argv[3]);
        
        if(argv[4]){
            zapisz(argv[4],suma(mac1, mac2));
            uwolnij(mac1);
            uwolnij(mac2);}
        else{
            wypisz(suma(mac1, mac2));
            uwolnij(mac1);
            uwolnij(mac2);}
    }
    else if(strcmp(argv[1],"subtract") == 0)
    {
        fin=fopen(argv[2], "r");
        mac1=wczytaj(fin);
        fin=fopen(argv[3], "r");
        mac2=wczytaj(fin);

        if(mac1->r != mac2->r)
        printf("Macierze %s i %s nie są jednakowych rozmiarów, więc nie można wykonać dodawania\n", argv[2], argv[3]);
        else if(mac1->c != mac2->c)
        printf("Macierze %s i %s nie są jednakowych rozmiarów, więc nie można wykonać dodawania\n", argv[2], argv[3]);
        
        if(argv[4]){
        zapisz(argv[4],roznica(mac1, mac2));
        uwolnij(mac1);
            uwolnij(mac2);}
        else{
        wypisz(roznica(mac1, mac2));
        uwolnij(mac1);
            uwolnij(mac2);}
    }
    else if(strcmp(argv[1],"prod") == 0)
    {
        fin=fopen(argv[2], "r");
        mac1=wczytaj(fin);
        fin=fopen(argv[3], "r");
        mac2=wczytaj(fin);

         if(mac1->c != mac2->r)
        printf("Macierze %s i %s nie są rozmiarów, które kwalifikują się do mnożenia\n", argv[2], argv[3]);
        else if(argv[4]){
        zapisz(argv[4],prod(mac1, mac2));
        uwolnij(mac1);
        uwolnij(mac2);}
        else{
        wypisz(prod(mac1, mac2));
        uwolnij(mac1);
        uwolnij(mac2);}
    }
    else if(strcmp(argv[1],"multiply") == 0)
    {
        fin=fopen(argv[2], "r");
        mac1=wczytaj(fin);

        mac1=multiply(mac1, atof(argv[3]));
        if(argv[4]){
        zapisz(argv[4],mac1);
        uwolnij(mac1);}
        else{
        wypisz(mac1);
        uwolnij(mac1);}
    }
    else if(strcmp(argv[1],"norm") == 0)
    {
        fin=fopen(argv[2], "r");
        mac1=wczytaj(fin);

        if(argv[3])
        {FILE *fout=fopen(argv[3], "w");
        fprintf(fout, "%f\n", norm(mac1));
        fclose(fout);
        uwolnij(mac1);}
        else{
        printf("%f\n", norm(mac1));
        uwolnij(mac1);}
    }
}