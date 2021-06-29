#include<stdio.h>

int main(){
	int N;
	int i, j, k, w, minj, cnt = 0;
	int A[100];
	
	scanf("%d\n", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	
	for(i = 0; i < N-1; i++){
		minj = i;
		for(j = i; j < N; j++){
			if(A[j] < A[minj]){
				minj = j;
			}
		}
		if(i != minj){
			w = A[i];
		    A[i] = A[minj];
		    A[minj] = w;
	    	cnt++;
		}
	}
		
	for(k = 0; k < N - 1; k++){
		printf("%d ", A[k]);
	}
    printf("%d\n", A[N - 1]);
	printf("%d\n", cnt);
	return 0;
}
