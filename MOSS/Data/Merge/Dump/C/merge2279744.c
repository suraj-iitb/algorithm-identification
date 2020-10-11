#include <stdio.h>

#define INF 2000000000

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int count = 0;

int main(int argc, char const *argv[]) {

  int i;
  int num;
  scanf("%d",&num);
  int S[num];

  for( i = 0 ; i < num ; i++ ){
    scanf("%d",&S[i]);
  }

  mergeSort(S,0,num);

  for( i = 0 ; i < num-1 ; i++ ){
    printf("%d ",S[i]);
  }
  printf("%d\n",S[i]);

  printf("%d\n",count);

  return 0;
}

void merge(int *A, int left, int mid, int right){

  int n1,n2;
  int i,j,k;

  n1 = mid - left;
  n2 = right - mid;
  int L[n1+1],R[n2+1];

  for( i = 0 ; i < n1 ; i++ ){
    L[i] = A[left+i];
  }

  for( i = 0 ; i < n2 ; i++ ){
    R[i] = A[mid+i];
  }

  L[n1] = INF;
  R[n2] = INF;

  i = 0;
  j = 0;

  for( k = left ; k < right ; k++ ){

    count++;

    if( L[i] <= R[j] ){
      A[k] = L[i];
      i++;
    }else{
      A[k] = R[j];
      j++;
    }
  }


}

void mergeSort(int *A, int left, int right){

  int mid;

  if( left+1 < right ){

    mid = (left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);

  }

}
