#include <stdio.h>
#define MAX 500000
#define S 2000000000

int L[MAX/2+2],R[MAX/2+2];
int c;

void merge(int *A, int n, int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right -mid;
  int i;
  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];
  L[n1]=S;
  R[n2]=S;
  i=0;
    int j=0, k=0;
  for(j=left;j<right;j++){
    c++;
    if(L[i]<=R[k]){
      A[j]=L[i];
      i++;
    }else{
      A[j]=R[k];
      k++;
    }
  }
}

void mergeSort(int *A,int n, int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,n,left,mid);
    mergeSort(A,n,mid,right);
    merge(A,n,left,mid,right);
  }
}
int main(){
  int A[MAX],n,i;
  c=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  mergeSort(A,n,0,n);
  for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n",A[i]);
    else  printf("%d ",A[i]);
  }
  printf("%d\n",c);
  return 0;
}
