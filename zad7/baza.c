#include"baza.h"
#include<string.h>

student * wczytaj_studentow(FILE *fin)
{
    char bufor[255];
    int n,i;
    char *s;
    student *last_stud = NULL;
    student *glowa=NULL;
    fgets(bufor,254, fin);
    sscanf(bufor, "%d", &n);

    for(i=0;i<n;i++)
    {
        student *stud = (student*) malloc(sizeof(student));
        stud->nast = NULL;

        if(last_stud!= NULL){
            last_stud->nast = stud;
        }
        else
            glowa=stud;
        last_stud = stud;

        fgets(bufor,254, fin);
        s = strtok(bufor,";");
        stud->imie = (char*) malloc(sizeof(char) * strlen(s) + 1);
        strcpy(stud->imie,s);

        s = strtok(NULL,";");
        stud->nazwisko = (char*) malloc(sizeof(char) * strlen(s) + 1);
        strcpy(stud->nazwisko,s);

        s = strtok(NULL,";");
        stud->nr_albumu = (char*) malloc(sizeof(char) * strlen(s) + 1);
        strcpy(stud->nr_albumu,s);

        s = strtok(NULL,"\n");
        stud->email = (char*) malloc(sizeof(char) * strlen(s) + 1);
        strcpy(stud->email,s);
    }

    return glowa;
}

Przedmiot * wczytaj_przedmioty(FILE *fik)
{
    char bufor[255];
    int i,n;
    char * k;
    Przedmiot * jedynka=NULL;
    Przedmiot * koniec=NULL;
    fgets(bufor, 254, fik);
    sscanf(bufor, "%d", &n);

    for(i=0;i<n;i++)
    {
        Przedmiot *uzywka;
        uzywka=(Przedmiot*) malloc(sizeof(Przedmiot));
        uzywka->next=NULL;

        if(koniec != NULL)
            koniec->next=uzywka;
        else
            jedynka=uzywka;
        
        koniec = uzywka;

        fgets(bufor, 254, fik);
        k=strtok(bufor , ";");
        uzywka->kod_przedmiotu=(char*) malloc(sizeof(char)* strlen(k) + 1);
        strcpy(uzywka->kod_przedmiotu,k);

        k=strtok(NULL , ";");
        uzywka->nazwa_przedmiotu=(char*) malloc(sizeof(char)* strlen(k) + 1);
        strcpy(uzywka->nazwa_przedmiotu,k);

        k=strtok(NULL , "\n");
        uzywka->semestr=(char*) malloc(sizeof(char)* strlen(k) + 1);
        strcpy(uzywka->semestr,k);
    }
    return jedynka;
}

Ocena * wczytaj_oceny(FILE *fic)
{
    char bufor[255];
    int n,i;
    Ocena * ostatnia=NULL;
    Ocena * poczatek=NULL;
    char *w;
    fgets(bufor,254, fic);
    sscanf(bufor,"%d", &n);

    for(i=0;i< n; i++)
    {
        Ocena *ocenka = (Ocena*) malloc(sizeof(Ocena));
        ocenka->nastep = NULL;

        if(ostatnia != NULL)
            ostatnia->nastep = ocenka;
        else
            poczatek=ocenka;
        
        ostatnia= ocenka;

        fgets(bufor, 254, fic);
        w= strtok(bufor,";");
        ocenka->nr_albumu=(char*) malloc(sizeof(char)* strlen(w)+1);
        strcpy(ocenka->nr_albumu,w);

        w= strtok(NULL,";");
        ocenka->kod_przedmiotu=(char*) malloc(sizeof(char)* strlen(w)+1);
        strcpy(ocenka->kod_przedmiotu,w);

        w= strtok(NULL,";");
        ocenka->ocena=(char*) malloc(sizeof(char)* strlen(w)+1);
        strcpy(ocenka->ocena,w);

        w= strtok(NULL,"\n");
        ocenka->komentarz=(char*) malloc(sizeof(char)* strlen(w)+1);
        strcpy(ocenka->komentarz,w);

    }
    return poczatek;
}

sbaza * wczytaj_baze(char *nazwa_pliku)
{
    FILE *fin = fopen(nazwa_pliku,"r");
    if(fin == NULL)
    {
        printf("ERRORE\n");
        exit(-1);
    }
    sbaza *baza = (sbaza*) malloc(sizeof(sbaza));
    baza->lista_studentow = wczytaj_studentow(fin);
    baza->lista_przedmiotow = wczytaj_przedmioty(fin);
    baza->lista_ocen = wczytaj_oceny(fin);

    fclose(fin);
    return baza;
}

int ile_studentow(sbaza *baza)
{
    int n=0;
    student *stud = baza->lista_studentow;
    while(stud!=NULL)
    {
        n++;
        stud=stud->nast;
    }
    return n;
}

int ile_przedmiotow(sbaza *baza)
{
    int n=0;
    Przedmiot *przed = baza->lista_przedmiotow;
    while(przed!=NULL)
    {
        n++;
        przed=przed->next;
    }
    return n;
}

int ile_ocen(sbaza *baza)
{
    int n=0;
    Ocena *o = baza->lista_ocen;
    while(o!=NULL)
    {
        n++;
        o=o->nastep;
    }
    return n;
}

