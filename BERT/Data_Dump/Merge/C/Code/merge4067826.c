#include <stdio.h>
#define N 500000
 
void merge(int *, int, int, int);
void mergeSort(int *, int, int);
 
int count=0;
 
int main()
{
  int i, p, S[N];
 
  scanf("%d", &p);
 
  for(i = 0; i < p; i++){
    scanf("%d", &S[i]);
  }
 
  mergeSort(S, 0, p);
 
  for(i = 0; i < p-1; i++){
    printf("%d ", S[i]);
  }
  printf("%d\n", S[p-1]);
  printf("%d\n", count);
 
  return 0;
}
 
void merge(int *S, int left, int mid, int right)
{
   
  int x1, x2, i, j, k;
  int L[N], R[N];
   
  x1 = mid-left;
  x2 = right-mid;
 
  for(i = 0; i < x1; i++) L[i] = S[left + i];
  for(i = 0; i < x2; i++) R[i] = S[mid + i];
 
  L[x1] = 1000000000;
  R[x2] = 1000000000;
  i = j = 0;
 
  for(k = left; k < right; k++){
    if(L[i] <= R[j]){
      S[k] = L[i];
      i++;
    }
    else{ 
      S[k] = R[j];
      j++;
    }
    count++;
  }
}
 
void mergeSort(int *S, int left, int right)
{
 
  int mid;
 
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(S, left, mid);
    mergeSort(S, mid, right);
    merge(S, left, mid, right);
  }
}

