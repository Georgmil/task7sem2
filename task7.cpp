#include "task7sem2.hpp"

void push(list **head,list **tail, int value,double time,double kogda,int kol){

        list* newnode=(list*)malloc(sizeof(list));

        newnode->id=value;
        newnode->obra=time;
        newnode->poluchili=kogda;
        newnode->cikl=kol;
        newnode->next=*head;
        newnode->prev=NULL;

        if(*head!=NULL){
            (*head)->prev=newnode;
        }
        else{
            *tail=newnode;
        }
        *head=newnode;

}




void pop_last(list **tail, list **head){

    if((*tail)->prev!=NULL){
        *tail=(*tail)->prev;
        (*tail)->next=NULL;}
    else{
        *head=NULL;
        *tail=NULL;
    }

}

double randomchik(double a, double b){
    double y=(double)rand()/RAND_MAX;
    double rand=roundf(((double)1000*y))/((double)1000);

    double t=a+(b-a)*rand;

    return t;

}


double okr(double znachenie){
    return roundf((double) 1000*znachenie)/(double)1000;
}

double vremja(list *tail, double d){
    if(tail==NULL){
        return 0;
    }
    else{
        double g=d+(tail->obra);
        return (okr(g));}
    }
int dob(list *tail){
    return (tail->cikl)+1;
}

int length(list *head){
    int schetchik = 0;
    list *current = head;
    while (current != NULL)
    {
        schetchik++;
        current = current->next;
    }
    return schetchik;
}

void printuem(double ev2,double prostoj,double ozhidanie_max,double ozhidanie_sred,int zajavka,int ozhidanie_maxn,int ozhidanie_cikl,list *head){
        printf("Programma rabotala %f vremeni\n",ev2);
        printf("Prosttoj bil %f vremeni\n",prostoj);
        printf("Ozhidane max= %f\n",ozhidanie_max);
        printf("Srednee ozhidanie %f\n",ozhidanie_sred/(zajavka*4));
        printf("Nomer samogo dolgo ozhidaemoj zajavki= %d v cikle %d\n",ozhidanie_maxn,ozhidanie_cikl);
        printf("Dlina ocheredi rovna %d\n",length(head));
        printf("Kolichestvo voshedshih zajavok =%d",zajavka);

}


