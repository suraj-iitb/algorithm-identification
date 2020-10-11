#include <stdio.h>
#include <stdlib.h>

int merge(int *,int,int,int,int);
int mergeSort(int *,int,int,int);

int count;
int L[500000/2+2],R[500000/2+2];

int main()
{
  int A[500000],n,i;
  count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(A[i] >= 1000000001){
	return 0;
      }
  }

  mergeSort(A,0,n,n);

  for(i=0;i<n;i++){
    if(i)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

int merge(int A[],int left,int mid,int right,int n)
{
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  /*L=(int*)malloc((n1+1)*sizeof(int));
    R=(int*)malloc((n2+1)*sizeof(int));*/
  for (i=0;i<n1;i++)L[i] = A[left + i];
  for (i=0;i<n2;i++)R[i] = A[mid + i];
  L[n1] = 1000000001;
  R[n2] = 1000000001;
  i = 0;
  j = 0;
    for (k=left;k<right;k++){
      count++;
      if (L[i] <= R[j]){
	A[k] = L[i];
	i = i + 1;
      }
      else{ 
	A[k] = R[j];
	j = j + 1;
      }
    }
    return;
}

int mergeSort(int A[],int left,int right,int n){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid,n);
    mergeSort(A,mid,right,n);
    merge(A,left,mid,right,n);
      }
return;
}

