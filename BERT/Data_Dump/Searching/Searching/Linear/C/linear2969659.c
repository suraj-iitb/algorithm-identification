#include<stdio.h>
#define N 10000

int main(void){

  int n, q, C=0, i, j;
  int S[N], T[N];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }

  for(j=0;j<q;j++){
    for(i=0;i<n;i++){

      if(S[i] == T[j]){
	C++;
	break;
      }
    }
  }

  printf("%d\n", C);

  return 0;
}

