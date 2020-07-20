#include <cstdio>

#define Swap(a, b) ((a)^=(b),(b)^=(a),(a)^=(b))

int main()
{
    int N ,cnt;
    scanf (" %d", &N);
    int A[N];
    
    for (int i = 0; i < N; i++){
        scanf (" %d", &A[i]);
    }

    cnt = 0;
    for (int i = 0; i <= N - 1; i++){
        for (int j = N - 1; j >= i + 1; j--){
            if (A[j] < A[j-1]){
                cnt++;
                Swap(A[j], A[j-1]);
            }
        }
    }

    for (int i = 0; i < N; i++){
        if (i != N - 1){
            printf("%d ", A[i]);
        }
        if (i == N - 1){
            printf("%d\n", A[i]);
        }
    }

    printf("%d\n", cnt);
    
    return 0;
}
