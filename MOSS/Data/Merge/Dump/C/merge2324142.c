#include<stdio.h>
#define N 500000
#define INFTY 1000000000

void merge(int *,int,int,int);
void mergesort(int *,int,int);

int cnt = 0;

int main () {

  int i,n,a[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%d",&a[i]);
  }

  mergesort(a,0,n);

    for(i=0;i<n;i++){
    if(i != n-1)
      printf("%d ",a[i]);
    else if(i == n-1)
      printf("%d\n",a[i]);
  }
  printf("%d\n",cnt);

return 0;
}

void mergesort(int *A,int left,int right){
  int mid;
  if (left+1 < right){
  mid = (left + right) / 2;
  mergesort(A,left,mid);
  mergesort(A,mid,right);
  merge(A,left,mid,right);
  }
}

void merge (int *A,int left,int mid,int right){
  int i,j,k,n1,n2,L[N],R[N];
  n1 = mid - left;
  n2 = right - mid;

  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
    A[k] = L[i];
    i=i+1;
    }
    else{
    A[k] = R[j];
    j=j+1;
    }
  }
}
