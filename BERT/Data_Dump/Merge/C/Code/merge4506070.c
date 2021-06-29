#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INFTY 999999999

int count;

void merge(int *A,int left,int mid,int right){
	int n1=(mid-left);
	int n2=(right-mid);
	int *L,*R;
	L=(int*)malloc(sizeof(int)*(n1+1));
	R=(int*)malloc(sizeof(int)*(n2+1));
	for(int i=0;i<n1;i++){
		L[i]=A[left+i];
	}
	for(int i=0;i<n2;i++){
		R[i]=A[mid+i];
	}
	L[n1]=INFTY;
	R[n2]=INFTY;
	int i=0,j=0;
	for(int k=left;k<(right);k++){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}else{
			A[k]=R[j];
			j++;
		}
		count++;
	}
}

void mergeSort(int *A,int left,int right){
	int mid;

	if((left+1)<right){
		mid=((left+right)/2);
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}

int main(){
	int N;
	int *S;

	count=0;

	scanf("%d",&N);
	S=(int*)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++){
		scanf("%d",&S[i]);
	}

	mergeSort(S,0,N);

	for(int i=0;i<N;i++){
		printf("%d",S[i]);
		if(i==(N-1)){
			printf("\n");
		}else{
			printf(" ");
		}
	}
	printf("%d\n",count);
	
	return 0;
}
