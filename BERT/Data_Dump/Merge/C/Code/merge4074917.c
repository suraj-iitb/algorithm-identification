#include<stdio.h>
#define MAX 2000000000
#define MAX1 500000

void merge(int*, int, int, int);
void mergeSort(int*, int, int);

int count=0;

int main (){
    int n,S[MAX1],i;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&S[i]);
    }
    mergeSort(S, 0, n);
    for(i=0; i<n; i++){
        if(i==n-1)printf("%d\n",S[i]);
        else printf("%d ",S[i]);
    }
    printf("%d\n",count);
    return 0;
}
void merge(int S[], int left, int mid, int right){
  int L[MAX1],R[MAX1],i,j,n1,n2,k;
  n1 = mid - left;
  n2 = right - mid;
  for(i=0; i<=n1; i++){
      L[i]=0;
  }
  for(i=0; i<=n2; i++){
      R[i]=0;
  }
  for(i=0; i<n1; i++){
    L[i] = S[left + i];
  }
  for(i=0; i<n2; i++){
    R[i] = S[mid + i];
  }
  L[n1] = MAX;
  R[n2] = MAX;
  i = 0;
  j = 0;
  for(k=left; k<right; k++){
    if(L[i] <= R[j]){
      S[k] = L[i];
      i = i + 1;
    }else{ 
      S[k] = R[j];
      j = j + 1;
    }
    count++;
  }
}
void mergeSort(int S[], int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(S, left, mid);
    mergeSort(S, mid, right);
    merge(S, left, mid, right);
  }
}

