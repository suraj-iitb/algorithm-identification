#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *A, int N);

int main(void){
	int n;
	int *num;
	scanf("%d",&n);
	num=(int *)malloc(sizeof(int)*n);
	if(num==NULL){
		printf("failure\n");
		exit(1);
	}

	int i;
	for(i=0;i<n;i++){
		scanf("%d",(num+i));
	}
	for(i=0;i<n-1;i++){
		printf("%d ",*(num+i));
	}
	printf("%d\n",*(num+n-1));
	insertionSort(num,n);
	/*
	for(i=0;i<n;i++){
		printf("%d",*(num+i));
	}
	*/

	free(num);
	return 0;
}

void insertionSort(int *num, int n){
	int i,j,k,v;
	for(i=1;i<n;i++){
		v=num[i];
		j=i-1;
		while(j>=0&&num[j]>v){
			num[j+1]=num[j];
			j--;
		}
		num[j+1]=v;
		for(k=0;k<n-1;k++){
			printf("%d ",*(num+k));
		}
		printf("%d\n",*(num+n-1));
	}
}
