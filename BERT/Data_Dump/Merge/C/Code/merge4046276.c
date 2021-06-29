#include<stdio.h>
#include<limits.h>

int INF = 999999999;

int count;

void merge(int S[], int left, int mid, int right){
	int i=0, j=0;
	int n1 = mid-left;
	int n2 = right - mid;
	int L[n1], R[n2];
	for(i=0; i<n1; i++){
		L[i] = S[left + i];
	}
	for(i=0; i<n2; i++){
		R[i] = S[mid + i];
	}
	L[n1] = INF;
	R[n2] = INF;
	i=0; j=0;
	for(int k=left; k<right; k++){
		count++;
		if(L[i]<=R[j]){
			S[k] = L[i];
			i++;
		}
		else{
			S[k] = R[j];
			j++;
		}
	}
}

void mergeSort(int S[], int left, int right){
	int mid;
	mid = (left + right)/2;
	if( left+1<right ){
		mid = (left + right)/2;
		mergeSort(S, left, mid);
		mergeSort(S, mid, right);
		merge(S, left, mid, right);
	}
}

int main(void){
	int n, i, S[500000];
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &S[i]);
	}
	mergeSort(S, 0, n);
	
	for(i=0; i<n-1; i++){
		printf("%d ", S[i]);
	}
	printf("%d\n", S[i]);
	printf("%d\n", count);
	return 0;
}
