#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 100000

int partition(int*,int,int);
void quickSort(int*,int,int);
int isStable(int *,int *,int);

int B[MAX];
char C[MAX];

int main(){

  //unsigned short *A;
  int A[MAX];

  int i,k=0,n;
  int x,p,q,r;


  scanf("%d",&n);

  p=0;
  r=n-1;

  //A=malloc(sizeof(short)*n+1);

  for(i=0;i<n;i++){
    scanf(" %c %d",&C[i],&A[i]);
    B[i]=i;
  }

  quickSort(A,p,r);


  if(isStable(A,B,n)==0) printf("Not stable\n");
  else printf("Stable\n");


  for(i=0;i<n;i++){
    printf("%c %d\n",C[i],A[i]);
  }
  


  return 0;
  
}


int partition(int* A,int p,int r){
  int i,j,x,mv,bmv;
  char cmv;
  i=p-1;
  x=A[r];

  for(j=p;j<r;j++){
    if(A[j]<=x){
      i++;

      mv=A[i];
      bmv=B[i];
      cmv=C[i];
      A[i]=A[j];
      B[i]=B[j];
      C[i]=C[j];
      A[j]=mv;
      B[j]=bmv;
      C[j]=cmv;
    }

  }


  mv=A[i+1];
  bmv=B[i+1];
  cmv=C[i+1];
  A[i+1]=A[r];
  B[i+1]=B[r];
  C[i+1]=C[r];
  A[r]=mv;
  B[r]=bmv;
  C[r]=cmv;

  return i+1;
}


void quickSort(int* A,int p,int r){
  int q;
  if(p<r){
    q=partition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
}

int isStable(int *A,int *B,int n){
  int i;
  for(i=0;i+1<n;i++){
    if(A[i]==A[i+1] && B[i]>B[i+1])return 0;
  }
  return 1;
}
