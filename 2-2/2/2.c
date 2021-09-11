#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int ansNum[3], usrRes[3];

void makeAns(void)
{
    srand(time(NULL));
    ansNum[0]=rand()%9+1;
    do ansNum[1]=rand()%9+1; 
    while(ansNum[0]==ansNum[1]);
    do ansNum[2]=rand()%9+1;
    while(ansNum[0]==ansNum[1] || ansNum[1]==ansNum[2] || ansNum[0]==ansNum[2]);
}

void getRes(void)
{
    while(1)
    {
        printf("jon (Three different numbers from 1 to 9):");
        scanf("%1d%1d%1d", &usrRes[0], &usrRes[1], &usrRes[2]);
        if(usrRes[0]!=usrRes[1] && usrRes[1]!=usrRes[2] && usrRes[0]!=usrRes[2]) break;
    }
}

void printRes(int sc, int bc)
{
    printf("%d strike(s) %d ball(s)\n", sc, bc);
}

int checkAns(void)
{
    printf("%d %d %d", usrRes[0], usrRes[1], usrRes[2]);
    int sc=0, bc=0;
    for(int i=0; i<3; i++)
        if(ansNum[i]==usrRes[i]) sc++;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(i!=j && ansNum[i]==usrRes[j]) bc++;
    printRes(sc, bc);
    return sc;
}

int main(void)
{
    makeAns();
    while(1)
    {
        getRes();
        int sc=checkAns();
        if(sc==3) break;
    }
    printf("Right!");
}