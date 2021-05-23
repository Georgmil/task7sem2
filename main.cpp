#include "task7sem2.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main()
{
    list *head=NULL;
    list *tail=NULL;


    int zajavka=0,c=0,p=1, q;
    double ev1=0, ev2=0,prostoj=0;
    double a_1=0, a_2=10;
    double b_1=0, b_2=2;
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
                if(head==NULL)
                    prostoj=prostoj+0.001;

                }

            }
            if(q==1){
                printf("\n\n");
                printuem(ev2,prostoj,ozhidanie_max,ozhidanie_sred,zajavka,ozhidanie_maxn,ozhidanie_cikl,head);
                printf("\n");
        }

    return 0;
}
