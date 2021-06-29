#include<stdlib.h>
#include<stdio.h>

#define LENGTH ((100))
void Trace(int a[], int n)
{
    int i;
    for (int i = 0; i < n; i++) {
        if (i > 0) { 
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
}

void InsertSort(int a[], int n)
{
    int i, j, v;
    for (int i = 1; i < n; i++) {
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        Trace(a, n);
    }
}

int main()
{
    int n, i, j;
    int a[LENGTH];

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    Trace(a, n);
    InsertSort(a, n);

    return 0;
}
