#include<stdio.h>
int Merge(int *,int,int,int);
int MergeSort(int *,int,int);
int sum=0;
int main()
{
  int i,n;
  int S[500000];

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  
  MergeSort(S,0,n);

  for(i=0;i<n-1;i++){
    printf("%d ",S[i]);
  }
  printf("%d\n",S[i]);
  printf("%d\n",sum);
  return 0;
}

int MergeSort(int *A,int left,int right)
{  
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    MergeSort(A,left,mid);
    MergeSort(A,mid,right);
    Merge(A,left,mid,right);
  }
  else return 0;
}

int Merge(int *A,int left,int mid,int right){
  int k,n1,n2,L[500000],R[500000],i,j;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1]=R[n2]=(1e9)+1;
  i=j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
      sum++;
    }
    else{
      A[k]=R[j];
      j++;
      sum++;
    }
  }
}
