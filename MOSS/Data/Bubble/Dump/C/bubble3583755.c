// Bubble sort
#include <stdio.h>

int bubble_sort(int *A, int N)
{
    int flag = 1, i = 0, cnt = 0;
    int j, tmp;
    while(flag){
        flag = 0;
        for(j=N-1; j>=i+1; j--){
            if(A[j] < A[j-1]){
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
                cnt++;
            }
        }
        i++;
    }
    return cnt;
}

int main(void)
{
    int n, i;
    int cnt = 0;
    scanf("%d", &n);
    int A[n];
    for(i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    cnt = bubble_sort(A, n);
    for(i=0; i<n; i++){
        if(i==n-1){
            printf("%d", A[i]);
        }else{
            printf("%d ", A[i]);
        }
    }
    printf("\n");
    printf("%d\n", cnt);

    return 0;
}
