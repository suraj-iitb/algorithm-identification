/*線形探索*/
#include <stdio.h>
#define N 10000
#define Q 500
int main(){
  int s[N], t[Q], n, q, i, j, count=0;

  scanf("%d", &n);

  for (i=0; i<n; i++){
    scanf("%d", &s[i]);
  }
  
  scanf("%d", &q);
  
  for (i=0; i<q; i++){
    scanf("%d", &t[i]);
    /*探索*/
    for (j=0; j<n; j++){
      if (t[i] == s[j]){
	count++;
	break;
      }
    }
  }

  printf("%d\n", count);

  return 0;
}

