#include<stdio.h>
#define N 500000
void merge(int*,int,int,int);
void mergeSort(int*,int,int);
int sum = 0;
int main(){
  int n,i,S[N];

  scanf("%d",&n);

  for(i = 0; i < n; i++)
    scanf("%d",&S[i]);
  mergeSort(S,0,n);
  for(i = 0; i < n; i++){
    printf("%d",S[i]);
    if(i < n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",sum);

  return 0;
}

void merge(int A[],int left,int mid,int right){
  int n1 = mid - left,n2 = right - mid,L[n1 + 1],R[n2 + 1],i,j,k;

  for(i = 0; i < n1; i++)
    L[i] = A[left +i];

  for(i = 0; i < n2; i++)
    R[i] = A[mid + i];

  L[n1] = 1000000000;
  R[n2] = 1000000000;
  i = 0;
  j = 0;

  for(k = left; k < right; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }

    else{
      A[k] = R[j];
      j = j + 1;
    }
    sum++;
  }
}

void mergeSort(int A[],int left,int right){
  int mid;

  if (left + 1 < right){
  mid = (left + right)/2;
  mergeSort(A,left,mid);
  mergeSort(A,mid,right);
  merge(A,left,mid,right);
  }
}
