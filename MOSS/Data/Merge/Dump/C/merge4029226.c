#include <stdio.h>
#include<stdlib.h>
#define MAX 500000

int cnt=0;

void merge(int A[], int left, int mid, int right)
{
	int k, n1, n2, i, j;
	n1=mid-left;
	n2=right-mid;
	int L[n1];
	int R[n2];
	for(i=0; i<n1;i++){
		L[i]=A[left+i];
	}
	for(i=00; i<n2;i++){
		R[i]=A[mid+i];
	}
	L[n1]=1000000001;
	R[n2]=1000000001;
	i=0;
	j=0;
	for(k=left; k<right;k++){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i=i+1;
			cnt++;
		}
		else{
			A[k]=R[j];
			j=j+1;
			cnt++;
		}
		
	}
}

void mergeSort(int A[], int left, int right)
{
	int mid;
	if(left+1<right){
		mid = (left+ right)/2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main(void)
{
	int i, n;
	int S[MAX];
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d", &S[i]);
	}
	mergeSort(S, 0, n);
	
	for(i=0;i<n-1;i++){
		printf("%d ", S[i]);
	}
	printf("%d\n", S[n-1]);
	printf("%d\n", cnt);
	
	return 0;
}

