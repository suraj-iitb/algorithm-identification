#include<stdio.h>
#include<stdlib.h>

#define N 500000
#define M 1000000001

void merge(int[],int,int,int);
void mergesort(int[],int,int);

int S[N],cnt=0;

int main(){
  int n,i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  mergesort(S,0,n);

  for(i=0;i<n;i++){
    if(i!=0) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}

void merge(int *A,int left,int mid,int right)
{
  int n1,n2,i=0,j=0,k;
  int *L,*R;

  n1=mid-left;
  n2=right-mid;

  L=(int *)malloc(sizeof(int)*(n1+1));
  R=(int *)malloc(sizeof(int)*(n2+1));

  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }

  i=0;

  L[n1]=M;
  R[n2]=M;

  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
    }
    else{
      A[k]=R[j];
      j=j+1;
    }
  }
  free(L);
  free(R);

  return;
}

void mergesort(int *A,int left,int right)
{
  int mid;

  if(left+1<right){
    mid=(left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
  return;
}
