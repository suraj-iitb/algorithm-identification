#include<stdio.h>

#define N 100

int bubbleSort(int *, int );

int main(){

  int A[N],i,n,cunt;

  scanf("%d",&n);

  for(i=0;i<n;i++)scanf("%d",&A[i]);

  cunt =  bubbleSort(A,n);

  for(i=0;i<n-1;i++)printf("%d ",A[i]);
  printf("%d\n",A[i]);
  printf("%d\n",cunt);
  
  return 0;
}

int bubbleSort(int A[], int n){
  int i,j, flag = 1 ,key ,cunt = 0;
  for(j = 0;flag ;j++){
    flag = 0;
    for(i=n-1;i>= j+1;i--){
      if(A[i]<A[i-1]){
	key = A[i];
	A[i]=A[i-1];
	A[i-1]=key;
	flag = 1;
	cunt++;
      }	
    }
  }
  return cunt;
}
