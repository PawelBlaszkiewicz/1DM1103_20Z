#include"baza.h"
#include<string.h>

student *ostatni(student *glowa)
{
    if(glowa!=NULL){
    while(glowa->nast !=NULL)
        {glowa=glowa->nast;}
    return glowa;}

    else{
        return NULL;
    }
}
student * usun(student *glowa, student *el)
{
    student *c=glowa;
    if(glowa==el)
    {
        glowa=glowa->nast;
    } 
    else
    {
    while(c!= NULL)
    {
        if(c==el)
        {
            c->poprz->nast = c->nast;
            if(c->nast !=NULL)
                c->nast->poprz = c->poprz;

            break;
        }
        c=c->nast;
    }
    }
    c->nast=NULL;
    c->poprz=NULL;
    return glowa;
}
student *najwiekszy(student *el)
{
    student *max=NULL;
    while(el!=NULL)
    {
        if(max==NULL){
            max=el;
        }else{
            if(strcmp(el->nazwisko, max->nazwisko)>0)
            max = el;
        }
        el=el->nast;
    }
    return max;
}
student *najmniejszy(student *el)
{
    student *min=NULL;
    while(el!=NULL)
    {
        if(min==NULL){
            min=el;
        }else{
            if(strcmp(el->nazwisko, min->nazwisko)<0)
            min = el;
        }
        el=el->nast;
    }
    return min;
}
student *sortuj_przez_wybieranie_wgore(student *glowa)
{
    student *ng = NULL;
    student *m;
    student *o=NULL;

    while(glowa!=NULL)
    {
        m=najwiekszy(glowa);
        glowa=usun(glowa,m);

        o = ostatni(ng);
    if(o==NULL)
    {
        ng=m;
    }
    else
    {
        o->nast=m;
        m->poprz=o;
    }

    }
    return ng;
}
student *sortuj_przez_wybieranie_wdol(student *glowa)
{
    student *ng = NULL;
    student *m;
    student *o=NULL;

    while(glowa!=NULL)
    {
        m=najmniejszy(glowa);
        glowa=usun(glowa,m);

        o = ostatni(ng);
    if(o==NULL)
    {
        ng=m;
    }
    else
    {
        o->nast=m;
        m->poprz=o;
    }

    }
    return ng;
}




Przedmiot *ostatnip(Przedmiot *glowa)
{
    if(glowa!=NULL){
    while(glowa->next !=NULL)
        {glowa=glowa->next;}
    return glowa;}

    else{
        return NULL;
    }
}
Przedmiot * usunp(Przedmiot *glowa, Przedmiot *el)
{
    Przedmiot *c=glowa;
    if(glowa==el)
    {
        glowa=glowa->next;
    } 
    else
    {
    while(c!= NULL)
    {
        if(c==el)
        {
            c->pop->next = c->next;
            if(c->next !=NULL)
                c->next->pop = c->pop;

            break;
        }
        c=c->next;
    }
    }
    c->next=NULL;
    c->pop=NULL;
    return glowa;
}
Przedmiot *najmniejszyp(Przedmiot *el)
{
    Przedmiot *max=NULL;
    while(el!=NULL)
    {
        if(max==NULL){
            max=el;
        }else{
            if(strcmp(el->kod_przedmiotu, max->kod_przedmiotu)<0)
            max = el;
        }
        el=el->next;
    }
    return max;
}
Przedmiot *sortuj_przez_wybieranie_przedmioty(Przedmiot *glowa)
{
    Przedmiot *ng = NULL;
    Przedmiot *m;
    Przedmiot *o=NULL;

    while(glowa!=NULL)
    {
        m=najmniejszyp(glowa);
        glowa=usunp(glowa,m);

        o = ostatnip(ng);
    if(o==NULL)
    {
        ng=m;
    }
    else
    {
        o->next=m;
        m->pop=o;
    }

    }
    return ng;
}
Przedmiot *najmniejszypnazwa(Przedmiot *el)
{
    Przedmiot *max=NULL;
    while(el!=NULL)
    {
        if(max==NULL){
            max=el;
        }else{
            if(strcmp(el->nazwa_przedmiotu, max->nazwa_przedmiotu)<0)
            max = el;
        }
        el=el->next;
    }
    return max;
}
Przedmiot *sortuj_przez_wybieranie_przedmiotynazwa(Przedmiot *glowa)
{
    Przedmiot *ng = NULL;
    Przedmiot *m;
    Przedmiot *o=NULL;

    while(glowa!=NULL)
    {
        m=najmniejszypnazwa(glowa);
        glowa=usunp(glowa,m);

        o = ostatnip(ng);
    if(o==NULL)
    {
        ng=m;
    }
    else
    {
        o->next=m;
        m->pop=o;
    }

    }
    return ng;
}


