#include<stdio.h>

#define N 10000
#define Q 10000

int main(){
  int i, j, n, m, a[N], b[Q], f = 0, g = 0;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  scanf("%d", &m);

  for(i = 0; i < m; i++){
    scanf("%d", &b[i]);
  }

  for(j = 0; j < m; j++){
    for(i = 0; i < n; i++){
      if(a[i] == b[j]){
	f++;
	break;
      }
    }
    g += f;
    f = 0;
  }


  printf("%d\n", g);

  return 0;
}


