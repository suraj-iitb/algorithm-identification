#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int n;
int counter = 0;

int merge(int A[], int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	int L[n1 + 1];
	int R[n2 + 1];
	
	for(int i = 0; i < n1; i++){
		L[i] = A[left + i];
	}
	for(int i = 0; i < n2; i++){
		R[i] = A[mid + i];
	}
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	int i = 0;
	int j = 0;
	for(int k = left; k < right; k++){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
			counter++;
		}else{
			A[k] = R[j];
			j++;
			counter++;
		}
	}
}

int mergeSort(int A[], int left, int right){
	if(left + 1 < right){
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}


int main() {

	scanf("%d",&n);
	int List[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&List[i]);
	}
	
	mergeSort(List,0,n);
	
	
	printf("%d",List[0]);
	for(int i = 1; i < n; i++){
		printf(" %d",List[i]);
	}
	printf("\n%d\n",counter);
	
	
	return 0;
}




