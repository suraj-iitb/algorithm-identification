#include <stdio.h>
#define N 100

int main() {
    int i, j, k=0,key;
    int A[N];
    int num;

    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        scanf("%d", &A[i]);
    }

    for (i = 0; i < num; i++) {
        for (j = num-1; j > 0; j--) {
            if (A[j] < A[j - 1]) {
                key = A[j - 1];
                A[j - 1] = A[j];
                A[j] = key;
                k++;
            }
        }
       
    }
    for (i = 0; i < num; i++) {
        printf("%d",A[i]);
        if (i < num-1)printf(" ");
        else printf("\n");
    }
    printf("%d\n", k);

    return 0;

}
