#include<stdio.h>
#include<malloc.h>

int main(void)
{
    int n1, n2;
    while(1)
    {
        printf("num_1 integer(<51):");
        scanf("%d", &n1);
        printf("num_2 integer(<51):");
        scanf("%d", &n2);
        if(n1<51 && n2<51) break;
    }
    int* a1, *a2;
    a1=(int*)malloc(n1*sizeof(int)), a2=(int*)malloc(n2*sizeof(int));
    int max=n1>n2 ? n1:n2, c1=0, c2=0, cd=0;
    for(int i=1; i<=max; i++)
    {
        if(n1%i==0 && n2%i==0)
            cd++, a1[c1++]=i, a2[c2++]=i;
        else if(n1%i==0)
            a1[c1++]=i;
        else if(n2%i==0)
            a2[c2++]=i;
    }
    printf("num_1 integer divisor: ");
    for(int i=0; i<c1; i++)
        printf("%d ", a1[i]);
    printf("\n");
    printf("num_2 integer divisor: ");
    for(int i=0; i<c2; i++)
        printf("%d ", a2[i]);
    printf("\n");
    printf("Total common divisor: %d", cd);
}