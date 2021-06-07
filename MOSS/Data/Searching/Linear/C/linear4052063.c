#include <stdio.h>
#define N 10000
#define Q 500

int main(){
  int n, q, i, j, flag, flag2, flag3, count = 0;
  int s[N], t[Q];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);

  for(i = 0; i < q; i++){
    scanf("%d", &t[i]);
  }

  for(j = 0; j < q; j++){
    i = 0;
    flag = 0;
    flag2 = 0;
    flag3 = 0;
    s[n] = t[j];
    while(s[i] != s[n]){
      i++;
      if(i == n){
	flag2 = 1;
	break;
      }
      if(s[i] == s[n]){
	flag = 1;
      }
    }
    if(flag2 != 1 && flag == 0){
      flag3 = 1;
    }
    count += flag;
    count += flag3;
  }

  printf("%d\n", count);

  return 0;
}
  

