#include <stdio.h>
#include <stdlib.h>
#define MAX 500000
#define SENTINEL 2000000000
int L[(MAX/2)+2], R[(MAX/2)+2];
int cnt = 0;
void merge(int*,int,int,int,int);
void mergeSort(int*,int,int,int);
int main(){
  int *S;
  int n, i;
  scanf("%d",&n);
  if(n > MAX)
    exit(1);
  S = (int*)malloc(sizeof(int) * n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
    if(S[i] < 0 || S[i] > (SENTINEL/2))
      exit(1);
  }

  mergeSort(S,n,0,n);

  for(i = 0; i < n; i++){
    printf("%d",S[i]);
    if(i != n-1)
      printf(" ");
  }
  printf("\n%d\n",cnt);
  
  return 0;
}

void merge(int S[],int n, int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int i,j,k;
  for(i = 0; i < n1; i++)
    L[i] = S[left+i];
  for(i = 0; i < n2; i++)
    R[i] = S[mid+i];
  L[n1] = R[n2] = SENTINEL;
  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    cnt++;
    if(L[i] <= R[j])
      S[k] = L[i++];
    else
      S[k] = R[j++];
  }
}

void mergeSort(int S[],int n, int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left + right) / 2;
    mergeSort(S,n,left,mid);
    mergeSort(S,n,mid,right);
    merge(S,n,left,mid,right);
  }
}


