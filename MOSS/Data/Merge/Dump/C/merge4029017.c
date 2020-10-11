#include<stdio.h>
#define MAX 500000
#define SEN 2000000000

int c=0;

void merge(int A[], int n, int left, int mid, int right){
	int n1=mid-left;
	int n2=right-mid;
	int L[MAX/2+2],R[MAX/2+2];
	
	for(int i=0;i<n1;i++){
		L[i]=A[left+i];
	}
	for(int i=0;i<n2;i++){
		R[i]=A[mid+i];
	}
	L[n1]=SEN;
	R[n2]=SEN;
	
	int i=0,j=0;
	
	for(int k=left;k<right;k++){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}else{
			A[k]=R[j];
			j++;
		}
		c++;
	}
}

void mergesort(int A[], int n, int left, int right){
	int mid;
	
	if(left+1<right){
		mid=(left+right)/2;
		mergesort(A,n,left,mid);
		mergesort(A,n,mid,right);
		merge(A,n,left,mid,right);
	}
}

int main(void){
	int A[MAX];
	int n;
	
	scanf("%d",&n);
	for(int i;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	mergesort(A,n,0,n);
	
	printf("%d",A[0]);
	for(int i=1;i<n;i++){
		printf(" %d",A[i]);
	}
	printf("\n");
	
	printf("%d\n",c);
	
	
	return 0;
}
