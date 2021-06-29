#include <stdio.h>

int main(void)
{
	int n, i, j, minj, A[100], temp, cnt=0;
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d",&A[i]);
	}
	for (i=0; i<n; i++) {
		minj = i;
		for (j=i; j<n; j++) {
			if(A[j] < A[minj]) {
				minj = j;
			}
		}
		if(i != minj) {
			temp = A[i];
			A[i] = A[minj];
			A[minj] = temp;
			cnt++;
		}
	}
	for (i=0; i<n-1; i++) {
		printf("%d ",A[i]);
	}
	printf("%d\n%d\n",A[n-1],cnt);
	return 0;
}
