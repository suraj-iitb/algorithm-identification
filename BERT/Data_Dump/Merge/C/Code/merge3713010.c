#include <stdio.h>
#include<math.h>
#define MAX 500005
#define INFINITY 2000000000

int i,j,k,n;
int S[MAX];
int count = 0;

void merge(int A[], int l, int m, int r){
  int n1, n2;
  n1 = m - l;
  n2 = r - m;
  int L[n1+1], R[n2+1];
  for (i = 0; i < n1; i++)
    L[i] = A[l + i];
  for (i = 0; i < n2; i++)
    R[i] = A[m + i];
  L[n1] = INFINITY;
  R[n2] = INFINITY;
  i = 0;
  j = 0;
  for (k = l; k < r; k++){
    if (L[i] <= R[j]){
      A[k] = L[i];
      i++;
      count++;
    }
    else{
       A[k] = R[j];
       j++;	
       count++;
    }
  }
}

void mergeSort(int A[], int l, int r){
  if (l+1 < r){
  	int m;
    m = (l + r)/2; 
    mergeSort(A, l, m);
    mergeSort(A, m, r);
    merge(A, l, m, r);
  }
}

int main(void){
	scanf("%d ", &n);
	for(i=0; i<n; i++)
		scanf("%d ", &S[i]);
	
	mergeSort(S,0,n);
	
	for (i=0; i<n; i++){
		if (i<n-1)
			printf("%d ", S[i]);
		else printf("%d\n", S[i]);
	}
	printf("%d\n", count);
	
	return 0;
}
