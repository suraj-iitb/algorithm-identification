#include <stdio.h>
int main(void)
{
	int n, q, i, j, k=0;
	scanf("%d", &n);
	int a[n];
	for(i = 0; i < n; i++)scanf("%d", &a[i]);
	
	scanf("%d", &q);
	int b[q];
	for(j = 0; j < q; j++)scanf("%d", &b[j]);
	
	for(i = 0; i < q; i++){
		for(j = 0; j < n; j++){
			if(a[j] == b[i]){
				k++;
				break;
			}
		}
	}
	
	printf("%d\n", k);
	
	return 0;
}
