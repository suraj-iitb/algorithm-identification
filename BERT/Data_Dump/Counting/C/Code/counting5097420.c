#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main()
{
    unsigned short *a, *b;

    int c[VMAX + 1];
    int n;

    scanf("%d", &n);

    a = malloc(sizeof(short) * n + 1);
    b = malloc(sizeof(short) * n + 1);

    for(int i = 0; i <= VMAX; i++) c[i] = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%hu",&a[i+1]);
        c[a[i+1]]++;
    }

    for(int i = 1; i <= VMAX; i++) c[i] = c[i] + c[i-1];

    for(int j = 1; j <= n; j++)
    {
        b[c[a[j]]] = a[j];
        c[a[j]]--;
    }

    for(int i = 1; i <= n;i++)
    {
        if(i > 1) printf(" ");
        printf("%d",b[i]);
    }
    printf("\n");

    return 0;

}
