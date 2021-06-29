#include <iostream>
#include <stdio.h>

int main()
{
    int N = 0;
    int num[1001];
    int temp = 0;
    int buf = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (num[j-1] > num[j])
            {
                temp = num[j-1];
                num[j-1] = num[j];
                num[j] = temp;
            }
            else
            {
                break;
            }
        }

        for (int k = 0; k < N; k++)
        {
            if (k != N - 1) { printf("%d ", num[k]); }
            else { printf("%d\n", num[k]); }
        }
    }

}
