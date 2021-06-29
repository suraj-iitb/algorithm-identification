#include<stdio.h>
#define SENTINEL 1000000001
void merge(int *,int,int,int);
void mergeSort(int *,int,int);
int count=0;

int main(){
  int n;
  int left;
  int right;
  int mid;
  int i;
  int S[500000];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  left = 0;
  mid = i/2;
  right = i;

  mergeSort(S,left,right);

  for(i=0;i<n;i++){
    if(i != n-1) printf("%d ",S[i]);
    else printf("%d\n",S[i]);
  }
  printf("%d\n",count);
  return 0;
}

void merge(int *S,int left,int mid,int right){
  int n1;
  int n2;
  int i;
  int j;
  int k;
  n1 = mid - left;
  n2 = right - mid;
  int L[n1];
  int R[n2];
  
    for(i=0;i<n1;i++){
    L[i] = S[left + i];
  }
  for(i=0;i<n2;i++){
    R[i] = S[mid + i];
    }

  L[n1] = SENTINEL;
  R[n2] = SENTINEL;

  i = 0;j = 0;
 
    for(k=left;k<right;k++){
    if(L[i] <= R[j]){
      S[k] = L[i];
      i += 1;
    }
    else{
      S[k] = R[j];
      j += 1;
    }
    count++;
  }
}

void mergeSort(int *S,int left,int right){
  int mid;

  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(S,left,mid);
    mergeSort(S,mid,right);
    merge(S,left,mid,right);
  }
}
