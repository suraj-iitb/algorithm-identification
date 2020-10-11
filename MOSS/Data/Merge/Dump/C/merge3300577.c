#include <stdio.h>

int cnt=0;

void merge(int A[],int left,int mid,int right)
{
  int n1,n2,i,j,k;
  n1=mid-left;
  n2=right-mid;
  int L[n1+1];
  int R[n2+1];
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];
  L[n1]=1000000001;
  R[n2]=1000000001;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }else{
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int A[],int left,int right)
{
  if(left+1<right){
    int mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}


int main()
{
  int n,i,A[500000];
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  mergeSort(A,0,n);
  for(i=0;i<n;i++) {
    printf("%d",A[i]);
    if(i==n-1) printf("\n");
    else printf(" ");
  }
  printf("%d\n",cnt);
  return 0;
}

