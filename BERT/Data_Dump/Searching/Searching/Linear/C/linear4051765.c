#include <stdio.h>
#define S_len 10000
#define T_len 500
#define TRUE 1
#define FALSE 0

int isMatched(int S[],int n, int Ti){
  int i=0;
  while(i != n){
    if(S[i] == Ti){
      return TRUE;
    }
    i++;
  }
  return FALSE;
}

int main(){
  int n,q,i, match=0;
  int S[S_len];
  int T[T_len];

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }

  for(i=0; i<q; i++){
    match += isMatched(S,n,T[i]);
  }
  
  printf("%d\n",match);
  return 0;
}

