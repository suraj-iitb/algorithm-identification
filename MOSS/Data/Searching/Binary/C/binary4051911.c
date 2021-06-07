#include <stdio.h>
#define S_len 100000
#define T_len 50000
#define TRUE 1
#define FALSE 0

int isMatched(int S[],int n, int Ti){
  int rgh = n;
  int lft = 0;
  int mid = n / 2;

  while(rgh > lft){
    mid = (rgh + lft)/2;
    if(Ti == S[mid]){
      return TRUE;
    }else if(S[mid] < Ti){
      lft = mid + 1;
    }else if(S[mid] > Ti){
      rgh = mid;
    }
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

