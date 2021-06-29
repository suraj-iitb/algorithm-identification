#include <stdio.h>
int main(void)
{
	int n, i, j, min, k=0, m;
	scanf("%d", &n);
	int a[n];
	for(i = 0; i < n; i++)scanf("%d", &a[i]);
	
	for(i = 0; i < n; i++){
		min = i;
		for(j = i; j < n; j++){
			if(a[j] < a[min])min = j;
		}
		if(i != min){
			m = a[i];
			a[i] = a[min];
			a[min] = m;
			k++;
		}
	}
	
	for(i =0; i < n; i++){
		if(i!=n-1)printf("%d ", a[i]);
		else printf("%d\n", a[i]);
	}
	printf("%d\n", k);
	
	return 0;
}
