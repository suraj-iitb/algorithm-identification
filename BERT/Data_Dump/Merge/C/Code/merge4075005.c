#include<stdio.h>
#include<math.h>
#define N 500000

int L[N/2+2],R[N/2+2],cnt=0;
void merge(int *,int,int,int,int);
void mergeSort(int*,int,int,int);
int main()
{
  int n,i;
  scanf("%d",&n);
  int A[n];
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  mergeSort(A,n,0,n);

  for(i=0;i<n;i++){
    if(i!=n-1)
      printf("%d ",A[i]);
    else
      printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}

void merge(int *A,int n,int left,int mid,int right)
{
  int n1 = mid-left;
  int n2 = right-mid;
  int i,j,k;
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];
  L[n1]=R[n2]=2000000000;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]) A[k]=L[i++];
    else A[k] = R[j++];
                         }
}

void mergeSort(int *A,int n,int left,int right)
{
  int mid;
  if(left+1<right){
  mid=(left+right)/2;
  mergeSort(A,n,left,mid);
  mergeSort(A,n,mid,right);
  merge(A,n,left,mid,right);
                   }
}



