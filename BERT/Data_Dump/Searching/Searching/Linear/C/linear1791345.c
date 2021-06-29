#include <stdio.h>
#define n 10000
#define q 500

int main (){
  
  int S, T, i, j, s[n], t[q], count=0;
  
  scanf("%d", &S);
  
  for(i=0; i<S; i++){
    scanf("%d", &s[i]);
  }
  
  scanf("%d", &T);
  
  for(j=0; j<T; j++){
    scanf("%d", &t[j]);
  }
  
  
  for(i=0; i<T; i++){
    for(j=0; j<S; j++){
      if(s[j]==t[i]){
	count++;
	break;
      }
    }
  }
  printf("%d\n", count);
  
  return 0;
}
