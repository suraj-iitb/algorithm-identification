#include<stdio.h>
#define INF 2000000000

void merge(int *,int,int,int);
void mergesort(int *,int,int);

int A[100000000], L[1000000],R[1000000];
int count=0;

int main(){
  int i,n;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  mergesort(A,0,n);

  for(i=0;i<n;i++){
    if(i>0) printf(" %d",A[i]);
    else printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

void merge(int *A,int left,int mid,int right){
  int i,j,k;
  int n1 = mid - left;
  int n2 = right - mid;

  for(i=0;i<n1;i++) L[i]=A[left+i];


  for(i=0;i<n2;i++) R[i]=A[mid+i];

  L[n1] = INF;
  R[n2] = INF;

  i = 0;
  j = 0;

  for(k=left;k<right;k++){
    count++;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
    }else{
      A[k]=R[j];
      j=j+1;
    }
  }
}

void mergesort(int *A,int left, int right){
  int mid;
  if(left+1<right){
    mid = (left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}

