#include<stdio.h>
 
int main(void)
{
	int n1, n2, A[100000], B[100000];
	int i, j, k, l = 0;
	int min, max, mid;
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
		min = 0;
		max = n1 - 1;
		mid = (n1 - 1) / 2;
		while (min < max){
				
			
			
			if (B[i] < A[mid]) {
				max = mid - 1;
			}
			if (B[i] > A[mid]) {
				min = mid + 1;
			}
			mid = (max + min) / 2;
			if (A[mid] == B[i]) {
				count++;
				break;
			}
		
		}
	}

	printf("%d\n", count);




	return 0;
}
 

