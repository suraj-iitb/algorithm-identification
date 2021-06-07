#include <stdio.h>

main(){
  int s[100000],t[50000],i,j,n,q,count=0,L,R,M;
  
  scanf("%d",&n);
  
  for(i=0;i < n;i++) scanf("%d",&s[i]);
  
  scanf("%d",&q);
  
  for(j=0;j < q;j++) scanf("%d",&t[j]);
  
 
  for(j=0;j<q;j++){
    L = 0;
    R = n;
   
   
  while(L<R){
    M = (L+R)/2;
    if(s[M] == t[j]){
      count++;
      break;
    }
    if(s[M] < t[j]){
      L = M+1;
    }
    if(s[M] > t[j]){
      R = M;
    }
  }
  }

 printf("%d\n",count);
 
 return 0;
  
}
