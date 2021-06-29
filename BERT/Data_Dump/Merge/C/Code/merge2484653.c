#include<stdio.h>

#define N 500000

void merge(int, int, int);
void mergeSort(int, int);

int c=0;
int Q[N];
int L[N];
int R[N];

int main(){
int i, n;
  scanf("%d", &n);
  for(i=0 ; i<n ; i++) scanf("%d", &Q[i]);
  mergeSort(0, n);

  for(i=0 ; i<n-1 ; i++) printf("%d ", Q[i]);
  printf("%d\n", Q[i]);
  printf("%d\n", c);

  return 0;
}

void merge(int left, int mid, int right){
  int n1, n2, i, j, k;

  n1 = mid - left;
  n2 = right - mid;

  for(i=0 ; i<=n1-1 ; i++) L[i] = Q[left+i];
  for(i=0 ; i<=n2-1 ; i++) R[i] = Q[mid+i];

  L[n1] = 1000000000;
  R[n2] = 1000000000;
  i = 0;
  j = 0;

  for(k=left ; k<right ; k++){
    c++;
    if(L[i] <= R[j]){
      Q[k] = L[i];
      i++;
    }
    else{
      Q[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int left, int right){
  int mid;

  if(left+1 < right){
    mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}
