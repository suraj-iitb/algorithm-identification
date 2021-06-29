#include <stdio.h>

int main(void)
{
    int N, i, j, minj, temp;
    int count = 0;
    int A[100];

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (i = 0; i < N; i++){
        minj = i;
        for ( j = i; j < N; j++){
            if (A[j] < A[minj])
            minj = j;}
        if ( minj != i){
        temp = A[i];
        A[i] = A[minj];
        A[minj] = temp;
        count++;
        }
    }

    for (i = 0; i < N; i++){
		if ( i != 0)
		printf(" ");
		
        printf("%d", A[i]);
    }

    printf("\n%d\n", count);

    return 0;
}
