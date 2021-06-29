#include <stdio.h>

int main(){
	int n, i, j, count=0, tmp;
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(i=0; i<n-1; i++){
		for(j=n-1; j>i; j--){
			if(a[j-1]>a[j]){
				tmp=a[j-1];
				a[j-1]=a[j];
				a[j]=tmp;
				count++;
			}
		}
	}
	for(i=0; i<n-1; i++){
		printf("%d ", a[i]);
	}
	
	printf("%d\n", a[n-1]);
	
	printf("%d\n", count);
	
	return 0;
}
