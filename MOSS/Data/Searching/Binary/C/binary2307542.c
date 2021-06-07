#include <stdio.h>

int main(){
  
  int n1, n2, S[1000000], T[1000000];
  int i, j, count = 0;
  int l, m, r;
  
  scanf("%d",&n1);
  for(i = 0;i < n1;i++){
    scanf("%d", &S[i]);
  }
  
  scanf("%d",&n2);
  for(i = 0;i < n2;i++){
    scanf("%d",&T[i]);
  }
  
  for(i = 0;i < n2;i++){
    l = 0;
    r = n1;
    
    while(l < r){
      m = (l + r)/2;
      if(S[m] == T[i]){
	count++;  break;
      }
      else if(T[i] < S[m]){
	r = m;
      }
      else {l = (m + 1);}
    }
  } 
  
  printf("%d\n",count);
  return 0;
  
}
