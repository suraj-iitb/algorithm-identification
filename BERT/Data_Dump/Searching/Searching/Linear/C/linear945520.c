#include<stdio.h>
#define N 10000
#define Q 500


main(){  
  int i,n,S[Q],j,q,T[N],count=0;
  
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  for(i=0;i<n;i++){
    for(j=0;j<q;j++){    
      if(S[i]==T[j]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);

  return 0;
}
