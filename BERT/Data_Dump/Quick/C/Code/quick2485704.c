#include <stdio.h>
#include <stdlib.h>


#define MAX 100000
#define FR 2000000000
int N;

typedef struct{
  char sign;
  int number;
}QUICK;

QUICK L[MAX/2+2];
QUICK R[MAX/2+2];

QUICK *A;
QUICK *B;


int partition(QUICK *,int,int,int);
void merge(QUICK *,int ,int ,int,int );
void mergeSort(QUICK *,int ,int ,int);
void quickSort(QUICK *,int ,int ,int);

#define MAX 100000
#define RF 2000000000
int N;

int main(){
  int i,j,x;
  scanf("%d",&N);
  A=malloc(sizeof(QUICK) * N);
  B=malloc(sizeof(QUICK) * N);
  char ARRAY[10];
  int stable = 1;

  for(i=0;i<N;i++){
    scanf("%s %d",ARRAY,&x);
    A[i].sign = ARRAY[0];
    B[i].sign = ARRAY[0];
    A[i].number = x;
    B[i].number = x;
  }

  mergeSort(A,N,0,N);
  quickSort(B,N,0,N-1);

  for (i=0;i<N;i++){
    if(A[i].sign != B[i].sign){
      stable = 0;
    }
  }

  if(stable == 1){
    printf("Stable\n");
  }
  else printf("Not stable\n");
  for(i=0;i<N;i++){
    printf("%c %d\n",B[i].sign,B[i].number);
  }

  free(A);
  free(B);
  return 0;
}

void merge(QUICK *A,int n,int left,int mid,int right){
  int i,j,k;
  int a,b;

  a=mid - left;
  b=right - mid;

  for(i=0;i<a;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<b;i++){
    R[i]=A[mid+i];
  }

  L[a].number = R[b].number = FR;

  i=j=0;
  for(k=left;k<right;k++){
    if(L[i].number <= R[j].number){
      A[k] = L[i++];
    }
    else{
      A[k] = R[j++];
    }
  }
}

void mergeSort(QUICK *A,int n,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,n,left,mid);
    mergeSort(A,n,mid,right);
    merge(A,n,left,mid,right);
  }
}

int partition(QUICK *A,int n,int p,int r){
  int i,j;
  QUICK t,x,a,b;
  x = A[r];
  i = p-1;
  for(j=p;j<=r-1;j++){
    if(A[j].number <= x.number){
      i++;
      // A[i] ??¨ A[j] ?????????
      a=A[i];
      A[i]=A[j];
      A[j]=a;
    }
  }
  //A[i+1] ??¨ A[r] ?????????
  b=A[i+1];
  A[i+1]=A[r];
  A[r]=b;

  return i+1;
}

void quickSort(QUICK *A,int n,int p,int r){
  int q;
  if(p<r){
    q=partition(A,n,p,r);
    quickSort(A,n,p,q-1);
    quickSort(A,n,q+1,r);
  }
}
