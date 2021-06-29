#include <stdio.h>
#define N 100

int main() {
    int i, j, k=0, min,key;
    int A[N];
    int num;

    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        scanf("%d", &A[i]);
    }

    for (i = 0; i < num; i++) {
        min = i;
        for (j = i; j < num; j++) {
            if (A[min] > A[j])min = j;
        }
        if (A[min] < A[i]){
            key = A[min];
            A[min] = A[i];
            A[i] = key;
            k++;
        }
    }
    for (i = 0; i < num; i++) {
        printf("%d", A[i]);
        if (i < num - 1)printf(" ");
        else printf("\n");
    }
    printf("%d\n", k);

    return 0;

}

