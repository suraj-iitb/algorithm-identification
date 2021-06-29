#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

int V, E;
int dist[100000];
vector<int> a[100000];
map<pair<int, int>, int> mp;
const int INF = 1000000000;

int main() {
  int s;
  cin >> V >> E >> s;
  rep(i, E) {
    int x, y, temp;
    cin >> x >> y >> temp;
    a[x].push_back(y);
    mp[make_pair(x, y)] = temp;
  }
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, s));

  rep(i, V) {
    dist[i] = INF;
  }
  dist[s] = 0;
  
  while(que.size()) {
    int p = que.top().second;
    que.pop();
    for(int i = 0; i < a[p].size(); i++) {
      if(dist[a[p][i]] > dist[p] + mp[make_pair(p, a[p][i])]) {
        dist[a[p][i]] = dist[p] + mp[make_pair(p, a[p][i])];
        que.push(P(dist[a[p][i]], a[p][i]));
      }
    }
  }

  rep(i, V) {
    if(dist[i] != INF) cout << dist[i] << endl;
    else cout << "INF" << endl;
  }
  return 0;
}
