#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int main(){
  int i,j,n,q,c,key,cnt = 0;
  int S[MAX],T[MAX];
  
  scanf("%d",&n);
  if(n>=10001) exit(1);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  if(q>=501) exit(2);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(S[j] == T[i]){
	cnt++;
	break;
      }
    }
  }

  printf("%d\n",cnt);
  
  return 0;
}

