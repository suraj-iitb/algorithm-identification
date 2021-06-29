#include <stdio.h>
#include <stdlib.h>

int main(){
  int  n, q;
  int *S,*T;
  int  i, m, r, l, c=0;

  /*scan S*/
  scanf("%d", &n);
  S = (int *)malloc(sizeof(int) * n);
  for(i=0; i<n; i++)
    scanf("%d", &S[i]);

  /*scan T*/
  scanf("%d", &q);
  T = (int *)malloc(sizeof(int) * q);
  for(i=0; i<q; i++)
    scanf("%d", &T[i]);

  /*calc the ans*/
  for(i=0; i<q; i++){
    l = 0;
    r = n;
    while(l < r){
      m = (l + r) / 2;
      if(S[m] == T[i]) {c++; break;}
      else if(S[m] > T[i]) r = m;
      else l = m + 1;
    }
  }
  /*print the ans*/
  printf("%d\n", c);

  return 0;
}
