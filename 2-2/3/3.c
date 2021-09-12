#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int main(void)
{
    const int dir[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
    int n;
    while(1)
    {
        printf("the size of square:");
        scanf("%d", &n);
        if(n>0) break;
    }

    int** arr;
    arr=(int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
        arr[i]=(int*)calloc(n, sizeof(int));

    arr[0][0]=1;
    int x=0, y=0, nDir=0, t=1;
    while(t!=n*n)
    {
        int nx=x+dir[nDir][0], ny=y+dir[nDir][1];
        if(!(0<=nx && nx<n && 0<=ny && ny<n) || arr[nx][ny])
        {
            nDir=(nDir+1)%4;
            continue;
        }
        arr[nx][ny]=++t;
        x=nx, y=ny;
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%3d ", arr[i][j]);
        printf("\n");
    }
    for(int i=0; i<n; i++)
        free(arr[i]);
    free(arr);
}