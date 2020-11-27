#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"wczytaj.h"

struct macierz *suma(struct macierz *m, struct macierz *n)
{
    for(int i=0 ; i< m->r ; i++)
    {
        for(int j=0 ; j< m->c ; j++)
        {
            m->data[i][j] += n->data[i][j];
        }
    }
    return m;
}

struct macierz *roznica(struct macierz *m, struct macierz *n)
{
    for(int i=0 ; i< m->r ; i++)
    {
        for(int j=0 ; j< m->c ; j++)
        {
            m->data[i][j] = m->data[i][j] - n->data[i][j];
        }
    }
    return m;
}

struct macierz *prod(struct macierz *m, struct macierz *n)
{
    struct macierz *k;
    k=(struct macierz*) malloc(sizeof(float));
    k->r = m->r; 
    k->c = n->c; 
    k->data=(float**) malloc(sizeof(float) * k->r);
    for(int i=0;i< k->r;i++)
    {
        k->data[i] = (float*)malloc(sizeof(float) * k->c);
        for(int j=0;j< k->c;j++)
        {
            k->data[i][j] = 0;
        }
    }

    for(int i=0 ; i< m->r ; i++)
    {
        for(int j=0 ; j< n->c ; j++)
        {
            for(int h=0 ; h < m->c ; h++)
            {
            k->data[i][j] = k->data[i][j] + (m->data[i][h] * n->data[h][j]);
            }
        }
    }
    return k;
}

struct macierz *multiply(struct macierz *m, float a)
{
    for(int i=0 ; i< m->r ; i++)
    {
        for(int j=0 ; j< m->c ; j++)
        {
        m->data[i][j] = a * m->data[i][j];
        }
    }
    return m;
}

float norm(struct macierz *m)
{
    float s=0;
    for(int i=0;i< m->r;i++)
    {
        for(int j=0;j< m->c;j++)
        {
            s+= m->data[i][j]*m->data[i][j];
        }
    }
    return sqrt(s);
}