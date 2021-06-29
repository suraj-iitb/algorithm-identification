#include <stdio.h>

int n, cnt=0;

void merge(int A[], int left, int mid, int right){
  int n1 = mid -left;
  int n2 = right - mid;
  int L[n1], R[n2];
  int i, j, k;
  for(i = 0; i < n1; i++)L[i] = A[left+i];
  for(i = 0; i < n2; i++)R[i] = A[mid+i];
  L[n1] = 1000000000, R[n2] = 1000000000;
  i = 0, j = 0;
  for(k = left; k < right; k++){
    cnt++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }
    else{
      A[k]= R[j];
      j++;
    }
  }
}

void mergesort(int A[], int left, int right){
  if(left+1 < right){
    int mid = (left+right)/2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(void)
{
  int i;
  scanf("%d", &n);
  int a[n];
  for(i = 0; i < n; i++)scanf("%d", &a[i]);

  mergesort(a, 0, n);

  for(i = 0; i < n; i++){
    if(i+1 != n)printf("%d ", a[i]);
    else printf("%d", a[i]);
  }
  printf("\n");
  printf("%d\n", cnt);
  
  return 0;
}

