#include <stdio.h>
main(){

  int S[100000],T[50000];
  int n,q,i,j,ans = 0,mid,left = 0,right;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){

    scanf("%d",&S[i]);

  }

  scanf("%d",&q);

  for(i = 0 ; i < q ; i++ ){

    scanf("%d",&T[i]);

  }

 

  for(i = 0 ; i < q ; i++ ){
   
    left = 0;
    right = n;

  while(left<=right)
    {
      
      mid = (left + right) / 2;

      if(S[mid] == T[i]) {
	ans++;
	break;
      }
      if(S[mid] < T[i]) left = mid + 1;    
      else right = mid - 1;
      
    }
  }
  
  
  
  
  printf("%d\n",ans);
  
  return 0;

}
