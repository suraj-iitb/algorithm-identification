#include <stdio.h>
int main(void)
{
	int n, q, i, j, k=0;
	int right, left, mid;
	
	scanf("%d", &n);
	int a[n];
	for(i = 0; i < n; i++)scanf("%d", &a[i]);
	scanf("%d", &q);
	int b[q];
	for(j = 0; j < q; j++)scanf("%d", &b[j]);
	
	for(i = 0; i < q; i++){
		left = 0;
		right = n;
		
		while(left < right){
			mid = (left+right)/2;
			if(b[i] == a[mid]){
				k++;
				break;
			}
			if(b[i] < a[mid])right = mid;
			else left = mid+1;
		}
	}
	
	printf("%d\n", k);
	
	return 0;
}
