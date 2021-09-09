#include<stdio.h>

int main(void)
{
    int table[30][30]={};
    printf("Odd num:");
    int n; scanf("%d", &n);
    
    int x=0, y=n/2, i=0;
    while(i!=n*n)
    {
        table[x][y]=++i;

        int nx=x-1, ny=y-1;
        if(nx<0) nx=n-1; 
        if(ny<0) ny=n-1;

        if(table[nx][ny])
            nx=x+1, ny=y;
        
        x=nx, y=ny;
    }

    for(int i=0; i<n; i++)
    {    
        for(int j=0; j<n; j++)
            printf("%03d ", table[i][j]);
        printf("\n");
    }
}