#include <stdio.h>

void trace(int A[], int N){
	int i;
	for (i = 0; i < N; i++){
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}

void swap(int *a, int *b){
    int temp;
    temp = *a;

    *a = *b;
    *b = temp;
}

int bubbleSort(int A[], int N){
    int flag, count, j;
    flag = 1;
    count = 0;
    while (flag==1){
        flag = 0;
        for (j = N - 1; 0 < j; j--){
            if (A[j] < A[j-1]) {
                swap(&(A[j]), &(A[j-1]));
                flag = 1;
                count++;
            }

        }
    }
    return count;
}



int main(void){
    int A[100];
    int N, i, count;

    scanf("%d", &N);
    for (i=0; i < N; i++) scanf("%d", &A[i]);

    count = bubbleSort(A, N);

    trace(A,N);
    printf("%d\n",count);

    return 0;
}
