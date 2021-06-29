#include <stdio.h>

int main(){
	int n, i, j, tmp, count=0, min;
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	for(i=0; i<n-1; i++){
		min=i;
		for(j=i+1; j<n; j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		if(i!=min){
			tmp=a[i];
			a[i]=a[min];
			a[min]=tmp;
			count++;
		}
	}
	
	for(i=0; i<n-1; i++){
		printf("%d ", a[i]);
	}
	
	printf("%d\n", a[n-1]);
	
	printf("%d\n", count);
	
	return 0;
}
