#include<stdio.h>

#define MAX 500000
#define SENTINEL 1000000000
  
int S[MAX], count = 0;
  
void merge(int *, int, int, int);
void mergeSort(int *, int, int);

void mergeSort(int *A, int left, int right)
{
  int mid;
  
  if(left + 1 < right)
    {
      mid = (left + right) / 2;
      mergeSort(A, left, mid);
      mergeSort(A, mid, right);
      merge(A, left, mid, right);
    }
}
void merge(int *A, int left, int mid, int right)
{
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1+1], R[n2+1], i, j, k;
  
  for(i = 0; i < n1; i++) L[i] = A[left + i];
    
  for(i = 0; i < n2; i++) R[i] = A[mid + i];
    
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  
  i = 0;
  j = 0;
  
  for(k = left; k < right; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else{
      A[k] = R[j];
      j = j + 1;
    }
    count++;
  }
}
  
 
int main()
{
  int n, i, left, right;
  
  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &S[i]);

  left = 0;
  right = n;
  
  mergeSort(S, left, right);
  
  for(i = 0; i < n; i++){
    if(i < n - 1)printf("%d ", S[i]);
    else printf("%d\n%d\n", S[i], count);
  }
  
  return 0;
}
