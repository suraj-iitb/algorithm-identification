#include<stdio.h>
#include<math.h>
void merge(int *, int, int, int);
void mergesort(int *, int, int);

int count=0;

int main()
{
  int i, n, S[1000000];

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &S[i]);
  }

  mergesort(S, 0, n);

  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i < n-1)
      printf(" ");
  }

  printf("\n%d\n", count);
  return 0;
}


void merge(int *A, int left, int mid, int right)
{
  int n1=mid - left , n2=right - mid;
  int L[n1], R[n2];
  int i, j, k;
  
  for(i=0; i<n1; i++){
    L[i]=A[left+i];
  }

  for(i=0; i<n2; i++){
    R[i]=A[mid+i];
  }
  
  L[n1]=1000000000;
  R[n2]=1000000000;

  i=0;
  j=0;

  for(k=left; k<right; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i+=1;
    }
    else {
      A[k] = R[j];
      j+=1;
    }
    count++;
  }

}

void mergesort(int *A, int left, int right)
{
  int mid;
  if(left+1 < right){
    mid=(left+right)/2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, mid, right);
  }
}
