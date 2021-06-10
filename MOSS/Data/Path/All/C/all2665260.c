#include <bits/stdc++.h>
using Int = int64_t;
using UInt = uint64_t;
using C = std::complex<double>;
#define rep(i, n) for(Int i = 0; i < (Int)(n); ++i)
#define guard(x) if( not (x) ) continue;

int main() {
   Int v, e;
   std::cin >> v >> e;
   std::vector<Int> ss(e), ts(e), ds(e);
   rep(i, e) std::cin >> ss[i] >> ts[i] >> ds[i];
   std::vector<std::vector<Int>> xss(v, std::vector<Int>(v));
   std::vector<std::vector<bool>> yss(v, std::vector<bool>(v));
   rep(i, v) yss[i][i] = true;
   rep(i, e) {
      Int s = ss[i], t = ts[i], d = ds[i];
      xss[s][t] = d;
      yss[s][t] = true;
   }
   for(Int k = 0; k < v; ++k) {
      for(Int i = 0; i < v; ++i) {
         for(Int j = 0; j < v; ++j) {
            guard( yss[i][k] and yss[k][j] );
            Int t = xss[i][k] + xss[k][j];
            if( not yss[i][j] or xss[i][j] > t ) {
               xss[i][j] = t;
               yss[i][j] = true;
            }
         }
      }
   }
   for(Int i = 0; i < v; ++i) {
      if( xss[i][i] < 0 ) {
         puts("NEGATIVE CYCLE");
         return 0;
      }
   }
   for(Int i = 0; i < v; ++i) {
      for(Int k = 0; k < v; ++k) {
         printf("%s", yss[i][k]?std::to_string(xss[i][k]).c_str():"INF");
         putchar(k==v-1?'\n':' ');
      }
   }
}
