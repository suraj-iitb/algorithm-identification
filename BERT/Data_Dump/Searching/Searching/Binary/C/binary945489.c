#include <stdio.h>
#define N 100000
#define Q 50000

main(){  
  int n,q,i,j,k,l,count=0;
  int S[N],T[Q];
  
  scanf("%d",&n);
  scanf("%d",&S[0]);

  for(i=1,l=1;i<n;i++){
    scanf("%d",&k);
    if(k > S[l-1]){
      S[l]=k;
      l++;
    }
  }
  
  scanf("%d",&q);
 
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }

    for(j = 0 ; j < q ; j++){
      for(i = 0 ; i < l ; i++){
	if(T[j]==S[i]){
	  count++;
	  break;
	}
      }
    }
    printf("%d\n",count);
    return 0;
}
