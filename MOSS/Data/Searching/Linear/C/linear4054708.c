#include<stdio.h>
int main(){
  int n,q,S[10000],T[500],i,j,cnt=0;
  scanf("%d",&n);
  for(i=0;i<=n-1;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<=q-1;i++) scanf("%d",&T[i]);
  
  for(i=0;i<=q-1;i++){
    for(j=0;j<=n-1;j++){
      if(S[j]==T[i])break;
	
      
    }
     if(S[j]==T[i])cnt++;
  }
 
  printf("%d\n",cnt);
  return 0;
}

