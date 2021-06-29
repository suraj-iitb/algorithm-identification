#include <iostream>
#include <stdio.h>

int main()
{
    int n;
    int count = 0;
    int data[10000];
    int minj;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    // 選択ソート 
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        minj = i;
        for (int j = i; j < n; j++)
        {
            if (data[j] < data[minj])
            {
                minj = j;
            }
        }
        if (minj != i)
        {
            temp = data[minj];
            data[minj] = data[i];
            data[i] = temp;
            count++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", data[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }

    printf("%d\n", count);
}
