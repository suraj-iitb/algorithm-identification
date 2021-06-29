#include <stdio.h>

#define N 10000
#define Q 500

int main () {
  int i, j, n, q, c=0;
  int s[N], t[Q];

  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);
  for(i=0;i<q;i++){
    scanf("%d", &t[i]);
    for(j=0;j<n;j++){
      if(t[i]==s[j]){
        c++;
        break;
      }
    }
  }

  printf("%d\n", c);

  return 0;
}
