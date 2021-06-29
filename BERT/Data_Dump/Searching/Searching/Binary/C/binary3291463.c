#include<stdio.h>

int main(){
  int i, j, n, s[100000], q, t[50000], cnt = 0;
  int l, r, m;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);
  for(j = 0; j < q; j++){
    scanf("%d", &t[j]);

    l = 0;
    r = n;
    while(l < r){
      m = (l + r)/2;
      if(s[m] == t[j]){
	cnt++;
	break;
      }
      else if(t[j] < s[m]){
	r = m;
      }
      else {
	l = m + 1;
      }
    }
  }

  printf("%d\n", cnt);

  return 0;
}

