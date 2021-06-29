

#include<stdio.h>

int L[300000], R[300000];

int cnt = 0;

int merge(int A[], int n, int left, int mid, int right){

int i, j, k;

int n1 = mid - left;

int n2 = right - mid;

int L[500000], R[500000];


  for( i = 0; i < n1; i++ ){

    L[i] = A[left + i];

  }

  for( i = 0; i < n2; i++ ){

    R[i] = A[mid + i];

  }

  L[n1] = R[n2] = 2000000000;

  i = 0;

  j = 0;


  for( k = left; k < right ; k++ ){

    cnt++;

    if(L[i] <= R[j]){

      A[k] = L[i];

      i = i + 1;

    }

    else{

      A[k] = R[j];

      j = j + 1;

    }

  }

}


void mergeSort(int A[], int n, int left, int right){

int mid;

  if(left+1 < right){

    mid = (left + right)/2;

    mergeSort(A, n, left, mid);

    mergeSort(A, n, mid, right);

    merge(A, n, left, mid, right);

  }

}


int main(void){

int n, i;

int A[500000];

  scanf("%d", &n);

  for(i = 0; i < n; i++) scanf("%d", &A[i]);

  mergeSort(A, n, 0, n);

  for(i = 0; i < n; i++){

    if(i==0)printf("%d",A[i]);

    else printf(" %d",A[i]);

  }

 printf("\n%d\n",cnt);

  return 0;

}