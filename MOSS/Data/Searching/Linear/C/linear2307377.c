#include <stdio.h>

#define SMAX 10000
#define TMAX 500
#define NOT_FAUND -1

int linearSearch(int*,int,int);

int main(){

  int i,n,q,S[SMAX],T[TMAX],count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    if(linearSearch(S,n,T[i])!=NOT_FAUND){
      count++;
    }
  }

  printf("%d\n",count);
  return 0;
}

int linearSearch(int* A,int n,int key){

  int i=0;
  A[n]=key;
  while(A[i]!=key){
    i++;
  }
  if(i==n) return NOT_FAUND;
  return i;
  
}
