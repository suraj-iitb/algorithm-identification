#include<stdio.h>

#define N 500000
#define M 1000000000

void merge(int [], int, int, int);
void mergeSort(int [], int, int);

int L[N/2+2],R[N/2+2];
int c=0;

main(){
  int i,n;
  int A[N];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  mergeSort(A,0,n);

  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",c);
  return 0;
}

void merge(int A[], int l, int m, int r){
  int n1;
  int n2;
  int i,j,k;
  n1=m - l;
  n2=r - m;

  for(i=0;i<n1;i++) L[i]=A[l+i];
  for(i=0;i<n2;i++) R[i]=A[m+i];

  L[n1]=R[n2]=M;
  i=0;
  j=0;

  for(k=l;k<r;k++){
    c++;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
  }
}

void mergeSort(int A[], int l, int r){
  int m;
  if(l+1<r){
    m=(l+r)/2;
    mergeSort(A, l, m);
    mergeSort(A, m, r);
    merge(A, l, m, r);

  }
}

