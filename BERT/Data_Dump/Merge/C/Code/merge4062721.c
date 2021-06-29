#include<stdio.h>

#define N 500000
#define I 1000000000

void mergesort(int *,int,int);
void merge(int *,int,int,int);

int count=0;

void mergesort(int *S,int left,int right)
{
  int mid;
  
  if(left+1 < right) {
    mid = (left + right) / 2;
    mergesort(S,left,mid);
    mergesort(S,mid,right);
    merge(S,left,mid,right);
  }
  
}
  

void merge(int *S,int left,int mid,int right)
{
  int i,j,k,a,b;
  int L[N],R[N];

  a = mid - left;
  b = right - mid;

  for(i=0;i<a;i++) {
    L[i] = S[left+i];
  }
  
  for(i=0;i<b;i++) {
    R[i] = S[mid+i];
  }
  
  L[a] = I;
  R[b] = I;

  i=0;
  j=0;

  for(k=left;k<right;k++){
    count++;
    if(L[i] <= R[j]){
      S[k] = L[i];
      i++;
    }else{
      S[k] = R[j];
      j++;
    }
  }
}
  

int main()
{
  int n,i;
  int S[N];

  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%d",&S[i]);
  }
  
  mergesort(S,0,n);

  for(i=0;i<n;i++) {
    if(i)
      printf(" ");
    printf("%d",S[i]);
  }
  
  printf("\n");
  printf("%d\n",count);
  

  return 0;
}

