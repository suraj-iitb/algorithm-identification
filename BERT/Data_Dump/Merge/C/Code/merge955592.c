#include <stdio.h>
#define N 500000
#define SENTINEL 1000000000
int count=0;
void Merge( int*, int, int, int );
void MergeSort( int*, int, int);

 int main(){
	 int i;
	 int n;
	 int S[N];
	 scanf("%d", &n);
	 for( i=0; i<n; i++ ){
		 scanf("%d", &S[i]);
	 }
	 MergeSort(S, 0, n);
	 for( i=0; i<n; i++ ){
		 printf("%d",S[i]);
		 if( i+1 != n) printf(" ");
	 }
	 printf("\n%d\n",count);
	 return 0;
 }
 void Merge( int *A, int left, int mid, int right ){
	 int n1 = mid-left;
	 int n2 = right-mid;
	 int L[n1];
	 int R[n2];
	 int i, j, k;
	 for( i=0; i<n1; i++ ) L[i] = A[ left+i ];
	 for( i=0; i<n2; i++ ) R[i] = A[ mid+i ];
	 L[n1] = SENTINEL;
	 R[n2] = SENTINEL;
	 i = 0;
	 j = 0;
	 for( k=left; k<right; k++ ){
		 count++;
		 if( L[i] <= R[j] ){
			 A[k] = L[i];
			 i++;
		 }
		 else{
			 A[k] = R[j];
			 j++;
		 }
	 }
 }

 void MergeSort( int *A, int left, int right ){
	 int mid;
	 if( left+1 < right){
		 mid = ( left+right )/2;
		 MergeSort(A, left, mid);
		 MergeSort(A, mid, right);
		 Merge(A, left, mid, right);
	 }
 }
