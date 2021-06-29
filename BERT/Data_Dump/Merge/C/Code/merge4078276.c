#include <stdio.h>
#include <stdlib.h>
#define INFTY -1

void merge( int [], int left, int mid, int right );
void MergeSort( int [], int left, int right );
int n, cnt = 0;

int main(){
    int i, A[500000];

    //input
    scanf("%d", &n);
    for (i = 0; i<n; i++)
	scanf("%d", &A[i]);

    //sort
    MergeSort(A, 0, n);

    //display
    for (i = 0; i<n; i++){
	printf("%d", A[i]);
	if (i < n-1) printf(" ");
    }
    printf("\n%d\n", cnt);

    return 0;
}

void merge( int A[], int left, int mid, int right ){
    int *L, *R;
    int n1 = mid - left;
    int n2 = right - mid;
    int i, j, k;
    // allocate the memory for merge
    L = malloc(sizeof(int) * (n1+1)); //left side
    R = malloc(sizeof(int) * (n2+1)); //right side

    // substitute the value of A-array for each divided array 
    for (i = 0; i<n1; i++)
	L[i] = A[left + i];
    for (i = 0; i<n2; i++)
	R[i] = A[mid + i];
    //as sentinels
    L[n1] = INFTY;
    R[n2] = INFTY;
    //sort
    i = 0;
    j = 0;
    for (k = left; k<right; k++){
	if (R[j] == INFTY){
	    A[k] = L[i];
	    i++;
	}
	else if (L[i] == INFTY){
	    A[k] = R[j];
	    j++;
	}
	else if (L[i] <= R[j]){
	    A[k] = L[i];
	    i++;
	}
	else if (L[i] > R[j]){ 
	    A[k] = R[j];
	    j++;
	}
	cnt++;
    }
    free(L);
    free(R);
    return ;
}

void MergeSort( int A[], int left, int right ){
    int mid;
    if (left+1 < right){
	mid = (left + right)/2;
	MergeSort(A, left, mid);
	MergeSort(A, mid, right);
	merge(A, left, mid, right);
    }
    return ;
}

