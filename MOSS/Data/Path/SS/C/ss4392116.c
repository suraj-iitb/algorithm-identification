//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <time.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second
#define mp make_pair
 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1ll << 60;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int V, E, R;
ll Dist[int(1e5 + 5)];
vector <Pil> Graph[int(1e5 + 5)];

int main(){
  scanf("%d%d%d", &V, &E, &R);
  for (int i = 0; i < E; i++){
    int S, T; ll D; scanf("%d%d%lld", &S, &T, &D);
    Graph[S].push_back(mp(T, D));
  }
  
  fill(Dist, Dist + V, -1);
  priority_queue <Pli, vector<Pli>, greater<Pli> > que;
  que.push(mp(0, R));
  while (!que.empty()){
    Pli Q = que.top(); que.pop();
    if (Dist[Q.se] != -1) continue;

    Dist[Q.se] = Q.fi;
    for (int i = 0; i < Graph[Q.se].size(); i++){
      Pil next = Graph[Q.se][i];
      if (Dist[next.fi] != -1) continue;
      que.push(mp(Dist[Q.se] + next.se, next.fi));
    }
  }
  
  for (int i = 0; i < V; i++){
    if (Dist[i] == -1) printf("INF\n");
    else printf("%lld\n", Dist[i]);
  }
  
  return 0;
}

