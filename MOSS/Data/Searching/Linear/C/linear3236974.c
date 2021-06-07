#include<stdio.h>
 
int main(void)
{
	int n1, n2, A[10000], B[10000];
	int i, j, k, l = 0;
	int count = 0;

	scanf("%d", &n1);

	for (i = 0;i < n1;i++) {
		scanf("%d", &A[i]);
	}

	scanf("%d", &n2);

	for (i = 0;i < n2;i++) {
		scanf("%d", &B[i]);
	}
	
	for (i = 0;i < n2;i++) {
		for (j = 0;j < n1;j++) {
			if (A[j] == B[i]) {
				count++;
				break;
			}
		}
	}

	printf("%d\n", count);




	return 0;
}
 

