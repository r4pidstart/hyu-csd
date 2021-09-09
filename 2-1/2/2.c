#include<stdio.h>

int mystrcmp(const char* s1, const char* s2)
{
    int cur=0;
    while(s1[cur]!='\0' || s2[cur]!='\0')
    {
        if(s1[cur] > s2[cur]) return 1;
        if(s1[cur] < s2[cur]) return -1;
        cur++;
    }
    return 0;
}

int main(void)
{
    char s1[10], s2[10];
    printf("First string:");
    scanf("%s", s1);
    printf("Second string:");
    scanf("%s", s2);
    int ret=mystrcmp(s1, s2);
    if(ret==0) printf("Same String\n");
    else if(ret==1) printf("First string is larger.\n");
    else printf("Second string is larger.\n");
}