Ocena *ostatnio(Ocena *glowa)
{
    if(glowa!=NULL){
    while(glowa->nastep !=NULL)
        {glowa=glowa->nastep;}
    return glowa;}

    else{
        return NULL;
    }
}

Ocena * flitrujkod(Ocena *glowa, char *kodzik)
{
    Ocena *m=NULL;
    Ocena *n=NULL;
    while(glowa!=NULL)
    {
        if(strcmp(glowa->kod_przedmiotu,kodzik)==0)
        {

        Ocena *nowaglowa;
        nowaglowa=(Ocena*) malloc(sizeof(Ocena));
        nowaglowa->nastep=NULL;
        nowaglowa->poprzedni=NULL;

        if(m == NULL)
            {m = nowaglowa;}
        else
            {
                n=ostatnio(m);
                ostatnio(m)->nastep = nowaglowa;
                nowaglowa->poprzedni = n;
            }

            nowaglowa->nr_albumu=glowa->nr_albumu;
            nowaglowa->kod_przedmiotu=glowa->kod_przedmiotu;
            nowaglowa->ocena=glowa->ocena;
            nowaglowa->komentarz=glowa->komentarz;
        }
        
        glowa=glowa->nastep;
    }

    return m;
}

void wypiszoceny(Ocena *glowa)
{
    Ocena *o = glowa;
    while(o!=NULL)
    {
        printf("%s\n",o->ocena);

        o = o->nastep;
    }
}


Ocena * flitrujstudent(Ocena *glowa, char *kodzik)
{
    Ocena *m=NULL;
    Ocena *n=NULL;
    while(glowa!=NULL)
    {
        if(strcmp(glowa->nr_albumu,kodzik)==0)
        {

        Ocena *nowaglowa;
        nowaglowa=(Ocena*) malloc(sizeof(Ocena));
        nowaglowa->nastep=NULL;
        nowaglowa->poprzedni=NULL;

        if(m == NULL)
            {m = nowaglowa;}
        else
            {
                n=ostatnio(m);
                ostatnio(m)->nastep = nowaglowa;
                nowaglowa->poprzedni = n;
            }

            nowaglowa->nr_albumu=glowa->nr_albumu;
            nowaglowa->kod_przedmiotu=glowa->kod_przedmiotu;
            nowaglowa->ocena=glowa->ocena;
            nowaglowa->komentarz=glowa->komentarz;
        }
        
        glowa=glowa->nastep;
    }

    return m;
}





student * wczytaj_studentow(FILE *fin)
{
    char bufor[255];
    int n,i;
    char *s;
    student *c = NULL;
    student *glowa=NULL;
    fgets(bufor,254, fin);
    sscanf(bufor, "%d", &n);

    for(i=0;i<n;i++)
    {
        student *stud = (student*) malloc(sizeof(student));
        stud->nast = NULL;
        stud->poprz = NULL;

        if(glowa == NULL){
            glowa = stud;
        }
        else{
            c=ostatni(glowa);
            ostatni(glowa)->nast = stud;
            stud->poprz = c;
        }

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
        uzywka->pop=NULL;

        if(jedynka == NULL)
            {jedynka = uzywka;}
        else
            {
                koniec=ostatnip(jedynka);
                ostatnip(jedynka)->next = uzywka;
                uzywka->pop = koniec;
            }
        
        

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
        Ocena *ocenka;
        ocenka=(Ocena*) malloc(sizeof(Ocena));
        ocenka->nastep=NULL;
        ocenka->poprzedni=NULL;

        if(poczatek == NULL)
            {poczatek = ocenka;}
        else
            {
                ostatnia=ostatnio(poczatek);
                ostatnio(poczatek)->nastep = ocenka;
                ocenka->poprzedni = ostatnia;
            }

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