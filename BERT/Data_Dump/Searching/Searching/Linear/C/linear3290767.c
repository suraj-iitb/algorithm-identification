#include<stdio.h>
#define NOTFOUND 0
#define MAX 10000

int linearSearch(int n, int *A, int key){
  int i=0;
  A[n]=key;
  while(A[i]!=key)
    i++;
  if(i==n) return NOTFOUND;

  return 1;

}


int main(){
  int i,n,q,A[MAX],B[MAX],count=0;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&B[i]);
  }

  for(i=0;i<q;i++){
    if(linearSearch(n,A,B[i])==1) count++;
  }

  printf("%d\n",count);

  return 0;
}

