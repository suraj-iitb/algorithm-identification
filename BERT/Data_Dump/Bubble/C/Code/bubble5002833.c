#include <stdio.h>
int N, A[100];
int main() {
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    int i = 0;
    int ifSwapped = 1;
    int swapcnt = 0;
    while (i < N-1 && ifSwapped)
    {
        ifSwapped = 0;
        for (int j = 0; j < N-i-1; j++)
        {
            if (A[j] > A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                swapcnt++;
                ifSwapped = 1;
            }
            
        }
        i++;
    }
    
    for (int i = 0; i < N-1; i++)
    {
        printf("%d ", A[i]);
    }
    printf("%d\n", A[N-1]);
    printf("%d\n", swapcnt);

    return 0;
}
