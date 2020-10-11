#include<stdio.h>
#define M 10000000

int A[M];
void bubbleSort(int A[], int n);

int main()
{
	int n, i;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	bubbleSort(A,n);
}

void bubbleSort(int A[], int n) {
	int flag = 1,p, j, cp, cnt= 0;
	while(flag) {
		flag = 0;
		for(j = n-1; j >= 1; j --) {
			if(A[j] < A[j-1]) {
				cp = A[j];
				A[j] = A[j-1];
				A[j-1] = cp;
				cnt ++;
				flag = 1;
			}
		}
	}
	
	for(p = 0; p < n-1; p++){
		printf("%d ", A[p]);
	}
	printf("%d", A[p]);
	printf("\n%d\n", cnt);
}


