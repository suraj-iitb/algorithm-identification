#include <stdio.h>

int main(){
  int n, s[10000], q, t;
  int i, j, c = 0;

  scanf("%d", &n);
  for(i=0; i<n; i++)
    scanf("%d", &s[i]);
  scanf("%d", &q);
  for(i=0; i<q; i++){
    scanf("%d", &t);

    for(j=0; j<n; j++)
      if(s[j] == t){
        c++;
        break;
      }
  }

  printf("%d\n", c);

  return 0;
}

