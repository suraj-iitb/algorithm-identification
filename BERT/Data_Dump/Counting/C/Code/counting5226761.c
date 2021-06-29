#include <stdio.h>
#include <stdlib.h>
#define MAX 10005

void countSort(int a[], int n)
{
    int *a_copy = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) a_copy[i] = a[i];
    int c[MAX];
    for (int i = 0; i < MAX; i++) c[i] = 0;

    for (int i = 0; i < n; i++)
    {
        c[a[i]]++;
    }

    for (int i = 1; i < MAX; i++) c[i] = c[i-1] + c[i];

    for (int i = n-1; i >= 0; i--)
    {
        a[c[a_copy[i]]-1] = a_copy[i];
        c[a_copy[i]]--;
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int *a = malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++) scanf("%hu", &a[i]);
    countSort(a, n);
    for (int i = 0; i < n; i++)
    {
        if (i) printf(" ");
        printf("%hu", a[i]);
    }
    printf("\n");
    return 0;
}
