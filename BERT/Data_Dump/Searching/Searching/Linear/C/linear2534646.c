#include<stdio.h>

int main(void){
  int n, i, j, q, a, count = 0, S[10000];
  scanf("%d", &n);
  for(i=0;i<n;i++) scanf("%d ", &S[i]);
  scanf("%d", &q);
  for(i=0;i<q;i++){
    scanf("%d", &a);
    for(j=0;j<n;j++){
      if(S[j] == a){
        count++;
        break;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}
