#include <stdio.h>
int main()
{
    int n, cnt = 0;
    int A[110];
    int i, j, tmp, pos;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &A[i]);
    for(i = 0; i < n; i++)
    {
        pos = i;
        for(j = i + 1; j < n; j++)
        {
            if(A[j] < A[pos]) pos = j;
        }
        if(A[i] > A[pos])
        {
            tmp = A[i];
            A[i] = A[pos];
            A[pos] = tmp;
            cnt++;
        }
    }
    for(i = 0; i < n; i++)
    {
        if(i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", cnt);
    return 0;
}
