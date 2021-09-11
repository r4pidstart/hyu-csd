#include<stdio.h>
#include<time.h>
#include<stdlib.h>

struct Student
{
    int mid_score; int final_score; char grade;
};

int main(void)
{
    int n;
    while(1)
    {
        printf("How many students:");
        scanf("%d", &n);
        if(5<=n && n<=30) break;
    }
    
    struct Student* arr=(struct Student*)malloc(sizeof(struct Student)*n);
    
    // make rand score for each student
    int ts=0;
    srand(time(NULL));
    for(int i=0; i<n; i++)
        ts+=arr[i].mid_score=(rand()%9+1)*10, ts+=arr[i].final_score=(rand()%9+1)*10;
    
    double avg=(double)ts/n/2;

    for(int i=0; i<n; i++)
    {
        if((arr[i].mid_score+arr[i].final_score)/2.0 > avg) arr[i].grade='P';
        else arr[i].grade='F';
        printf("Student %d's grade is %c\n", i, arr[i].grade);
    }
    
}