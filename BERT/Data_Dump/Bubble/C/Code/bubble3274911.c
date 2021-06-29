#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define N 100
void bubbleSort(int *,int n);
int main(){
  int A[MAX];
  int n,i,v=0,j=0,l,cnt;
  scanf("%d",&n);
  if(n>N){
    end(1);
  }
  for(j=0;j<n;j++){
    scanf("%d",&A[j]);
  }
  bubbleSort(A,n);
  return 0;
}
void bubbleSort(int *A, int n){
  int i,v,j,l,flag=1,cnt=0;
  while(flag){
    flag=0;
    for(j=n-1;0<j;j--){
      if(A[j]<A[j-1]){
	v=A[j];
	A[j]=A[j-1];
	A[j-1]=v;
	cnt++;
	flag=1;
      }
    }
  }
    for(l=0;l<n;l++){
      printf("%d",A[l]);
      if(l!=n-1){
	printf(" ");
      }
      if(l==n-1){
	printf("\n");
      }
    }
    printf("%d\n",cnt);
}
  

