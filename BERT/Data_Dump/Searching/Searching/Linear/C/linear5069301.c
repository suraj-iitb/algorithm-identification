#include <stdio.h>

int linearSearch(int, int *, int);

int main(){
  int n,q,i;
  int S[10001],T[10001];
  int count=0;

  scanf("%d",&n);
  
  for(i=0; i<n; i++){
     scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }

  for(i=0; i<q; i++){
    count+=linearSearch(n,S,T[i]);
  }
  
  printf("%d\n",count);
  
  return 0;
}

int linearSearch(int n,int *A,int key){
  int i = 0;
  A[n] = key;
  
  while(A[i] != key){
    i++;
  }
  if(i==n){
    return 0;
  }
  return 1;
}

