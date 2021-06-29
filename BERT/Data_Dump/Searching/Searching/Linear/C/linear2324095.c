#include<stdio.h>
long int s[10000], t[500];
int n, q;
int searching(int key)
{
    int i=0;

    s[n]=key;

    while(s[i]!=key) i++;

    if(i==n) return 0;
    else return 1;
}
int main()
{
    int i, sum=0;
    long int key;

    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &s[i]);
    scanf("%d", &q);
    for(i=0;i<q;i++)
        scanf("%d", &t[i]);

    for(i=0;i<q;i++)
    {
        key=t[i];
        if(searching(key)) sum++;
    }

    printf("%d\n", sum);

    return 0;
}
