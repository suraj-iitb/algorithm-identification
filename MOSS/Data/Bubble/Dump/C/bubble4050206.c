#include <stdio.h>
int main()
{
    int n;
    int A[101];
    int x = 0, cnt = 0, i, tmp;
    scanf("%d", &n);



    for(i = 0; i < n; i++) scanf("%d", &A[i]);


    while(x < n)
    {
        for(i = n - 1; i > x; i--)
        {
            if(A[i - 1] > A[i])
            {
                tmp = A[i - 1];
                A[i - 1] = A[i];
                A[i] = tmp;
                cnt++;
            }
        }
        x++;
    }



    for(i = 0; i < n; i++)
    {
        if(i > 0) printf(" ");
        printf("%d", A[i]);
    }


    printf("\n%d\n", cnt);
    return 0;
}

