#include <stdio.h>
#define N 10000
#define Q 500

int main(){
  int n, q, i, j, count = 0, a[N], b[Q];

  scanf("%d", &n);
  for(i = 0;i < n;i++){
    scanf("%d", &a[i]);
  }
  scanf("%d", &q);
  for(i = 0;i < q;i++){
    scanf("%d", &b[i]);
  }
  for(i = 0;i < q;i++){
    for(j = 0;j < n;j++){
      if(b[i] == a[j]){
	count++;
	break;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}
