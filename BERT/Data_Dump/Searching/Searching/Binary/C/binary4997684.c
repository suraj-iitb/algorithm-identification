#include <stdio.h>

int main(){
  long long n, q, s[100001], t, i, min, max, mid, c = 0;

  scanf("%lld", &n);
  for(i = 0; i < n; ++i) scanf("%lld", s + i);

  scanf("%lld", &q);
  while(q--){
    scanf("%lld", &t);
    min = 0;
    max = n - 1;
    while(min <= max){
      mid = (min + max) / 2;
      if(s[mid] == t){ c++; break;}
      else if(s[mid] > t) max = mid - 1;
      else if(s[min] < t) min = mid + 1;
    }
  }
  printf("%lld\n", c);
  return 0;
}
