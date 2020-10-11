#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void sort(int A[],int n){
	int tmp;
	int count=0;
	for(int i=0;i<(n-1);i++){
		for(int j=(n-1);j>i;j--){
			if(A[j-1]>A[j]){
				count++;
				tmp=A[j-1];
				A[j-1]=A[j];
				A[j]=tmp;
			}
		}
	}

	for(int i=0;i<n;i++){
		printf("%d",A[i]);
		if(i==(n-1)){
			printf("\n");
		}else{
			printf(" ");
		}
	}
	printf("%d\n",count);
}

int main(){
    int n;
	int *A;

	scanf("%d",&n);
	A=(int*)malloc(sizeof(int)*n);

	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}

	sort(A,n);


	
	return 0;
}
