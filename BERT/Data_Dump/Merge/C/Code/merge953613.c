#include<stdio.h>
#include<stdlib.h>

#define SENTINEL 1000000001

void Merge(int*,int,int,int);
void Merge_sort(int*,int,int);

int cnt=0;

int main(void){
  int n;
  int i;
  int *S;

  scanf("%d",&n);

  S=(int*)malloc(sizeof(int)*n);

  for(i=0;i<n;i++)scanf("%d",&S[i]);

  Merge_sort(S,0,n);

  printf("%d",S[0]);
  for(i=1;i<n;i++)printf(" %d",S[i]);
  printf("\n%d\n",cnt);

  free(S);

  return 0;
}


void Merge(int A[],int left,int mid,int right){
  int n1,n2;
  int *L,*R;
  int i,j,k;

  n1=mid-left;
  n2=right-mid;

  L=(int*)malloc(sizeof(int)*(n1+1));
  R=(int*)malloc(sizeof(int)*(n2+1));

  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];

  L[n1]=SENTINEL;
  R[n2]=SENTINEL;

  i=0;
  j=0;

  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
    cnt++;
  }
}


void Merge_sort(int A[],int left,int right){
  int mid;

  if(left+1<right){
    mid=(left+right)/2;
    Merge_sort(A,left,mid);
    Merge_sort(A,mid,right);
    Merge(A,left,mid,right);
  }
}
