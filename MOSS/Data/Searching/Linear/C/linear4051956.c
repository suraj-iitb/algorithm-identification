#include <stdio.h>

int main(){
  int n = 0, q = 0;
  int i = 0, j = 0, cnt = 0;
  int S[10000], T[500];

  /*Input S[N]*/
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }
  
  /*Input T[N]*/
  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
    /*
    if(i > 0){
      for(j = 0; j < i; j++){
	if(T[i] == T[j])scanf("%d",&T[i]);
      }
    }
    */
  }

  /*Search*/
  for(i = 0; i < q; i++){
    for(j = 0; j < n; j++){
      if(S[j] == T[i]){
	cnt++;
	break;
      }
    }
  }

  /*Print*/
  printf("%d\n",cnt);
}

