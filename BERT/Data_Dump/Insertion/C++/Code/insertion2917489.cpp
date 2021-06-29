#include<stdio.h>

int a[1001]={0},n;

void insertionSort(void){
	for(int i=1;i<n;i++){
		int v=a[i];
		int j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;
			a[j+1]=v;
		}
		for(int k=0;k<n;k++){
			printf("%d", a[k]);
			if(k<n-1)printf(" ");
		}
		printf("\n");
	}
	return;
}

int main(void){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		printf("%d", a[i]);
		if(i<n-1)printf(" ");
	}
	printf("\n");
	insertionSort();

	return 0;
}
