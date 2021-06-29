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

int selectionSort(int A[], int N){
    int minj, count;
    int i,j;
    count = 0;

    for (i = 0; i <= N - 1; i++){
    	// i : ?????????????????????index
    	// minj : ???????????????????´???????????°???? ???index?????¢?´¢
    	minj = i; 
    	for (j = i; j <= N - 1; j++){ 
    		if (A[j] < A[minj]) minj = j;
    	}
    	//minj ????±??????£????????§swap
    	if (minj != i){
    		swap(&(A[i]), &(A[minj]));
    		count++;
    	}
    }
    return count;
}



int main(void){
    int A[100];
    int N, i, count;

    scanf("%d", &N);
    for (i=0; i < N; i++) scanf("%d", &A[i]);

    count = selectionSort(A, N);

    trace(A,N);
    printf("%d\n",count);

    return 0;
}
