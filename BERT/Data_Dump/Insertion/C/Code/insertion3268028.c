#include <stdio.h>
int main()
{
    int A[110];
    int n, i, j, v;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &A[i]);
    for(i = 0; i < n; i++)
    {
        if(i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    for(i = 1; i < n; i++)
    {
        v = A[i];
        j = i - 1;
        while(A[j] > v && j >= 0)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        for(j = 0; j < n; j++)
        {
            if(j) printf(" ");
            printf("%d", A[j]);
        }
        printf("\n");
    }
    return 0;
}
