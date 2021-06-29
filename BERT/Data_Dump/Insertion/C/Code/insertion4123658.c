#include <stdio.h>
#define N 100

int main()
{
    int a;
    int i;
    int array[N];

    scanf("%d", &a);
    for (i = 0; i < a; i++)
    {
        scanf("%d", &array[i]);
    }

    for (i = 1; i <= a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            printf("%d", array[j]);
            if (j != a - 1)
                printf(" ");
        }
        printf("\n");
        int k = i;
        while (array[k - 1] >= array[k])
        {
            int temp = array[k-1];
            array[k - 1] = array[k];
            array[k] = temp;
            k--;
            if(k==0) break;
        }
    }
    return 0;
}
