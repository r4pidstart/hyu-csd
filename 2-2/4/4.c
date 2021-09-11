#include<stdio.h>

int num[10];
void getComb(int n, int r, int c, int now)
{
    if(now>n) return;
    if(c==r)
    {
        for(int i=0; i<r; i++)
            printf("%d ", num[i]);
        printf("\n");
        return;
    }
    for(int i=now+1; i<=n; i++)
    {
        num[c]=i;
        getComb(n,r,c+1,i); 
    }
}

int main(void)
{
    int n,k;
    while(1)
    {
        printf("n:"); scanf("%d", &n);
        printf("k:"); scanf("%d", &k);
        if((4<=n && n<=10) && (1<=k && k<=n)) break;    
    }
    getComb(n,k,0,0);
}