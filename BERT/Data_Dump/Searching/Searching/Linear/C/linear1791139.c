#include <stdio.h>
int main(){
  int n, q, i, j, cnt = 0;
  scanf("%d", &n);
  int s[n];
  for(i = 0; i < n; i++)
    scanf("%d", &s[i]);
  scanf("%d", &q);
  int t[q];
  for(i = 0; i < q; i++){
    scanf("%d", &t[i]);
    for(j = 0; j < n; j++)
      if(t[i] == s[j]){
	cnt++;
	break;
      }
  }
  printf("%d\n", cnt);
  return 0;
}
