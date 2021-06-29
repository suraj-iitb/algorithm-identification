#include <stdio.h>
#define N 100

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    int a[N];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a+i);
    }

    print(a, n);

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i-1;
        while(a[j] > key && j >= 0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        print(a, n);
    }

    return 0;
}

