#include<stdio.h>
int main(){

int n, q, i, j, ans = 0;
int s[10000], t[500];

  scanf("%d", &n);
for(i = 0; i < n; i++){
  scanf("%d", &s[i]);
}
  scanf("%d", &q);
for(i = 0; i < q; i++){
  scanf("%d", &t[i]);
}
for(i = 0; i < q; i++){
  for(j = 0; j < n; j++){
    if(t[i] == s[j]){
      ans++;
      break;
    }
  }
}

  printf("%d\n", ans);

  return 0;
}
