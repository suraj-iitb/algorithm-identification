#include <stdio.h>
int main(){
  int n, q, i, l, r, m, cnt = 0;
  scanf("%d", &n);
  int s[n];
  for(i = 0; i < n; i++)
    scanf("%d", &s[i]);
  scanf("%d", &q);
  int t[q];
  for(i = 0; i < q; i++){
    scanf("%d", &t[i]);
    l = 0, r = n, m = (l + r) / 2;
    while(l != r){
      if(t[i] == s[m]){
	cnt++;
	break;
      }
      if(t[i] < s[m])
	r = m, m = (l + r) / 2;
      else
	l = m + 1, m = (l + r) / 2;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
