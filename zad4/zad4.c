#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _student{
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student, *pstudent;

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



void przedmioty(student dane[100], int ile_rekordow)
{
    char nr_przedmiotow[100][10];
    char studenci[100][10];
    int ile_przedmiotow;
    float sumy_ocen[100];
    int sumy_ects[100];
    int i=0;
    int pozycja;
    int naj_pozycja;
    int najgor_pozycja;
    float najlepsza = 0.0f;
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

    for(i=0;i<ile_przedmiotow;i++)
    {
        if(najlepsza < (sumy_ocen[i]/sumy_ects[i]))
        {
            najlepsza =  (sumy_ocen[i]/sumy_ects[i]);
            naj_pozycja = i;
        }

        if(najgorsza > (sumy_ocen[i]/sumy_ects[i]))
        {
            najgorsza = (sumy_ocen[i]/sumy_ects[i]);
            najgor_pozycja = i;
        }
    }

    char najlep[255], najgor[255];
    for(i=0;i<ile_rekordow;i++)
    {
        if(strcmp(nr_przedmiotow[naj_pozycja],dane[i].kod_przed) == 0)
        strncpy(najlep,dane[i].nazwa_przed,254);
    }

    for(i=0;i<ile_rekordow;i++)
    {
        if(strcmp(nr_przedmiotow[najgor_pozycja],dane[i].kod_przed) == 0)
        strncpy(najgor,dane[i].nazwa_przed,254);
    }

    printf("Najlepsza średnia:");
    printf(" %s - %s: %f \n",nr_przedmiotow[naj_pozycja], najlep,
     (sumy_ocen[naj_pozycja]/sumy_ects[naj_pozycja]) );

     printf("Najgorsza średnia:");
    printf(" %s - %s: %f \n",nr_przedmiotow[najgor_pozycja], najgor,
     (sumy_ocen[najgor_pozycja]/sumy_ects[najgor_pozycja]) );

}

int main(int argc, char ** argv)
{
    student dane[100];
    int ile;

    ile=wczytaj(dane, argv[1]);

    przedmioty(dane, ile);
}