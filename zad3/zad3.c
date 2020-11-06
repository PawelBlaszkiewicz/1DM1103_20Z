#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

struct macierz 
{
    int r;
    int c;
    float tab[200][200];
};

void wczytaj(FILE *fin,struct macierz *m)
{
    fscanf(fin , "%d" , &m->r);
    fscanf(fin , "%d" , &m->c);
    for(int i=0; i< (*m).r; i++)
    {
        for(int j=0; j<(*m).c; j++)
        {
            fscanf(fin , "%f" , &(*m).tab[i][j]);
        }
    }
}

void wypisz(struct macierz m)
{
    int i,j;
    printf("[");
    for(i=0;i<m.r;i++)
    {
        for(j=0;j<m.c;j++)
        {
            printf("%5.2f", m.tab[i][j]);
        }
    if (i < (m.r-1))
        printf("\n");
    }
    printf(" ]\n");
}

void zapisz(char nazwa[] , struct macierz m)
{
    FILE *fout = fopen(nazwa, "w");
    fprintf(fout, "%d\n%d\n", m.r, m.c);
    for( int i=0; i<m.r; i++)
    {
        for(int j=0;j<m.c;j++)
        {
            fprintf(fout, "%f " , m.tab[i][j]);
        }
        fprintf(fout, "\n");
    }
}

struct macierz suma(struct macierz m, struct macierz n)
{
    struct macierz k;
    k.r=m.r;
    k.c=m.c;
    for(int i=0 ; i<m.r ; i++)
    {
        for(int j=0 ; j<m.c ; j++)
        {
            k.tab[i][j] = m.tab[i][j] + n.tab[i][j];
        }
    }
    return k;
}

struct macierz roznica(struct macierz m, struct macierz n)
{
    struct macierz k;
    k.r=m.r;
    k.c=m.c;
    for(int i=0 ; i<m.r ; i++)
    {
        for(int j=0 ; j<m.c ; j++)
        {
            k.tab[i][j] = m.tab[i][j] - n.tab[i][j];
        }
    }
    return k;
}

struct macierz prod(struct macierz m, struct macierz n)
{
    struct macierz k;
    k.r=m.r;
    k.c=n.c;
    for(int i=0 ; i<m.r ; i++)
    {
        for(int j=0 ; j<n.c ; j++)
        {
            for(int h=0;h<n.c ; h++)
            k.tab[i][j] += m.tab[i][h]*n.tab[h][j];
        }
    }
    return k;
}

struct macierz multiply(struct macierz m, float a)
{
    struct macierz k;
    k.r=m.r;
    k.c=m.c;
    for(int i=0 ; i<m.r ; i++)
    {
        for(int j=0 ; j<m.c ; j++)
        {
        k.tab[i][j] = m.tab[i][j]* a;
        }
    }
    return k;
}

struct macierz norm(struct macierz m)
{
    struct macierz k;
    k.r=1;
    k.c=1;
    float s=0;
    for(int i=0 ; i<m.r ; i++)
    {
        for(int j=0 ; j<m.c ; j++)
        {
            s += m.tab[i][j]*m.tab[i][j];
        }
    }
    k.tab[0][0]= sqrt(s);
    return k;
}



int main(int argc, char *argv[])
{
    FILE *fin;
    FILE *fout;
    fin=fopen("A.txt", "r");
    struct macierz mac1;
    struct macierz mac2;

    if(strcmp(argv[1],"sum") == 0)
    {
        fin=fopen(argv[2], "r");
        wczytaj(fin, &mac1);
        fin=fopen(argv[3], "r");
        wczytaj(fin, &mac2);

        if(mac1.r != mac2.r)
            printf("Macierze %s i %s nie są jednakowych rozmiarów, więc nie można wykonać dodawania\n", argv[2], argv[3]);
        else if(mac1.c != mac2.c)
            printf("Macierze %s i %s nie są jednakowych rozmiarów, więc nie można wykonać dodawania\n", argv[2], argv[3]);
        else
        {
            fin=fopen(argv[2], "r");
            suma(mac1, mac2);
        }
        if(argv[4])
            zapisz(argv[4],suma(mac1, mac2));
        else
            wypisz(suma(mac1, mac2));
    }
    else if(strcmp(argv[1],"subtract") == 0)
    {
        fin=fopen(argv[2], "r");
        wczytaj(fin, &mac1);
        fin=fopen(argv[3], "r");
        wczytaj(fin, &mac2);

        if(mac1.r != mac2.r)
        printf("Macierze %s i %s nie są jednakowych rozmiarów, więc nie można wykonać dodawania\n", argv[2], argv[3]);
        else if(mac1.c != mac2.c)
        printf("Macierze %s i %s nie są jednakowych rozmiarów, więc nie można wykonać dodawania\n", argv[2], argv[3]);
        else
        {
            fin=fopen(argv[2], "r");
            roznica(mac1, mac2);
        }
        if(argv[4])
        zapisz(argv[4],roznica(mac1, mac2));
        else
        wypisz(roznica(mac1, mac2));
    }
    else if(strcmp(argv[1],"prod") == 0)
    {
        fin=fopen(argv[2], "r");
        wczytaj(fin, &mac1);
        fin=fopen(argv[3], "r");
        wczytaj(fin, &mac2);

         if(mac1.c != mac2.r)
        printf("Macierze %s i %s nie są rozmiarów, które kwalifikują się do mnożenia\n", argv[2], argv[3]);
        else
        if(argv[4])
        zapisz(argv[4],prod(mac1, mac2));
        else
        wypisz(prod(mac1, mac2));
    }
    else if(strcmp(argv[1],"multiply") == 0)
    {
        fin=fopen(argv[2], "r");
        wczytaj(fin, &mac1);

        if(argv[4])
        zapisz(argv[4],multiply(mac1, atof(argv[3])));
        else
        wypisz(multiply(mac1, atof(argv[3])));
    }
    else if(strcmp(argv[1],"norm") == 0)
    {
        fin=fopen(argv[2], "r");
        wczytaj(fin, &mac1);

        if(argv[3])
        zapisz(argv[3],norm(mac1));
        else
        wypisz(norm(mac1));
    }
}