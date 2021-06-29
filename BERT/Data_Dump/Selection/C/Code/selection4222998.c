#include<stdlib.h>
#include<stdio.h>

#define LENGTH ((100))
int SelectionSort(int a[], int n)
{
    int minj, v, sw = 0;
    for (int i = 0; i < n -1; i++)
    {
        minj = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minj])
            {
                minj = j;
            }
            
        }
        if (i < minj)
        {
            v = a[i];
            a[i] = a[minj];
            a[minj] = v;
            sw++;    
        }
    }
    return sw;
}

int main()
{
    int n, sw;
    int a[LENGTH];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    sw = SelectionSort(a, n);

    for (int j = 0; j < n; j++)
    {
        if (j > 0)
        {
            printf(" ");
        }
        printf("%d", a[j]);
    }

    printf("\n");
    printf("%d\n", sw);
    
    return 0;
}
