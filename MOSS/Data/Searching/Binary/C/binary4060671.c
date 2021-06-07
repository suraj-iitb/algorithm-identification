#include<stdio.h>

int nibungi(int*,int,int);

int main(){

  int i,n1,n2,k,m=0;
  int A[100001],B;

  scanf("%d",&n1);
  for(i=0;i<n1;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&n2);
  for(i=0;i<n2;i++){
    scanf("%d",&B);
    if(nibungi(A,B,n1) != 0) m++;
  }
  printf("%d\n",m);
  return 0;
}

int nibungi(int A[],int key,int n1){
  int center,left=0,right=n1;
  while(left<right){
    center = (left + right) / 2;
    if(A[center] == key) return center;
    else if(key < A[center]) right = center;
    else left = center + 1;
  }
  return 0;
}

