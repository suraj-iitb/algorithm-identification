#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 500000

void merge_sort(int *, int, int);
void merge(int *, int, int, int);

int cnt=0;

int main(){
  int i, j, n, s[N];

  scanf("%d", &n);
  if(n>500000) exit(1);

  for(i=0; i<n; i++){
    scanf("%d", &s[i]);
    if(s[i]>1000000000) exit(2);
  }

  merge_sort(s, 0, n);

  for(j=0; j<n; j++){
    if(j<n-1) printf("%d ", s[j]);
    else printf("%d\n", s[j]);
  }
  printf("%d\n", cnt);
  return 0;
}

void merge(int A[], int left, int mid, int right){
  int i, j, k;
  int n1=mid-left;
  int n2=right-mid;
  int L[N/2+2], R[N/2+2];

  for(i=0; i<n1; i++) L[i]=A[left+i];
  for(i=0; i<n2; i++) R[i]=A[mid+i];

  L[n1]=INT_MAX;
  R[n2]=INT_MAX;
  i=0;
  j=0;

  for(k=left; k<right; k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
      cnt++;
    }

    else if(R[j]<=L[i]){
      A[k]=R[j];
      j++;
      cnt++;
    }
  }
}

void merge_sort(int A[], int left, int right){
  int mid;

  if (left+1<right) {
    mid=(left+right)/2;
    merge_sort(A, left, mid);
    merge_sort(A, mid, right);
    merge(A, left, mid, right);
  }
}

