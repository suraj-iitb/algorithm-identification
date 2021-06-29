#include <stdio.h>
int main(){

  int n,q,S[10000],T[10000],i,j,count=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){

    scanf("%d",&S[i]);

  }
   scanf("%d",&q);

  for(i=0;i<q;i++){

    scanf("%d",&T[i]);
    j=0;
    while(1){
      if(S[j]==T[i]){
	count++;
	break;
      }
      j++;
      if(j==n)break; 
    
  }
  }

  printf("%d\n",count);

  return 0;
}

  
  

