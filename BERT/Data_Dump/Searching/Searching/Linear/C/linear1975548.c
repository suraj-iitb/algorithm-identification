#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n,q;
  int *S,*T;
  int C=0;
  int i,j;

  scanf("%d",&n);
  S = (int*)malloc(sizeof(int)*n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  T = (int*)malloc(sizeof(int)*q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }

  for(i=0; i<q; i++){
    for(j=0; j<n; j++){
      if(T[i] == S[j]){
	C++;
	break;
      }
    }
  }

  printf("%d\n",C);

  free(S);
  free(T);
  
  return(0);
}
