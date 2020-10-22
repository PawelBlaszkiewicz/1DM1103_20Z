#include<stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[] )
{
    float a = atof(argv[1]);
    printf("Wartość %s do kwadratu to %f.\n",argv[1] ,a*a);
}