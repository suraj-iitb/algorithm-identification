#include <stdio.h>

int main()
{
  int i, j, S[10000], T[500], c=0, n, q, a=0;

  scanf("%d", &n);  
  for(i=0;i<n;i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);  
  for(j=0;j<q;j++){
    scanf("%d", &T[j]);
  }

  
  for(j=0;j<q;j++){
    for(i=0;i<n;i++){

      if(S[i] == T[j]){
	a = 1;
	break;
      }
    }
    if(a == 1){
      c++;
      a = 0;
    }
  }

  printf("%d\n", c);

  return 0;
}

