#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define reps(i,f,n) for(int i=(f); i<=(n); ++i)
using namespace std;

void counting_sort(int a[], const int len, const int maxv)
{
   int cnt[maxv + 1] = {-1};
   int ret[len];

   rep(i, len) ++cnt[ a[i] ];
   reps(i, 1, maxv) cnt[i] += cnt[i-1];

   for(int i=len-1; i>=0; --i){
      int& p = cnt[ a[i] ];
      ret[p] = a[i];
      --p;
   }

   memcpy( a, ret, sizeof(ret) );
   return ;
}

main()
{
   int N, a[2000001], maxv = 0;
   scanf("%d", &N);

   rep(i, N)
      scanf("%d", a+i),
      maxv = max( maxv, a[i] );

   counting_sort(a, N, maxv);

   rep(i, N) printf("%d%c", a[i], i+1 < N ? ' ' : '\n' );
}


