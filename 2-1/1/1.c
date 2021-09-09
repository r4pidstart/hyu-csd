#include<stdio.h>

int main(void)
{
    char name[30], major[30];
    int studentID;
    
    printf("name:");
    scanf("%[^\n]", name); getchar();
    printf("major:");
    scanf("%[^\n]", major);
    printf("studentID:");
    scanf("%d", &studentID);
    printf("Hello. My name is %s.\nMy major is %s.\nMy student ID is %d.\n", name, major, studentID);    
}