void zapisz_studentow(FILE *fout, sbaza *baza)
{
    int n=ile_studentow(baza);
    student *stud = baza->lista_studentow;
    fprintf(fout, "%d\n", n);
    for(int i=0;i<n;i++){
        fprintf(fout, "%s;%s;%s;%s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud=stud->nast;
    }
}

void zapisz_przedmioty(FILE *fout, sbaza *baza)
{
    int n=ile_przedmiotow(baza);
    Przedmiot *przed = baza->lista_przedmiotow;
    fprintf(fout, "%d\n", n);
    for(int i=0;i<n;i++){
        fprintf(fout, "%s;%s;%s\n", przed->kod_przedmiotu, przed->nazwa_przedmiotu, przed->semestr);
       przed=przed->next;
    }
}

void zapisz_oceny(FILE *fout, sbaza *baza)
{
    int n=ile_ocen(baza);
    Ocena *o = baza->lista_ocen;
    fprintf(fout, "%d\n", n);
    for(int i=0;i<n;i++){
        fprintf(fout, "%s;%s;%s;%s\n", o->nr_albumu, o->kod_przedmiotu, o->ocena, o->komentarz);
        o=o->nastep;
    }
}

void zapisz_baze(char *nazwa_pliku, sbaza * baza)
{
    FILE *fout=fopen(nazwa_pliku,"w");
    if(fout==NULL)
    {
        printf("ERRORE\n");
        exit(-1);
    }
    zapisz_studentow(fout, baza);
    zapisz_przedmioty(fout, baza);
    zapisz_oceny(fout, baza);
    fclose(fout);
}

student *  dodaj_s(sbaza *baza, char *a, char *b, char *c, char *d)
{

    student *k = (student*) malloc(sizeof(student));
    k->imie=a;
    k->nazwisko=b;
    k->nr_albumu=c;
    k->email=d;
    k->nast=NULL;
    

    student *it = baza->lista_studentow;
    while(it->nast!=NULL)
    {
        it=it->nast;
    }
    it->nast=k;
    return baza->lista_studentow;
}

Przedmiot * dodaj_p(sbaza *baza, char *a, char *b, char *c)
{
    Przedmiot *k = (Przedmiot*) malloc(sizeof(Przedmiot));
    k->kod_przedmiotu=a;
    k->nazwa_przedmiotu=b;
    k->semestr=c;
    k->next=NULL;

    Przedmiot *it = baza->lista_przedmiotow;
    while(it->next!=NULL)
    {
        it=it->next;
    }
    it->next=k;
    return baza->lista_przedmiotow;
}

Ocena *  dodaj_o(sbaza *baza, char *a, char *b, char *c, char *d)
{

    Ocena *k = (Ocena*) malloc(sizeof(Ocena));
    k->nr_albumu=a;
    k->kod_przedmiotu=b;
    k->ocena=c;
    k->komentarz=d;
    k->nastep=NULL;

    Ocena *it = baza->lista_ocen;
    while(it->nastep!=NULL)
    {
        it=it->nastep;
    }
    it->nastep=k;

    return baza->lista_ocen;
}

void  listuj_studentow(sbaza *baza)
{
    student * stud = baza->lista_studentow;
    int n=ile_studentow(baza);
    printf("%d\n", n);
    while(stud!=NULL)
    {
        printf("%s %s %s %s\n",stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);

        stud= stud->nast;
    }
}

void listuj_przedmioty(sbaza *baza)
{
    Przedmiot *przed = baza->lista_przedmiotow;
    int n=ile_przedmiotow(baza);
    printf("%d\n", n);
    while(przed!=NULL)
    {
        printf("%s %s %s\n", przed->kod_przedmiotu, przed->nazwa_przedmiotu, przed->semestr);

        przed = przed->next;
    }
}

void listuj_oceny(sbaza *baza)
{
    Ocena *o = baza->lista_ocen;
    int n=ile_ocen(baza);
    printf("%d\n", n);
    while(o!=NULL)
    {
        printf("%s %s %s %s\n", o->nr_albumu, o->kod_przedmiotu, o->ocena, o->komentarz);

        o = o->nastep;
    }
}

void zwolnij_studentow(student *stud)
{
    free(stud->imie);
    free(stud->nazwisko);
    free(stud->nr_albumu);
    free(stud->email);
    free(stud);
}

void zwolnij_liste_studentow(student *s)
{
    student *n;
    while(s!=NULL)
    {
        n= s->nast;
        zwolnij_studentow(s);
        s=n;
    }
    free(n);
}

void zwolnij_przedmioty(Przedmiot *xyz)
{
    free(xyz->kod_przedmiotu);
    free(xyz->nazwa_przedmiotu);
    free(xyz->semestr);
    free(xyz);
}

void zwolnij_liste_przedmiotow(Przedmiot *przed)
{
    Przedmiot *p;
    while(przed!=NULL)
    {
        p=przed->next;
        zwolnij_przedmioty(przed);
        przed=p;
    }
    free(p);
}

void zwolnij_oceny(Ocena *o)
{
    free(o->nr_albumu);
    free(o->kod_przedmiotu);
    free(o->ocena);
    free(o->komentarz);
    free(o);
}

void zwolnij_liste_ocen(Ocena *o)
{
    Ocena *p;
    while(o!=NULL)
    {
        p=o->nastep;
        zwolnij_oceny(o);
        o=p;
    }
    free(p);
}

void zwolnij(sbaza *baza)
{
    zwolnij_liste_studentow(baza->lista_studentow);
    zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
    zwolnij_liste_ocen(baza->lista_ocen);
    free(baza);
}