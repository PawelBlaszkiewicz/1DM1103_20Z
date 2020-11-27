#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include"wczytaj.h"


void uwolnij(struct macierz *m)
{
    for(int i=0;i<m->r;i++)
    {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

struct macierz *wczytaj(FILE *fin)
{
    struct macierz *m;
    m=(struct macierz*) malloc(sizeof(float));
    fscanf(fin, "%d", &m->r); 
    fscanf(fin, "%d", &m->c); 
    m->data=(float**) malloc(sizeof(float) * m->r);
    for(int i=0;i<m->r;i++)
    {
        m->data[i] = (float*)malloc(sizeof(float) * m->c);
        for(int j=0;j<m->c;j++)
        {
            fscanf( fin,"%f", &m->data[i][j]);
        }
    }
    fclose(fin);
    return m;
}

void wypisz(struct macierz *m)
{
    
    int i,j;
    for(i=0;i<m->r;i++)
    {
        for(j=0;j<m->c;j++)
        {
            printf("%.1f ", m->data[i][j]);
        }
        printf("\n");
    }
}

void zapisz(char *nazwa, struct macierz *m){
    FILE * fout = fopen(nazwa, "w");
    fprintf(fout, "%d\n%d\n", m->r ,m->c);
    for(int i=0;i<m->r;i++)
    {
        for(int j=0;j<m->c;j++)
        {
            fprintf(fout,"%.2f ", m->data[i][j]);
        }
        fprintf(fout, "\n");
    }
    fclose(fout);
}