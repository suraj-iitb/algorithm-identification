#include <stdio.h>

int main(){
  int n=0,m=0,i=0,L=0,M=0,R=0,c=0;

  scanf("%d",&n);

  int S[n];

  for(i=0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&m);

  int T[m];

  for(i=0; i < m; i++){
    scanf("%d",&T[i]);
  }

  for(i=0; i < m; i++){
    L = 0;
    R = n;
    while(L < R){
      M = (L + R)/2;
      if(S[M] == T[i]){
	T[i] = -1;
	c++;
	break;
      } else if(T[i] < S[M]){
	R = M;
      } else {
	L = M + 1;
      }
    }
  }

  printf("%d\n",c);

  return 0;
}

