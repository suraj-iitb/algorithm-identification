#include <stdio.h>
#define N 500000

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int cnt=0;

int main()
{
  int n,A[N],i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  mergeSort(A, 0, n);

  for(i=0;i<n;i++){    
    if(i != 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);

  return 0;

}

void merge(int A[],int left,int mid,int right)
{
  int n1,n2,i,j,k;
  int L[N],R[N];

  n1 = mid -left;
  n2 = right -mid;

  for(i=0;i<n1;i++){
    L[i] = A[left + i];
  }
  for(i=0;i<n2;i++){
    R[i] = A[mid + i];
  }
  L[n1] = 1000000005;
  R[n2] = 1000000005;
  i = 0;
  j = 0;

  for(k=left;k<right;k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else{
      A[k] = R[j];
      j = j + 1;
    }
    cnt++;
  }
}

void mergeSort(int A[],int left,int right)
{
  int mid;
  if((left+1) < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
