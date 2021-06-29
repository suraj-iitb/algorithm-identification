#include <stdio.h>

void Merge(int A[], int, int, int);
void MergeSort(int A[], int, int);

int ctr;

int main() {
	int N;
	scanf("%d", &N);
	int A[N];
	int s;
	for(s=0; s<N; s++){
		scanf("%d", &A[s]);
	}

	int l = 0;
	int r = N;

	MergeSort(A, l, r);

	for(s=0;s<N;s++){
		if(s) printf(" ");
		printf("%d", A[s]);
	}

	printf("\n");

	printf("%d\n", ctr);

	return 0;
}

void Merge(int A[], int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	int i;
	int L[n1]; 
	int R[n2];
	for(i=0; i<n1; i++){
		L[i]= A[left + i];
	}
	for(i=0; i<n2; i++){
		R[i]= A[mid + i];
	}

	L[n1] = 1000000005;
	R[n2] = 1000000005;

	i = 0;
	int j = 0;
	int k;

	for(k=left; k<right; k++){
		ctr++;
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;}
		else{
			A[k] = R[j];
			j++;
		} 
		}
	
}

void MergeSort(int A[], int left, int right){
	if(left+1 < right){
		int mid = (left + right)/2;
		MergeSort(A, left, mid);
		MergeSort(A, mid, right);
		Merge(A, left, mid,right);
	}
}

