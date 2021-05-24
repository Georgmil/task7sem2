#include "task7sem2.hpp"

void programma(list *head, list *tail,int randik){
    srand(randik);
    int zajavka=0,c=1,p=1, q;
    double ev1=0, ev2=0,prostoj=0;
    double a_1=0, a_2=10;
    double b_1=0, b_2=4;
    double a_st=0,a_en=0;
    double pogreshnost=0.0001;
    double ozhidanie=0, ozhidanie_max=0,ozhidanie_sred=0;
    int ozhidanie_maxn=0,ozhidanie_cikl=0;
    bool zakonchili=false;
    printf("Podrobno ili net, dla 5 zajavok(eto dostatochno chtobi ponjat kak rabotaet programma, 10 slishkom mnogo), DA=1, Net=0: ");
    scanf("%d",&q);
    int kol=1000;
    if(q==1){
        kol=5;
    }


        double t=randomchik(a_1,a_2);
        double d=t;


         while(zajavka<=kol && zakonchili==false){
            if(((t-ev1)>(-pogreshnost))&& ((t-ev1)<pogreshnost) && (zajavka <kol)){ //podumat o vozmozhnoj sookrasjeniej etoj chasti dobaviv ee v else if

                zajavka=zajavka+1;
                double T=randomchik(b_1,b_2);
                if(head==NULL){
                    d=t;
                }

                push(&head,&tail,zajavka,T,t,c);
                if(q==1){
                printf("Na vremeni %f mi poluchil zajavku %d ona budet obrabatovtasa %f vremeni \n",t,head->id,T);
                }
                a_st=t+a_1;
                a_en=t+a_2;
                t=randomchik(a_st,a_en);
                if(q==1){
                printf("Prihod sledujeshej zajavki ozhhidatesa v %f\n",t);}
                }

            else if(((ev2-(vremja(tail,d)))>(-pogreshnost))&& (((ev2-(vremja(tail,d)))<pogreshnost))&&(head!=NULL)){
                ozhidanie=ev2-(tail->poluchili)-(tail->obra);
                if(ozhidanie >=ozhidanie_max){
                    ozhidanie_max=ozhidanie;
                    ozhidanie_maxn=tail->id;
                    ozhidanie_cikl=tail->cikl;}
                ozhidanie_sred+=ozhidanie;

                if(q==1){
                printf("Obrabotka nachatja zajavki %d v %f zaverhila obrabotku v %f, zhdala ona %f \n",tail->id,okr(d),ev2,ozhidanie);
                }
                d=ev2;

                if(tail->cikl<4){
                    push(&head,&tail,tail->id,tail->obra,d,dob(tail));
                    pop_last(&tail,&head);
                }
                else{
                    if(tail->id==100*p){
                        pop_last(&tail,&head);
                        printf("\n\n");
                        printf("Posle vivoda iz sistemi %d zajavki\n",100*p);
                        printuem(ev2,prostoj,ozhidanie_max,ozhidanie_sred,zajavka,ozhidanie_maxn,ozhidanie_cikl,head);
                        p++;

                    }
                    else{
                    pop_last(&tail,&head);}
                }

                if(head==NULL && zajavka==kol)
                    zakonchili=true;
                }

            else{
                ev1=ev1+0.001;
                ev2=ev2+0.001;
                if(head==NULL){
                    prostoj=prostoj+0.001;
                    //printf("IDET PROSTOJ!!!!\n");
                    }

                }

            }
            if(q==1){
                printf("\n\n");
                printuem(ev2,prostoj,ozhidanie_max,ozhidanie_sred,zajavka,ozhidanie_maxn,ozhidanie_cikl,head);
                printf("\n");
        }
}





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


