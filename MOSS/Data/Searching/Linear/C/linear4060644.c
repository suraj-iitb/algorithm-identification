#include<stdio.h>

int hikaku(int*,int,int);

int main(){

  int i,n1,n2,k,m=0;
  int A[10001],B;
  
  scanf("%d",&n1);
  for(i=0;i<n1;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&n2);
  for(i=0;i<n2;i++){
    scanf("%d",&B);
    if(hikaku(A,B,n1) != 0) m++;
  }
  printf("%d\n",m);
  return 0;
}

int hikaku(int A[],int key,int n1){
  int i = 0;
  A[n1] = key;
  while(A[i] != key) i++;
  if(i == n1) return 0;
  return 1;
}

