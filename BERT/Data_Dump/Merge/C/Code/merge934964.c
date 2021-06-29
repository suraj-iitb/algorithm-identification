#include <stdio.h>

#define SENTINEL -100000000

int merge(int A[], int left, int mid, int right) {
	int L[mid-left+1];
	int R[right-mid+1];
	int n1 = mid - left;
	int n2 = right - mid;
	int count = 0;
	int i,j,k;

	for(i=0;i<n1;i++) {
		L[i] = A[left+i];
	}
	L[i] = SENTINEL;
	for(i=0;i<n2;i++) {
		R[i] = A[mid+i];
	}
	R[i] = SENTINEL;
	for(k=left,i=0,j=0;k<right;k++) {
		if(L[i] == SENTINEL && R[j] == SENTINEL) {
			break;
		} else if(L[i] == SENTINEL && R[j] != SENTINEL) {
			A[k] = R[j];
			j++;
			count++;
		} else if(R[j] == SENTINEL && L[i] != SENTINEL) {
			A[k] = L[i];
			i++;
			count++;
		} else if(L[i] <= R[j]) {
			A[k] = L[i];
			i++;
			count++;
		} else if(R[j] != -1){
			A[k] = R[j];
			j++;
			count++;
		}
	}
	return count;
}
	
int merge_sort(int A[], int left, int right) {
	int mid;
	int count = 0;
	if(left+1 < right) {
    	mid = (left + right)/2;
        count += merge_sort(A, left, mid);
        count += merge_sort(A, mid, right);
        count += merge(A, left, mid, right);
	}
	
	return count;
}

int main(void) {
	int i,n;
	int A[500000+1];
	int count;
	scanf("%d\n", &n);
	for(i=0;i<n;i++) {
		scanf("%d", &A[i]);
	}

	count = merge_sort(A, 0, n);
	
	for(i=0;i<n;i++) {
		printf("%d", A[i]);
		if(i<n-1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
	printf("%d\n", count);

	return 0;
}
