#include <stdio.h>

long long  a[2000000], b[2000000], c[10001];

void csort(long long *a, long long *b, long long k, long long n){
  long long i, j;
  for(j = 0; j < n; ++j) c[a[j]]++;
  for(i = 1; i <= k; ++i) c[i] += c[i - 1];
  for(j = n - 1; j >= 0; --j){
    b[c[a[j]] - 1] = a[j];
    c[a[j]]--;
  }
}

int main(){
  long long n, i, max  = 0;

  scanf("%lld", &n);
  for(i = 0; i < n; ++i){
    scanf("%lld", a + i);
    if(max < a[i]) max = a[i];
  }
  csort(a, b, max, n);

  for(i = 0; i < n; ++i) printf(i != 0 ? " %lld" : "%lld" , b[i]);
  puts("");
  return 0;
}
