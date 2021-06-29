#include<stdio.h>

int main(void){
        int i, k, N, tmp, flag, cnt;
        int A[10000];

        scanf("%d", &N);
        for(i=0; i<N; i++){
                scanf("%d", &A[i]);
        }
        cnt = 0;
        flag = 1;
        while(flag){
                flag = 0;
                for(i=N-1; i>0; i--){
                        if(A[i] < A[i-1]){
                                tmp = A[i];
                                A[i] = A[i-1];
                                A[i-1] = tmp;
                                flag = 1;
                                cnt++;
                        }
                }
        }
        for(i=0; i<N-1; i++){
                printf("%d ", A[i]);
        }
        printf("%d\n", A[i]);
        printf("%d\n", cnt);

        return 0;
}
