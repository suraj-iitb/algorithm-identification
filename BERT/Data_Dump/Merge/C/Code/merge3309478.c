#include <stdio.h>
#define INFTY 1000000000

void merge(int,int,int);
void mergeSort(int,int);
  
int L[5000000],R[5000000],S[5000000],count=0;

int main() {

  int n,i;
  
  scanf("%d",&n);
  for(i = 0; i < n; i++) {
    scanf("%d",&S[i]);
  }

  mergeSort(0,n);
  
  for(i = 0; i < n; i++) {
    if(i) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n%d\n",count);
  return 0;
}


void mergeSort(int left,int right)
{
  int mid;
  if(left + 1 < right) {
    mid = (left + right)/2;
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,mid,right);
  } 
}

void merge(int left,int mid,int right)
{
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i < n1; i++) {
    L[i] = S[left + i];
  }
  for(i = 0; i < n2; i++) {
    R[i] = S[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  
  for(k = left; k < right; k++) {
    count++;
    if(L[i] <= R[j]) {
      S[k] = L[i];
      i = i + 1;
    }
    else {
      S[k] = R[j];
      j = j + 1;
    }
}
}

