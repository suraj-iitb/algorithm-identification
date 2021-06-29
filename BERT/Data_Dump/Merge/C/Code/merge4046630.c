#include <stdio.h>

#define INFTY 1000000001

int A[500000];
int n;
int sum=0;


void merge(int A[],int left,int mid,int right) {

	int i,k,j,n1,n2;

	n1 = mid - left;
	n2 = right - mid;

	//L[0...n1], R[0...n2] を生成

	int L[n1+1], R[n2+1];

	for(i=0; i<n1; i++) {
		L[i]=A[left+i];
	}

	for(i=0; i<n2; i++) {
		R[i]=A[mid+i];
	}

	L[n1] = INFTY;
	R[n2] = INFTY;
	
	i = 0;
	j = 0;

	for (k = left; k < right; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i = i + 1;
			sum++;
		}
		else {
			A[k] = R[j];
			j = j + 1;
			sum++;
		}
		

	}
}

void mergeSort(int A[], int left, int right) {
	
	int mid;
	
	if(left+1 < right) {
		mid = (left + right)/2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}

}

int main(void) {

	int i;
	scanf("%d",&n);

	for(i=0; i<n; i++) scanf("%d",&A[i]);
	
	mergeSort(A,0,n);
	
	for(i=0;i<n;i++) {
		printf("%d",A[i]);
		if(i==n-1) printf("\n");
		else printf(" ");
	}
	printf("%d\n",sum);

	return 0;
}

