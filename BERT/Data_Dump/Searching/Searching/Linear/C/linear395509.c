#include <stdio.h>

int isIncludedInS(int x);

int S[10000],T[500];
int n,q;
int count = 0;

main(){

  int i;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
    count += isIncludedInS(T[i]);
  }

  printf("%d\n",count);

return 0;

}

int isIncludedInS(int x){

  int i;
  for(i=0; i<n; i++){
    if(x == S[i]){
      return 1;
    }
  }
  return 0;

}
