#include <stdio.h>


int main() {
  
  int n;
  int S[10000];
  int q;
  int T[500];
  int i, j;
  int count = 0;

  scanf("%d",&n);
  
  for(i=0; i<n; i++)
    scanf("%d", &S[i]);

  scanf("%d", &q);

  for(i=0; i<q; i++)
    scanf("%d", &T[i]);

  /*Linear search*/
  for(i=0; i<q; i++){
    for(j=0; j<n; j++){
      if(S[j] == T[i]){
	count++;
	break;
      }
    }
  }

  printf("%d\n", count);
 
  
  return 0;
}

