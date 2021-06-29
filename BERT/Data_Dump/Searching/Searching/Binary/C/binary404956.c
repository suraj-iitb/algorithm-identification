#include<stdio.h>

main(){

  int i,j,n,q,left,right,S[100001],T[50001],U[50001],mid;
  int sumcount = 0;
   
  scanf("%d",&n);
   
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }
   
  scanf("%d",&q);
   
  for(j = 0; j < q; j++){
    scanf("%d",&T[j]);
  }

  
  for(j = 0; j < q; j++){
    
    left = 0;
    right = n;    
    
    while(left != mid || right != mid){
      
    mid = (left + right) / 2;

      if(S[mid] < T[j]) {
	left =  mid + 1;
      } else if(S[mid] > T[j]) {
	right =  mid;
      } else if(S[mid] == T[j]) {
	sumcount++;
	break;
      }

    }
    
  }
  
  printf("%d\n",sumcount);
  
  return 0;

}
