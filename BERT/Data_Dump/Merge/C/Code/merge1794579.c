#include<stdio.h>
#include<stdlib.h>

#define N 500000
#define INFTY 1000000001

void merge(int[],int,int,int);
void mergeSort(int[],int,int);

int count=0,S[N];

int main(){
  int n;
  int i;

  /*   i n p u t   */
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }


  /*    m e r g e S o r t    */
  mergeSort(S, 0, n);


  /*   o u t p u t   */
  for(i=0;i<n;i++){
    if(i!=0) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

void merge(int *A, int left, int mid, int right){
  int n1,n2;
  int i,j,k;
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

  L[n1] = INFTY;
  R[n2] = INFTY;

  i=0;
  j=0;

  for(k=left;k<right;k++){
    count++;
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

void mergeSort(int *A,int left,int right){
  int mid;

  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }

  return;
}
