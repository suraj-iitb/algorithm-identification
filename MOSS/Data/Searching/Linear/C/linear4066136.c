#include <stdio.h>
int linearSearch();
int S[10005], n, T, q, C; 
int main(){
  int i;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&T);
    if( linearSearch(S, n, T) == 0){
      C++;
    }
  }
  printf("%d\n",C);
  return 0;
}

int linearSearch(){
  int i=0;
  S[n] = T;
  while(S[i] != T){
    i++;
  }
  if(i==n){
    return 1;
  }
  return 0;
}

