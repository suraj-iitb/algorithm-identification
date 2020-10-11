/* Bubble Sort */
#include <stdio.h>

int main()
{
    int N, i, j, cnt = 0, temp;
    int A[100];

    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    for(i=0; i<N; i++){
        for(j=N-1; j>i; j--){
            if(A[j] < A[j-1]){
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                cnt++;
            }
        }
    }

    for(i=0; i<N; i++){
        if(i>0){ printf(" "); }
        printf("%d", A[i]);
    }
    printf("\n%d\n", cnt);
    return 0;
}
