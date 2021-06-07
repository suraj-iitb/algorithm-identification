#include<stdio.h>
#define N 10000
#define Q 500
int main(){
  int n, q, S[N], T[Q], i, j, C = 0, f;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &T[i]);
  }
  for(i = 0; i < q; i++){
    f = 0;
    for(j = 0; j < n; j++){
      if(f == 0){
	if(T[i] == S[j]){
	  C++;
	  f++;
	  break;
	}
      }
    }
  }
  printf("%d\n", C);
  return 0;  
}
