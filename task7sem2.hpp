#ifndef TASK7SEM2_HPP_INCLUDED
#define TASK7SEM2_HPP_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>





typedef struct Node{
    int id;
    double obra;
    double poluchili;
    int cikl;
    struct Node *next;
    struct Node *prev;
}list;

void push(list **head,list **tail, int value,double time,double kogda,int kol);
void pop_last(list **tail, list **head);
double randomchik(double a, double b);
double okr(double znachenie);
double vremja(list *tail, double d);
int dob(list *tail);
int length(list *head);
void printuem(double ev2,double prostoj,double ozhidanie_max,double ozhidanie_sred,int zajavka,int ozhidanie_maxn,int ozhidanie_cikl,list *head);



#endif // TASK7SEM2_HPP_INCLUDED
