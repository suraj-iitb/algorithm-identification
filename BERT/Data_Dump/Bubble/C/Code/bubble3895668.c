#include <stdio.h>
int main(void)
{
	int n, i, k=0, m;
	scanf("%d", &n);
	
	int a[n];
	for(i = 0; i < n; i++)scanf("%d", &a[i]);
	
	int f=1;
	
	while(f==1){
		f=0;
		for(i = n-1; i >= 1; i--){
			if(a[i] < a[i-1]){
				m = a[i];
				a[i] = a[i-1];
				a[i-1] = m;
				k++;
				f=1;
			}
		}
	}
	
	for(i =0; i < n; i++){
		if(i!=n-1)printf("%d ", a[i]);
		else printf("%d\n", a[i]);
	}
	printf("%d\n", k);
	
	return 0;
}

