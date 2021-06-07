#include <stdio.h>
#include <stdlib.h>

int main(){
  int n,q,C = 0,i,j;
  int *S;
  int *T;

  scanf("%d",&n);
  S = (int *)malloc(sizeof(int) * (n+1));
  for(i = 0;i < n;i++)
    scanf("%d",&S[i]);
  
  scanf("%d",&q);
  T = (int *)malloc(sizeof(int) * q);
  for(i = 0;i < q;i++)
    scanf("%d",&T[i]);

  for(i = 0;i < q;i++){
    S[n] = T[i];
    for(j = 0;j < n;j++){
      if(S[j] == S[n]){
	C++;
	break;
      }
    }
  }

  printf("%d\n",C);

  free(S);
  free(T);
  return 0;
}

