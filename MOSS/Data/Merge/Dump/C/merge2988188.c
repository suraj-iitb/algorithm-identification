#include <stdio.h>
#define N 500000
#define INFTY 1000000000

int S[N];
int L[N/2+2],R[N/2+2];
int count=0;

int merge(int S[],int n, int left, int mid, int right){
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;

  j=0;
  k=0;

  for(i=0; i<n1; i++) L[i] = S[left+i];
  for(i=0; i<n2; i++) R[i] = S[mid+i];

  L[n1] = R[n2] = INFTY;

  for(i=left; i<right; i++){
    count++;
    if(L[j]<=R[k]) S[i] = L[j++];
    else {
      S[i] = R[k++];
    }

  }
 //printf("%d\n",count);
}

int mergeSort(int S[],int n, int left, int right){
  if(left+1 < right){
    int mid = (left + right) /2;
    mergeSort(S,n,left,mid);
    mergeSort(S,n,mid,right);
    merge(S,n,left,mid,right);
  }
}

int main(){
  int S[N],i,n;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }

  mergeSort(S,n,0,n);

  for(i=0; i<n; i++){
    if(i) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");

  printf("%d\n",count);

  return 0;

}

