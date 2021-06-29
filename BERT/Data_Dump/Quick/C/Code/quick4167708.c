#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFTY 2000000000

typedef struct{//x is value , y is pattern
    int x;
    char y[2];
}Trump;

int partition( Trump A[], int k, int r );
void quickSort( Trump A[], int p, int r );
void merge( Trump A[], int left, int mid, int right );
void MergeSort( Trump A[], int left, int right );
void swap( Trump *a, Trump *b );

//-----------------------------------------------------------------
int main(){
    int i, n, flag = 0;
    Trump A[100000], B[100000];

    //input and copy A to B
    scanf("%d", &n);
    for( i=0; i<n; i++){
	scanf("%s %d", A[i].y, &A[i].x);
	B[i] = A[i];
    }

    //sort
    quickSort( A, 0, n-1 );
    MergeSort( B, 0, n );
    
    //compare A and B
    for( i=0; i<n; i++ ){
	if( strcmp( A[i].y, B[i].y ) != 0 ) flag = 1;
    }

    //print
    if( flag == 0 ) printf("Stable\n");
    else printf("Not stable\n");
    for( i=0; i<n; i++ ) printf("%s %d\n", A[i].y, A[i].x);

    return 0;
}
     
//-------------------------------------------------------------------
void swap( Trump *a, Trump *b ){
    Trump tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
    
    return ;
}
    
int partition( Trump A[], int p, int r ){
    int i, j, x;

    x = A[r].x;
    for(i = p-1, j = p; j<r; j++){
	if(A[j].x <= x){
	    i++;
	    swap( &A[j], &A[i] );
	}
    }
    swap( &A[i+1], &A[r] );
    return i+1;
}

void quickSort( Trump A[], int p, int r ){
    int q;

    if ( p < r ){
	q = partition( A, p, r );
	quickSort( A, p, q-1 );
	quickSort( A, q+1, r );
    }
    return ;
}

//-------------------------------------------------------------------
void merge( Trump A[], int left, int mid, int right ){
    Trump *L, *R;
    int n1 = mid - left;
    int n2 = right - mid;
    int i, j, k;
    // allocate the memory for merge
    L = malloc(sizeof(Trump) * (n1+1)); //left side
    R = malloc(sizeof(Trump) * (n2+1)); //right side

    // substitute the value of A-array for each divided array 
    for (i = 0; i<n1; i++)
	L[i] = A[left + i];
    for (i = 0; i<n2; i++)
	R[i] = A[mid + i];
    //as sentinels
    L[n1].x = INFTY;
    R[n2].x = INFTY;
    //sort
    i = 0;
    j = 0;
    for (k = left; k<right; k++){
	if (R[j].x == INFTY){
	    A[k] = L[i];
	    i++;
	}
	else if (L[i].x == INFTY){
	    A[k] = R[j];
	    j++;
	}
	else if (L[i].x <= R[j].x){
	    A[k] = L[i];
	    i++;
	}
	else if (L[i].x > R[j].x){ 
	    A[k] = R[j];
	    j++;
	}
    }
    free(L);
    free(R);
    return ;
}

void MergeSort( Trump A[], int left, int right ){
    int mid;
    if (left+1 < right){
	mid = (left + right)/2;
	MergeSort(A, left, mid);
	MergeSort(A, mid, right);
	merge(A, left, mid, right);
    }
    return ;
}

