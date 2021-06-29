#include <stdio.h>
#include <stdlib.h>
#define INFTY 2000000000
long n,*S,count=0;
long *L,*R;
void merge(long,long,long);
void mergeSort(long,long);
int main(){
  int i;
  scanf("%d",&n);
  S=(long*)malloc(sizeof(long)*n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  mergeSort(0,n);
  for(i=0;i<n-1;i++){
    printf("%d ",S[i]);
  }
  printf("%d\n",S[i]);
  printf("%d\n",count);
  free(S);
  return 0;
}

void merge(long left, long mid, long right){
  long n1,n2;
  long i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  L=(long*)malloc(sizeof(long)*(n1+1));
  R=(long*)malloc(sizeof(long)*(n2+1));
  for (i = 0;i<= n1-1;i++)
    L[i] = S[left + i];
  for (i = 0;i<=n2-1;i++)
    R[i] = S[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for (k = left; k<= right-1;k++){
    if (L[i] <= R[j]){
      S[k] = L[i];
      i = i + 1;
    }
    else {
      S[k] = R[j];
      j = j + 1;
    }
    count++;
  }
  free(R);
  free(L);
}

void mergeSort(long left, long right){
  long mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

