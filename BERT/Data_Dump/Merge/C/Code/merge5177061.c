#include <stdio.h>
#define INFTY 1000000000
#define N 500000
int A[N],L[N],R[N],count=0;

void merge(int A[],int left,int mid,int right){
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
/*L[0...n1], R[0...n2] を生成*/
  for (i = 0; i< n1;i++)
    L[i] = A[left + i];
  for (i = 0; i< n2;i++)
    R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for (k = left; k<right; k++, count++){
    if (L[i] <= R[j]){
      A[k] = L[i];
	i = i + 1;
    }
  else {
      A[k] = R[j];
  j = j + 1;
	}
  }
}

void mergeSort(int A[],int left,int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
      }
}

  int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&A[i]);

    mergeSort(A,0,n);

      for(i=0;i<n-1;i++){
	printf("%d ",A[i]);
      }
      printf("%d",A[n-1]);
    printf("\n%d\n",count);

    return 0;
  }

