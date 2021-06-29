#include <stdio.h>
#include <limits.h>

int try = 0;
int L[500000],R[500000];

void merge(int *S, int left,int mid, int right){

  int n1,n2,i,j,k;

  n1 = mid - left;
  n2 = right - mid;

  for(i=0; i<n1; i++) L[i] = S[left+i];
  for(i=0; i<n2; i++) R[i] = S[mid+i];

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  i=0;
  j=0;
  for(k=left; k<right; k++){
    if(L[i] <= R[j]){
      S[k] = L[i++];
    }
    else{
      S[k] = R[j++];
    }
    try ++;
  }
}

void mergesort(int *S,int left, int right){

  int mid;
  if(left+1 < right){

    mid = (left + right)/2;
    mergesort(S,left,mid);
    mergesort(S,mid,right);
    merge(S,left,mid,right);

  }
}


int main () {

  int n,i;

  scanf ("%d",&n);

  int S[n];

  for (i=0; i<n; i++) scanf("%d",&S[i]);

  mergesort(S,0,n);

  for(i=0; i<n-1; i++) printf("%d ",S[i]);
  printf("%d\n",S[n-1]);
  printf("%d\n",try);

  return 0;

}
