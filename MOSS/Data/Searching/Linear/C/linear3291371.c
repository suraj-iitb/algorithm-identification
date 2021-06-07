#include<stdio.h>

int main(){
  int i, j, n, s[10000], q, t[500], cnt = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);
  for(j = 0; j < q; j++){
    scanf("%d", &t[j]);
    for(i = 0; i < n; i++){
      if(s[i] == t[j]){
	cnt++;
	t[j] = -1;
      }
    }
  }
  printf("%d\n", cnt);

  return 0;
}

  

