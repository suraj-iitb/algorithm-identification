#include <stdio.h>
int main()
{
    int n, list[105], temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && list[j] < list[j - 1])
        {
            temp = list[j];
            list[j] = list[j - 1];
            list[j - 1] = temp;
            j = j - 1;
        }
        for (int j = 0; j < n; j++)
        {
            if (j != (n - 1))
            {
                printf("%d ", list[j]);
            }
            else
            {
                printf("%d\n", list[j]);
            }
        }
    }
}

