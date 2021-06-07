#include <stdio.h>
#include <stdlib.h>


int main()
{
  int n,  q ,C=0,i,j;

  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  

    for(i=0;i<q;i++){
      for(j=0;j<n;j++){
	
	if(S[j]==T[i]){
	  C++;
	  break;
	}
	
      }
    }


  
  printf("%d\n",C);

  return 0;
}
