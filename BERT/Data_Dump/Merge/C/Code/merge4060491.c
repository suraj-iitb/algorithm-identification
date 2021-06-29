#include <stdio.h>

void merge(int left,int mid,int right);
int mergesort(int left,int right);

#define NUM 500000

int n1,n2;
int S[NUM],L[NUM],R[NUM];

int Q = 0;

int main()
{
  int n,i,k;
  
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }
  S[i] = 0;
  
  k = mergesort(0,n);
  printf("%d",S[0]);
  for(i = 1;i < n;i++){
    printf(" %d",S[i]);
  }
  printf("\n");
  printf("%d\n",Q);

  return 0;

}

void merge(int left,int mid,int right)
{
  int i,j,k;
  
  
  n1 = mid - left;
  n2 = right - mid;

  

  for(i = 0;i < n1 ;i++) {
    L[i] = S[left + i];
    
  }
  for(i = 0;i < n2 ;i++) {
    R[i] = S[mid + i];
  }
  L[n1] = 1000000000;
  R[n2] = 1000000000;

  i = 0;
  j = 0;

  for(k = left;k < right;k++){
    if(L[i] <= R[j]){
      S[k] = L[i];
      i++;
      Q++;
    }
    else {
      S[k] = R[j];
      j++;
      Q++;
    }
  }
}

int mergesort(int left,int right)
{
  int mid;
  if(left+1 < right){
    mid = (left+right)/2;
    mergesort(left,mid);
    mergesort(mid,right);
    merge(left,mid,right);
  }
}

