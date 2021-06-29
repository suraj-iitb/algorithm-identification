#include<stdio.h>
int Merge(int *,int,int,int);
int MergeSort(int *,int,int);
int SUM=0;


int MergeSort(int *A,int left,int right)
{  
  int center;
  if(left+1<right){
    center=(left+right)/2;
    MergeSort(A,left,center);
    MergeSort(A,center,right);
    Merge(A,left,center,right);
  }
  else return 0;
}

int Merge(int *A,int le,int mid,int rig)
{
  int i,j,N,a,b;
  int L[500000],R[500000];
  a=mid-le;
  b=rig-mid;
  for(i=0;i<a;i++){
    L[i]=A[le+i];
  }
  for(i=0;i<b;i++){
    R[i]=A[mid+i];
  }
  L[a]=1000000000;
  R[b]=1000000000;
  i=0;
  j=0;
  for(N=le;N<rig;N++){
    if(L[i]<=R[j]){
      A[N]=L[i];
      i=i+1;
      SUM=SUM+1;
    }
    else{
      A[N]=R[j];
      j=j+1;
      SUM=SUM+1;
    }
  }
}

int main()
{
  int i,n,S[500000];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  MergeSort(S,0,n);

  for(i=0;i<n-1;i++){
    printf("%d ",S[i]);
  }
  printf("%d",S[i]);
  printf("\n");
  printf("%d",SUM);
  printf("\n");
  return 0;
}

