#include<stdio.h>

int selectionSort(int n, int a[]);

int main(void){
	
	
	int n;
	
	scanf("%d", &n);
	
	int a[n], i;
	
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	selectionSort(n, a);
	
	return 0;
	
}

int selectionSort(int n, int a[]){
	
	int i, j, min, count=0, ii, check;
	
	for(j=0; j<n-1; j++){
		min=a[j];
		check=0;
		for(i=j+1; i<n; i++){
			if(a[i]<min){
				ii=i;
				min=a[i];
				check=1;
			}
		}
		if(check==1){
			a[ii]=a[j];
			a[j]=min;
			count++;
		}
		
	}
	
	for(i=0; i<n-1; i++){
		printf("%d ", a[i]);
	}
	
	printf("%d\n", a[i]);
	printf("%d\n", count);
	
}
