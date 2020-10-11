#include <stdio.h>
#include <stdlib.h>

int cnt;

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int main()
{
  int i, n, right, left;
  int *S;

  cnt = 0;

  scanf("%d",&n);
  S = (int *)malloc(sizeof(int) * n);
  if(S == NULL) exit(0);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }

  mergeSort(S,0,n);

  for(i = 0;i < n;i++){
    printf("%d",S[i]);
    if(i != (n - 1)) printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);

  free(S);

  return 0;
}

void merge(int *A,int left,int mid,int right)
{
  int i, j, k, n1, n2;
  int *R, *L;

  n1 = mid - left;
  n2 = right - mid;

  L = (int *)malloc(sizeof(int) * (n1 + 1));
  if(L == NULL)           exit(0);

  R = (int *)malloc(sizeof(int) * (n2 + 1));
  if(R == NULL)           exit(0);

  for(i = 0; i < n1;i++){
    L[i] = A[left + i];
  }
  for(i = 0; i < n2;i++){
    R[i] = A[mid + i];
  }

  L[n1] = 1000000000;
  R[n2] = 1000000000;

  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      cnt++;
    }
    else{
      A[k] = R[j];
      j = j + 1;
      cnt++;
    }
  }
  free(R);
  free(L);
}

void mergeSort(int *A,int left,int right)
{
  int mid;

  if((left + 1) < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

