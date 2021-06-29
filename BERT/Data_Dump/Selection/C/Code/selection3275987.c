#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define N 100
int bubbleSort(int *,int n);
int main(){
  int A[MAX];
  int n,j,cnt=0,l;
  scanf("%d",&n);
  if(n>N){
    end(1);
  }
  for(j=0;j<n;j++){
    scanf("%d",&A[j]);
  }
  cnt=bubbleSort(A,n);
  for(j=0;j<n;j++){
    printf("%d",A[j]);
    if(j!=n-1){
      printf(" ");
    }
    if(j==n-1){
      printf("\n");
    }
  }
  printf("%d\n",cnt);
  return 0;
}

int bubbleSort(int *A, int n){
  int minj,i,j,t,l,cnt=0;
  for(i=0;i<n-1;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]) minj=j;
    }     
    t=A[i];
    A[i]=A[minj];
    A[minj]=t;
    if(i!=minj)cnt++;
  }
  return cnt;
}

  

