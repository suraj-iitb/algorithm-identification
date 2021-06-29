#include<stdio.h>

#define N 10000

int linearSearch(int,int *,int);

int main(void){
  int S[N];
  int n,q,T,C=0;
  int i;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T);
    C += linearSearch(n,S,T);
  }

  printf("%d\n",C);
  
  return 0;
}

int linearSearch(int n, int *S, int key){
  int i=0;
  S[n] = key;
  while(S[i] != key) i++;
  if(i == n) return 0;
  else return 1;
}

