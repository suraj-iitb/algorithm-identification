/*
        AOJ - ALDS1_2_A
        Date: 20190311
        Author: Mikoron * ♡mikoiwate_351♡
*/

#define N 101

#include<stdio.h>

int main(void) {
        int i, j, n, buf, count;
        int A[N];

        scanf("%d", &n);
        for(i = 0; i < n; i++) {
                scanf("%d", &A[i]);
        }
        count = 0;
        for(i = 0; i < n-1; i++) {
                for(j = n-1; j > i; j--){
                        if(A[j] < A[j-1]) {
                                buf = A[j];
                                A[j] = A[j-1];
                                A[j-1] = buf;
                                count++;
                        }
                }
        }
        for(i = 0; i < n; i++) {
                if(i > 0) printf(" ");
                printf("%d", A[i]);
        }
        printf("\n%d\n", count);
        return 0;
}

