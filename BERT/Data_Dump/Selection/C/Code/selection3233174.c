#include <stdio.h>

int main(void) {
	int n,i,j,minj,a[100],count,tmp;
	count = 0;
	
	scanf("%d",&n);
	
	for(i = 0;i < n;i++){
		scanf("%d",&a[i]);
		}
		
	for(i = 0;i < n;i++){
		minj = i;
		for(j = i; j < n;j++){
			if(a[j] < a[minj]){
			minj = j;
			}
		}
		if(minj != i){
			tmp = a[i];
			a[i] = a[minj];
			a[minj] = tmp;
			count++;
		}
	}
	
	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		if(i < n -1)
			putchar(' ');
	}
	printf("\n");
	printf("%d\n", count);
		
	return 0;
}
