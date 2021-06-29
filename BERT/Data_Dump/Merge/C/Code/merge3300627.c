#include <stdio.h>
#include <stdlib.h>
#define INFTY 2000000000;
void merge(int *,int,int,int);
void mergeSort(int *,int,int);
int n, count = 0, *L, *R;
/*countは比較回数をカウントする。*/
int main()
{
  int *S, i;

  scanf("%d",&n);
  S = (int *)malloc(n * sizeof(int));

  for(i = 0 ; i < n ; i++) scanf("%d",&S[i]);

  mergeSort(S, 0, n);

  for(i = 0 ; i < n-1 ; i++) printf("%d ",S[i]);
  printf("%d\n",S[n-1]);
  printf("%d\n",count);

  free(S);
  free(L);
  free(R);
  
  return 0;
}

void merge(int *A, int left , int mid, int right)
{
  int n1, n2, i, j, k; 
  n1 = mid - left;
  n2 = right - mid;

  L = (int *)malloc((n1 + 1) * sizeof(int));
  R = (int *)malloc((n2 + 1) * sizeof(int));

  for(i = 0 ; i < n1 ; i++) L[i] = A[left+i]; 
  for(i = 0 ; i < n2 ; i++) R[i] = A[mid+i];

  L[n1] = INFTY;
  R[n2] = INFTY;

  i = 0;
  j = 0;

  for(k = left ; k < right ; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
      count++; }
    else{
      A[k] = R[j];
      j++;
      count++; } 
  }

} 

void mergeSort(int *A, int left, int right)
{
  int mid;
  
  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right); }

}
