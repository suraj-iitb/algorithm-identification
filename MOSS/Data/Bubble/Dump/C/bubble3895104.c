#include<stdio.h>

void bubbleSort(int n, int a[]);

int main(void){
	
	int n;
	
	scanf("%d", &n);
	
	int a[n], i;
	
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	bubbleSort(n, a);
	
	return 0;
	
}

void bubbleSort(int n, int a[]){
	
	int i, j, x, count=0;
	
	for(j=0; j<n; j++){
		for(i=n-1; j<i; i--){
			if(a[i]<a[i-1]){
				//printf("a[i-1]%d, a[i]%d ", a[i-1], a[i]);
				x=a[i-1];
				a[i-1]=a[i];
				a[i]=x;
				count++;
				//printf("a[i-1]%d, a[i]%d\n", a[i-1], a[i]);
			}
		}
	}
	
	for(i=0; i<n-1; i++){
		printf("%d ", a[i]);
	}
	
	printf("%d\n", a[i]);
	printf("%d\n", count);
	
}
