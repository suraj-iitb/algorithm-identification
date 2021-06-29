#include<stdio.h>

main(){

  int i,j,k,n,q,S[10001],T[501],U[501],frag;
  int count = 0, sumcount = 0;
  
  scanf("%d",&n);
  
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
  }
  
  
  for(i = 0; i < n; i++){
    for(j = 0; j < q; j++){

      frag = 0;

      if(S[i] == T[j]){	
	for(k = 0; k < count; k++){
	  if(U[k] == T[j] && U[k] == S[i]){
	    frag = 1;
	    break;
	  }
	}
	
	if(frag == 1) continue;
	sumcount++;
	U[count] = T[j];
	count++;
      }
      
    }
    
  }
  
  printf("%d\n",sumcount);
  
  return 0;
}
