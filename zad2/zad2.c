#include<stdlib.h>
#include<stdio.h>
 int main()
 {
     int a,b;
     float k,l;
     FILE *fin;
     fin=fopen("A.txt", "r");
     fscanf(fin, "%d", &a);
     fscanf(fin, "%d", &b);

     FILE *fic;
     fic=fopen("x.txt", "r");
     int c,d;
     fscanf(fic, "%d", &c);
     fscanf(fic, "%d", &d);

     char wektor[c];
    for(int i=0;i<c;i++)
    {
        fscanf(fic,"%f",&l);
        wektor[i]=l;
    }

    float tab[2][3];
    float suma=0;
    printf("(3) [");
     for (int i = 0; i<3;   )
     {
         for(int j = 0; j<2;   )
         {
             fscanf(fin, "%f", &k);
             suma=(k*wektor[j])+suma;
             j++;
         }
         printf("%.1f ",suma);
        i++;
        suma=0;
     }
     printf("]\n");
 }