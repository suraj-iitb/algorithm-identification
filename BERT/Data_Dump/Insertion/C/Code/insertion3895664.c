#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void insertionSort(int* a,int N){
	int v;
	int j;
	for(int i=0;i<=N-1;i++){
		v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1]=v;
		
		for(int k=0;k<N;k++){
			printf("%d",a[k]);
			if(k!=N-1)printf(" ");
		}
		printf("\n");
	}
}

int main(void){
	
	int n;
	scanf("%d",&n);
	int* a=(int*)malloc(sizeof(int)*n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	insertionSort(a,n);
	
	return 0;
	
}
