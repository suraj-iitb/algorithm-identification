#include <stdio.h>
#define N 500000
#define INF 1000000000

void merge(int, int, int);
void mergeSort(int, int);

int S[N], count=0;

int main()
{
  int i, n;

  scanf("%d", &n);
  for(i = 0 ; i < n ; i++){
    scanf("%d", &S[i]);
  }

  mergeSort(0, n);

  for(i = 0 ; i < n-1 ; i++){
    printf("%d ", S[i]);
  }
  printf("%d\n", S[i]);
  printf("%d\n", count);

  return 0;
}
  
void merge(int left, int mid, int right)
{
  int i, j, n1, n2, k, L[N/2 +1], R[N/2 +1];
  n1 = mid - left;
  n2 = right - mid;
  
  for(i = 0 ; i < n1 ; i++){
    L[i] = S[left + i];
  }
  for(i = 0 ; i < n2 ; i++){
    R[i] = S[mid + i];
  }
  L[n1] = INF+50;
  R[n2] = INF+50;
  i = 0;
  j = 0;
  for(k = left ; k < right ; k++){
    count++;
    if (L[i] <= R[j]){
      S[k] = L[i];
      i = i + 1;
    }
    else{ 
      S[k] = R[j];
      j = j + 1;
    }
  }
}
 
void mergeSort(int left, int right)
{
  int mid;
  
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}
