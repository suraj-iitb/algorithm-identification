#include<stdio.h>
#include<stdlib.h>
#define INFTY 1000000000

void merge(int*,int,int,int);
void mergeSort(int*,int,int);
int cnt=0;

int main(){
  int A[500000];
  int i,n;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A,0,n);

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1)
      printf(" ");
  }
  printf("\n%d\n",cnt);

  return 0;
}

void merge(int A[], int l, int m, int r){
  int n1,n2,i,j,k;
  int *L,*R;

  n1=m-l;
  n2=r-m;
  L=(int *)malloc(sizeof(int)*(n1+1));
  R=(int *)malloc(sizeof(int)*(n2+1));

  for(i=0;i<=n1-1;i++){
    L[i]=A[l+i];
  }
  for(i=0;i<=n2-1;i++){
    R[i]=A[m+i];
  }

  L[n1]=INFTY;
  R[n2]=INFTY;

  i=0;
  j=0;

  for(k=l;k<=r-1;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
      cnt++;
    }
    else{
      A[k]=R[j];
      j++;
      cnt++;
    }
  }
  free(L);
  free(R);
}

void mergeSort(int A[],int l,int r){
  int i,m;
  if(l+1<r){
    m=(l+r)/2;
    mergeSort(A,l,m);
    mergeSort(A,m,r);
    merge(A,l,m,r);
  }
}
