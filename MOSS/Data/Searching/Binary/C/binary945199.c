#include<stdio.h>
#define N 100000
#define Q 50000
int main(){
  int n, q, S[N], T[Q], l, m, r, i, C = 0;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }
  for(i = 0; i < q; i++){
    l = 0;
    r = n;
    while(l < r){
      m = (l + r) / 2;
      if(T[i] == S[m]){
	C++;
	break;
      }
      if(T[i] > S[m]) l = m + 1;
      else if(T[i] < S[m]) r = m;      
    }
  }
  
  printf("%d\n", C);
  return 0;  
}
