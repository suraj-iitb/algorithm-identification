#include <stdio.h>
main(){

  int S[10000],T[500];
  int n,q,i,j,ans = 0;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){

    scanf("%d",&S[i]);

  }

  scanf("%d",&q);

  for(i = 0 ; i < q ; i++ ){

    scanf("%d",&T[i]);

  }

  for(i = 0 ; i < n ; i++){
    for(j = 0 ; j < q ; j++){

      if(S[i] == T[j]) {ans++;
	T[j] = 10000000000;
      }
    }
  }

  printf("%d\n",ans);

  return 0;

}
