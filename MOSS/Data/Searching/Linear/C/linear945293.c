#include <stdio.h>

#define N 10000
#define Q 500
#define E 1000000000

main() {
  
  int n=0;
  int S[N];
  int q=0;
  int T[Q];
  int C=0;
  int i=0,j=0;
  
  scanf("%d",&n);
  
  if(n < 0 || N < n){
    return 0;
  }
  
  for(i=0;i < n;i++){
    scanf("%d",&S[i]);
    
    if(S[i] < 0 || E < S[i]){
      return 0;
    }
  }
  
  scanf("%d",&q);
  
  if(q < 0 || Q < q){
    return 0;
  }
  
  for(i=0;i < q;i++){
    scanf("%d",&T[i]);
    
    if(T[i] < 0 || E < T[i]){
      return 0;
    }
  }
  
  for(i=0;i < q;i++){
    for(j=0;j < n;j++){
      if(T[i] == S[j]){
	C++;
	break;
      }
    }
  }
  
  printf("%d\n",C);
  
  return 0;
}
