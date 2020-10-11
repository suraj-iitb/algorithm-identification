#include<stdio.h>
int main(void){
	int n;
	int i, j, k, w;
	int min, cnt = 0;
	int A[100];

	scanf("%d\n", &n);
	for(i=0; i<n; i++){
		scanf("%d", &A[i]);
	}

	for(i = 0; i < n-1; i++){
		min = i;
		for(j=i; j<n; j++){
			if(A[j] < A[min]){
				min = j;
			}
		}
		if(i!=min){
			w = A[i];
			A[i] = A[min];
			A[min] = w;
			cnt++;
		}
	}

	for(k=0; k<n-1; k++){
		printf("%d ", A[k]);
	}
	printf("%d\n", A[n-1]);
	printf("%d\n", cnt);
	return 0;
}
