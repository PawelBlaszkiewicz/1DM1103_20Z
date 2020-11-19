#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"studenci.h"

int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n)
{
    int ile_znalazlem=0;

    for(int i=0;i<n;i++)
    {
        if(znajdz(dane[i].nr_albumu, nr_albumow, ile_znalazlem) == -1)
        {
            strncpy(nr_albumow[ile_znalazlem], dane[i].nr_albumu, 9);
        ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}

void najlepszy_student(student dane[100], int ile_rekordow)
{
    char nr_albumow[100][10];
    char studenci[100][10];
    int ile_studentow;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    float srednie[100];
    int i=0;
    int pozycja;
    int naj_pozycja;
    float najlepsza = 0.0f;

    for(i=0;i<100;i++)
    {
    sumy_wazonych_ocen[i]=0;
    sumy_ects[i]=0;
    }
    
    ile_studentow = znajdz_studentow(nr_albumow, dane, ile_rekordow);

    //for(i=0;i<ile_studentow;i++)
    //{
    //    printf("Student [%d]: %s", i+1, nr_albumu[i]);
    //}
    for(i=0;i<ile_rekordow;i++)
    {
        pozycja = znajdz(dane[i].nr_albumu, nr_albumow, ile_studentow);
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }
/**
    for(i=0; i<ile_rekordow;i++)
    {
        if(sumy_wazonych_ocen[i] != 0){
        printf("Student [%d]: %s - %f:%d - %f\n",i+1,nr_albumow[i], sumy_wazonych_ocen[i], sumy_ects[i],
        sumy_wazonych_ocen[i]/sumy_ects[i]);}
    }
**/
    for(i=0;i<ile_studentow;i++)
    {
        if(najlepsza < (sumy_wazonych_ocen[i]/sumy_ects[i]))
        {
            najlepsza =  (sumy_wazonych_ocen[i]/sumy_ects[i]);
            naj_pozycja = i;
        }
    }

    printf("Najlepszy student:\n");
    printf("Student [%d]: %s - %f \n", naj_pozycja+1,nr_albumow[naj_pozycja], 
     (sumy_wazonych_ocen[naj_pozycja]/sumy_ects[naj_pozycja]) );
}

int znajdz_przedmioty(char nr_przedmiotow[100][10], student dane[100], int n)
{
    int ile_znalazlem=0;

    for(int i=0;i<n;i++)
    {
        if(znajdz_przedmiot(dane[i].kod_przed, nr_przedmiotow, ile_znalazlem) == -1)
        {
            strncpy(nr_przedmiotow[ile_znalazlem], dane[i].kod_przed, 9);
        ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}

void przedmiotnaj(student dane[100], int ile_rekordow)
{
    char nr_przedmiotow[100][10];
    char studenci[100][10];
    int ile_przedmiotow;
    float sumy_ocen[100];
    int sumy_ects[100];
    int i=0;
    int pozycja;
    int naj_pozycja;
    float najlepsza = 0.0f;

    for(i=0;i<100;i++)
    {
    sumy_ocen[i]=0;
    sumy_ects[i]=0;
    }
    
    ile_przedmiotow = znajdz_przedmioty(nr_przedmiotow, dane, ile_rekordow);

    //for(i=0;i<ile_studentow;i++)
    //{
    //    printf("Student [%d]: %s", i+1, nr_albumu[i]);
    //}
    for(i=0;i<ile_rekordow;i++)
    {
        pozycja = znajdz_przedmiot(dane[i].kod_przed, nr_przedmiotow, ile_przedmiotow);
        sumy_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }

 /**   for(i=0; i<ile_rekordow;i++)
    {
        if(sumy_ocen[i] != 0){
        printf("Przedmiot [%d]: %s - %f:%d - %f\n",i+1,nr_przedmiotow[i], sumy_ocen[i], sumy_ects[i],
        sumy_ocen[i]/sumy_ects[i]);}
    }
**/
    for(i=0;i<ile_przedmiotow;i++)
    {
        if(najlepsza < (sumy_ocen[i]/sumy_ects[i]))
        {
            najlepsza =  (sumy_ocen[i]/sumy_ects[i]);
            naj_pozycja = i;
        }
    }

    char najlep[255];
    for(i=0;i<ile_rekordow;i++)
    {
        if(strcmp(nr_przedmiotow[naj_pozycja],dane[i].kod_przed) == 0)
        strncpy(najlep,dane[i].nazwa_przed,254);
    }

    printf("Najlepsza średnia:");
    printf(" %s - %s: %f \n",nr_przedmiotow[naj_pozycja], najlep,
     (sumy_ocen[naj_pozycja]/sumy_ects[naj_pozycja]) );
}

void przedmioty(student dane[100], int ile_rekordow)
{
    char nr_przedmiotow[100][10];
    char studenci[100][10];
    int ile_przedmiotow;
    float sumy_ocen[100];
    int sumy_ects[100];
    int i=0;
    int pozycja;
    int najgor_pozycja;
    float najgorsza = 5.0f;

    for(i=0;i<100;i++)
    {
    sumy_ocen[i]=0;
    sumy_ects[i]=0;
    }
    
    ile_przedmiotow = znajdz_przedmioty(nr_przedmiotow, dane, ile_rekordow);

    //for(i=0;i<ile_studentow;i++)
    //{
    //    printf("Student [%d]: %s", i+1, nr_albumu[i]);
    //}
    for(i=0;i<ile_rekordow;i++)
    {
        pozycja = znajdz_przedmiot(dane[i].kod_przed, nr_przedmiotow, ile_przedmiotow);
        sumy_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }

 /**   for(i=0; i<ile_rekordow;i++)
    {
        if(sumy_ocen[i] != 0){
        printf("Przedmiot [%d]: %s - %f:%d - %f\n",i+1,nr_przedmiotow[i], sumy_ocen[i], sumy_ects[i],
        sumy_ocen[i]/sumy_ects[i]);}
    }
**/
    for(i=0;i<ile_przedmiotow;i++)
    {
        if(najgorsza > (sumy_ocen[i]/sumy_ects[i]))
        {
            najgorsza = (sumy_ocen[i]/sumy_ects[i]);
            najgor_pozycja = i;
        }
    }

    char najgor[255];

    for(i=0;i<ile_rekordow;i++)
    {
        if(strcmp(nr_przedmiotow[najgor_pozycja],dane[i].kod_przed) == 0)
        strncpy(najgor,dane[i].nazwa_przed,254);
    }
     printf("Najgorsza średnia:");
    printf(" %s - %s: %f \n",nr_przedmiotow[najgor_pozycja], najgor,
     (sumy_ocen[najgor_pozycja]/sumy_ects[najgor_pozycja]) );

}