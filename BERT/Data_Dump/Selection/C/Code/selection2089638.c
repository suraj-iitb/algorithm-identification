#include <stdio.h>
int main(void){
	int n, i, j, count, temp, minj, a[100];
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	count = 0;
	
	for(i=0; i<n; i++){
		minj = i;
		
		for(j=i;j<n;j++){
			if(a[j] < a[minj]){
				minj = j;
			}
		}
		
		if(minj != i){
			temp = a[i];
			a[i] = a[minj];
			a[minj] = temp;
			
			count++;
		}
	}
	
	for(i=0; i<n; i++){
		if(i != n-1){
			printf("%d ", a[i]);
		}else{
			printf("%d\n", a[i]);
		}
	}
	
	printf("%d\n", count);
	
	return 0;
}
