#include <stdio.h>
#include <vector>
#include <utility>
typedef long long ll;

int main(void) {
  ll inf = 10e15;
  ll i, j, k, v, r, e;
  scanf("%lld%lld%lld", &v, &e, &r);
  ll dis[v], now = r, smax = 1;
  char flag[v];
  std::vector< std::pair<ll, ll> > vec[v];
  std::vector< std::pair<ll, ll> >::iterator it;
  std::pair<ll, ll> seg[4 * v];
  while(smax < v) smax *= 2;
  for(i = 0; i <= smax * 2; ++i) {
    seg[i].first = inf; seg[i].second = i - smax;
  }
  for(i = 0; i < smax; ++i) seg[i].second = 1000000;
  seg[1].second = r;
  for(i = 0; i < v; ++i) dis[i] = inf, flag[i] = 1;
  flag[r] = 0;
  dis[r] = 0;
  for(i = 0; i < e; ++i) {
    ll ta, tb, tc;
    std::pair<ll, ll> p;
    scanf("%lld%lld%lld", &ta, &tb, &tc);
    p = std::make_pair(tb, tc);
    vec[ta].push_back(p);
  }
  for(k = 1; k < v; ++k) {
    for(it = vec[now].begin(); it != vec[now].end(); ++it) {
      if(flag[(*it).first] && dis[(*it).first] > dis[now] + (*it).second) {
        dis[(*it).first] = dis[now] + (*it).second;
        seg[smax + (*it).first].first = dis[now] + (*it).second;
        ll tmp = smax + (*it).first;
        tmp /= 2;
        while(tmp) {
          seg[tmp] = seg[tmp * 2] > seg[tmp * 2 + 1] ? seg[tmp * 2 + 1] : seg[tmp * 2];
          tmp /= 2;
        }
      }
    }
    if(now == seg[1].second || seg[1].first == inf) break;
    now = seg[1].second;
    flag[now] = 0;
    ll tmp = now + smax;
    seg[tmp].first = inf;
    tmp /= 2;
    while(tmp) {
      seg[tmp] = seg[tmp * 2] > seg[tmp * 2 + 1] ? seg[tmp * 2 + 1] : seg[tmp * 2];
      tmp /= 2;
    }
    /*for(i = 0; i < v; ++i) printf("%lld ", dis[i]);
    printf("&%lld\n", now);*/
  }
  for(i = 0; i < v; ++i) {
    if(dis[i] != inf) printf("%lld\n", dis[i]);
    else printf("INF\n");
  }
  return 0;
}
