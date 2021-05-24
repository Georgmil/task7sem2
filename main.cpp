#include "task7sem2.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main()
{
    list *head=NULL;
    list *tail=NULL;
    int z=1;
    int n=1;
    while(n){
        printf("\n\n");
        printf("Chtobi zapustit programmu nazhmite 1:\n");
        scanf("%d",&n);
        switch(n){
        case 1:
            programma(head,tail,z);
            z++;
            break;
        }
    }
return 0;
}







