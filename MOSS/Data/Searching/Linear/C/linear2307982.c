#include <stdio.h>
#define SMAX 10000
#define TMAX 500

int main( )
{
  int i=0,j=0,n,q,count=0;
  int S[SMAX],T[TMAX];
  
  scanf("%d",&n);
 
  while(i < n){
    scanf("%d",&S[i]);
    i++;
  }
  
  scanf("%d",&q);

  
  while(j < q ){
  scanf("%d",&T[j]);
  j++;
  }

  for(j=0;j < q;j++){
    for(i=0;i < n;i++){
      if(T[j]==S[i]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
