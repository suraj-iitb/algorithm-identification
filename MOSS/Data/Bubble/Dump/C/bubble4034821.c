#include <stdio.h>
#define M 100

int Bubblesort(int,int *);

int main()
{
	int A[M], i = 0,v,limit,count=0;
	scanf("%d", &limit);
	for(i=0;i<limit;i++){
		scanf("%d", &A[i]);
		if (i == M-1)break;
	}
	v = Bubblesort(limit,A);
	for (i = 0; i < limit - 1; i++) printf("%d ", A[i]);
	printf("%d\n%d\n", A[limit - 1],v);
	
	return 0;
}

int Bubblesort(int N,int *A)
{
	int flag = 1,j,count=0;
	int kari;
	while (flag) {
		flag = 0;
		for (j = N - 1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				kari = A[j];
				A[j] = A[j - 1];
				A[j - 1] = kari;
				flag = 1;
				count++;
			}
		}
	}
	return count;
}
