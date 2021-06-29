#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
#define N 100
void insertionSort(int *,int n);
int main(){
  int A[MAX];
  int n,i,v=0,j=0,l;
  scanf("%d",&n);
  if(n>N){
    end(1);
  }
  for(j=0;j<n;j++){
    scanf("%d",&A[j]);
  }
  insertionSort(A,n);
 return 0;
}
void insertionSort(int *A, int n){
  int i,v,j,l;
  for(i=1;i<=n;i++){
    for(l=0;l<n;l++){
      printf("%d",A[l]);
      if(l!=n-1){
	printf(" ");
      }
      if(l==n-1){
	printf("\n");
      }
    }
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
  }
}

