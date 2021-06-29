#include <stdio.h>
int main(void){
	int n, i, j, v, a[100];
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
		if(i != n-1){
			printf("%d ", a[i]);
		}else{
			printf("%d\n", a[i]);
		}
	}
	
	for(i=1; i<n; i++){
		v = a[i];
		j = i-1;
		while(j>=0 && a[j]>v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		
		for(j=0; j<n; j++){
			if(j != n-1){
				printf("%d ", a[j]);
			}else{
				printf("%d\n", a[j]);
			}
		}
	}
	
	return 0;
}
