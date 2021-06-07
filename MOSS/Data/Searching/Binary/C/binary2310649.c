#include <stdio.h>
#define MAX 100000

int main()
{
  int l, r, m, n, S[MAX], q, T[MAX], i, j, c = 0;

  
  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &S[i]);
  scanf("%d", &q);
 

  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
    r = n;
    l = 0;
    while(l < r){
      m = (l + r) / 2;
      if(S[m] == T[i]){
	c++;
	break;
      }
      else if(T[i]< S[m]) r = m;
      else l = m + 1;
    }
  }
  printf("%d\n", c);

  return 0;
}
