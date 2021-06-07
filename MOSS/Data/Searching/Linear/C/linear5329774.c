#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <stdlib.h>
#include <stdbool.h>
#define ll long long
#define PI acos(-1)
#define ichi 1000000007


  
int main () {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int q;
  scanf("%d", &q);
  int b[q];
  for (int i = 0; i < q; i++) scanf("%d", &b[i]);

  int ans = 0;
  for (int i = 0; i < q; i++) {
    for (int j = 0; j < n; j++) {
      if (b[i] == a[j]) {
        ans++;
        break;
      }
    }
  }

  printf("%d\n", ans);
   
  return 0;
}
