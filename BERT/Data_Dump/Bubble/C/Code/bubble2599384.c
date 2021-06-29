#include <stdio.h>

int main(void) {
	
	int i, n, s, f, count = 0;
	int a[100];
	
	scanf("%d", &n);
	for( i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	f = 1;
	while(f){
		f = 0;
			for( i = n-1; i > 0; i--){
				if( a[i] < a[i-1]){
					s = a[i];
					a[i] = a[i-1];
					a[i-1]= s;
					f = 1;
					count = count + 1;
				}
			}
	}
	
	for(i = 0; i < n-1; i++){
		printf("%d ", a[i]);
	}
		printf("%d\n",a[n-1]);
		printf("%d\n", count);
		
	return 0;
	
}
