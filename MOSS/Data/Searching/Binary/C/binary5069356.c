#include <stdio.h>
#define SMAX 100000
#define TMAX 50000

int main(){
  int n, q;
  int S[SMAX], T[TMAX];
  int i;
  int l, r, m;
  int cnt = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &S[i]);

  scanf("%d", &q);
  for(i = 0; i < q; i++) scanf("%d", &T[i]);

  for(i = 0; i < q; i++){

    l = 0;
    r = n;
    m = (l+r)/2;
    
    while(l != r){

      if(S[m] >= T[i]) r = m;
      else l = m + 1;

      m = (l+r)/2;
      
      if(S[m] == T[i]){
	cnt++;
	break;
      }
    }
    
  }
  
  printf("%d\n", cnt);
  return 0;
}

