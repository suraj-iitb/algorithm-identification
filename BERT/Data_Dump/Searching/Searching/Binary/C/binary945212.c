#include <stdio.h>
main(){
  int i,j,n1,n2,S[100000],T[50000],count=0,l=0,r,m;
  scanf("%d",&n1);
  for(i = 0; i < n1; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&n2);
  for(i = 0; i < n2; i++){
    scanf("%d",&T[i]);
  }
  for(i = 0; i < n2; i++){
    l = 0;
    r = n1;
    while(l < r){
      m = (l+r)/2;
      if(T[i] == S[m]){
	count++;
        break;
      }
      if(T[i] > S[m]){
	l = m + 1;
      }
      else if(T[i] < S[m]){
	r = m;
      }
    }
  }  
  printf("%d\n",count);
  
  return 0;
}
