#include<stdio.h>
#define N 10000
#define Q 500

int main(){

  int a[N], b[Q], cnt = 0;
  int i, j, n, q;

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d", &a[i]);

  scanf("%d", &q);
  for(i = 0; i < q; i++) scanf("%d",& b[i]);

  for(j = 0; j < q; j++){
    for(i = 0; i < n; i++){
      if(a[i] == b[j]){
    cnt++;
    break;
      }
    }
  }

  printf("%d\n", cnt);

  return 0;
}
