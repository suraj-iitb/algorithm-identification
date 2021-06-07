#include <stdio.h>
#define MAX 10000

int main(){
  int n, S[MAX], q, T[MAX], i, j, c = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &S[i]);
  scanf("%d", &q);
 
  for(j = 0; j < q; j++){
    scanf("%d", &T[j]);
    for(i = 0; i < n; i++){    

      if(S[i] == T[j]){
	c++;
	break;
      }
    }
  }
   
  printf("%d\n", c);

  return 0;
}
