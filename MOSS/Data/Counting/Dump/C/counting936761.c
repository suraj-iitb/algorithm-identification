#include <stdio.h>

void counting_sort(int A[], int B[], int k) {
	int i,j;
	int C[20000];
	for(i=0;i<20000;i++) C[i] = 0;

	for(i=0;i<k;i++) C[A[i]+1]++;

	for(i=1;i<20000;i++) {
		C[i] = C[i] + C[i-1];
	}

	for(i=1,k=0;i<=10001;i++) {
		for(j=C[i-1];j<C[i];j++) {
			B[k] = i-1;
			k++;
		}
	}
}

int A[2000000+1];
int B[2000000+1];

int main(void) {
	int i,n;
	scanf("%d\n", &n);
	for(i=0;i<n;i++) {
		scanf("%d", &A[i]);
	}
	counting_sort(A, B, n);
	
	for(i=0;i<n;i++) {
		printf("%d", B[i]);
		if(i<n-1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
	
	return 0;
}
