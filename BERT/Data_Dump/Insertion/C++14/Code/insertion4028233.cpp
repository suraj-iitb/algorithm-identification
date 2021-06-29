#include<stdio.h>

void InsertionSort(int* a, int n){
	int i,j,key;
	for(i=1;i<n;i++){
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
		for(j=0;j<n;j++){
			if(j)printf(" ");
			printf("%d",a[j]);
		}printf("\n");
	}
}

int main(){
	int i,n,array[100];
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d",&array[i]);
	}

	for(i=0;i<n;i++){
		if(i)printf(" ");
		printf("%d",array[i]);
	}printf("\n");
	InsertionSort(array,n);

	return 0;
}

