#include <iostream>
#include <stdio.h>

int main()
{
    int n;
    int count = 0;
    int data[10000];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    int flag = 1;
    int i = 0;
    int temp = 0;
    while (flag)
    {
        flag = 0;
        for (int j = n - 1; j > i; j--)
        {
            if (data[j] < data[j-1])
            {
                temp = data[j];
                data[j] = data[j-1];
                data[j - 1] = temp;
                flag = 1;
                count++;
            }
        }
        i++;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", data[i]);
        if (i < n-1)
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
