#include <stdio.h>
#define N 10000
#define Q 500

main(){  
  int n,q,i,j,count=0;
  int S[N],T[Q];
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }
  
    for(j = 0 ; j < q ; j++){
      for(i = 0 ; i < n ; i++){
      if(T[j]==S[i]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
       
