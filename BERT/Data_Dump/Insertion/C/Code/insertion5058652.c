#include <stdio.h>

int main()
{
    int i, j, v, a;
    int N[100];

    scanf("%d", &a);
    for (i = 0; i < a; i++)
    {
        scanf("%d", &N[i]);
        printf("%d", N[i]);
        if (i != a - 1)
            printf(" ");
    }
    printf("\n");

    for (i = 1; i < a; i++)
    {
        v = N[i];
        j = i - 1;
        while (j >= 0 && N[j] > v)
        {
            N[j + 1] = N[j];
            j--;
        }
        N[j + 1] = v;
        for(j=0;j<a;j++){
        printf("%d",N[j]);
        if (j != a - 1)
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}
