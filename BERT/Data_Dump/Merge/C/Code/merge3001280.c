#include <stdio.h>
#include <limits.h>


int S[500000];
int R[250001];
int L[250001];

int count;


void merge(int A[], int left, int mid,int right){
  int i,j,k;
  int n1,n2;
  
  n1 = mid - left;
  n2 = right - mid;
  
  /*L[0...n1], R[0...n2] �𐶐�*/
    
  for( i = 0 ;i<= n1-1;i++){
    L[i] = A[left + i];
  }
  for (i = 0 ;i<= n2-1;i++){
    R[i] = A[mid + i];
  }
  
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  
  i = 0;
  j = 0;
  for( k = left;k<= right-1;k++){
    ++count;
    if( L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else {
      A[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(int A[],int left,int right){
  int mid;
  
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);

  }
}


int main(){
  int i,j,n;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  mergeSort(S,0,n);

  for(j=0;j<n;j++){

    if(j!=n-1){
      printf("%d ",S[j]);

    }

    else{
      printf("%d\n",S[j]);
    }
  }

  printf("%d\n",count);

  return 0;
}

