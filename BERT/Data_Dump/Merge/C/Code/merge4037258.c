#include<stdio.h>
#include<math.h>
#include<limits.h>
#define MAX 500000
int count =0;
void merge(int A[],int left,int mid,int right);
void mergeSort(int A[],int left,int right);

int main(void){
	
	int n, i;
	int S[MAX];
	
	scanf("%d", &n);
	for(i = 0;i<n;i++){
		scanf("%d", &S[i]);
	}
	
	mergeSort(S, 0, n);
	
	for(i =0;i<n-1;i++){
		printf("%d ", S[i]);
	}
	printf("%d\n", S[n-1]);
	printf("%d\n", count);
	
	return 0;
}


void merge(int A[],int left,int mid,int right){
  	int n1 = mid - left;
  	int n2 = right - mid;
	int R[n1+1], L[n2+1];
	int i, j, k;
  //L[0...n1], R[0...n2] を生成
	for (i = 0;i <n1;i++){
		L[i] = A[left + i];
	}
	for (i = 0;i <n2;i++){
		R[i] = A[mid + i];
	}
 	L[n1] = INT_MAX;
  	R[n2] = INT_MAX;
	i = 0;
	j = 0;
	for (k = left ;k<right;k++){
		if( L[i] <= R[j]){
	      A[k] = L[i];
	      i = i + 1;
		  count++;
		}
		else {
	      A[k] = R[j];
	      j = j + 1;
			count++;
		}
	}
}
void mergeSort(int A[],int left,int right){
	if( left+1 < right){
    int mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
	}
}
