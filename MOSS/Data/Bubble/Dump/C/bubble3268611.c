#include <stdio.h>
int main()
{
    int n;
    int A[101];
    int k = 0, cnt = 0, i, tmp;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &A[i]);
    while(k < n)
    {
        for(i = n - 1; i > k; i--)
        {
            if(A[i - 1] > A[i])
            {
                tmp = A[i - 1];
                A[i - 1] = A[i];
                A[i] = tmp;
                cnt++;
            }
        }
        k++;
    }
    for(i = 0; i < n; i++)
    {
        if(i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", cnt);
    return 0;
}
