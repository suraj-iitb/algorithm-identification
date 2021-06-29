#include <stdio.h>
#define N 100

int main() {
    int i, j, k, key;
    int A[N];
    int num;

    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        scanf("%d", &A[i]);
        printf("%d", A[i]);
        if (i < num - 1)printf(" ");
        else printf("\n");
    }

    for (i = 1; i < num; i++) {
        key = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
            A[j + 1] = key;
        }

        for (k = 0; k < num; k++) {
            printf("%d", A[k]);
            if (k < num - 1)printf(" ");
            else printf("\n");
        }
       
    }

    return 0;

}
