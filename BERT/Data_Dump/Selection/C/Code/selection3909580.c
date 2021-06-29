#include<stdio.h>

int main(void){
	int n;
	int a[100];
	int i, j,count,x, min;
	scanf("%d", &n);
	for(i = 0;i<n;i++){
		scanf("%d", &a[i]);
	}
	count =0;
	for(i = 0;i<n;i++){
		min =i;
		for(j =i;j<n;j++){
			if(a[min] > a[j]){
				min =j;
			}
		}
		if(min != i){
		x = a[i];
		a[i] = a[min];
		a[min] = x;
		count++;
		}
	}
	
	for(i = 0;i<n-1;i++){
		
		printf("%d ", a[i]);
	}
	printf("%d\n", a[n-1]);
	printf("%d\n", count);
	
	return 0;
	
	
	}
