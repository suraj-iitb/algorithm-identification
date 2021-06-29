#include <stdio.h>

int main(void)
{
	int j, flag=1, n, A[100], temp, cnt=0;
	scanf("%d",&n);
	for (j=0; j<n; j++) {
		scanf("%d",&A[j]);
	}
	while(flag) {
		flag = 0;
		for (j=n-1; j>=1; j--) {
			if(A[j] < A[j-1]) {
				temp = A[j];
				A[j] = A[j-1];
				A[j-1] = temp;
				cnt++;
				flag = 1;
			}
		}
	}
	for (j=0; j<n-1; j++) {
		printf("%d ",A[j]);
	}
	printf("%d\n%d\n",A[n-1],cnt);
	return 0;
}
