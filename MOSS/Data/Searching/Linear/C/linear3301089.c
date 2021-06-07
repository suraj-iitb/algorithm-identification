#include<stdio.h>

int search(int *,int,int);

int main(){
  int S[1000000],k,n,q,C = 0;
  int i,j;
  
  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&S[i]);
  
  scanf("%d",&q);
  for(j = 0; j < q; j++) {
    scanf("%d",&k);
    if(search(S,n,k)) C++;
  }

  printf("%d\n",C);
  return 0;
}

int search(int *S,int n,int k){
  int i = 0;
  S[n] = k;
  while(S[i] != k) i++;
  return i != n;
}
  

