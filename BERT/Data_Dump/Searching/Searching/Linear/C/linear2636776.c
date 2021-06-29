#include <stdio.h>

int main(void) {
    int n, q, i, j, count = 0, flag = 0;
    scanf("%d", &n);
    int S[n];
    for(i = 0; i < n; i ++) scanf("%d", &S[i]);
    scanf("%d", &q);
    int T[q];
    for(i = 0; i < q; i ++) scanf("%d", &T[i]);

    for (i = 0; i < q; i ++) {
      flag = 0;
      for(j = 0; j < n; j ++) {
        if(S[j] == T[i] && flag == 0) {
          flag ++;
          count ++;
        }
        else if(S[j] == T[i] && flag != 0) continue;
      }
    }

    printf("%d\n", count);
    return 0;
}
