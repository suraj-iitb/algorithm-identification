/*
　　　  ∧＿∧　やあ
　　 （´・ω・｀)　　　　　/　　　　　ようこそ、バーボンハウスへ。
　　 ／∇y:::::＼　　　 [￣]　　　　　このテキーラはサービスだから、まず飲んで落ち着いて欲しい。
　　 |:⊃:|:::::|　　　|──|
￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|　うん、「また」なんだ。済まない。
￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|￣　  仏の顔もって言うしね、謝って許してもらおうとも思っていない。
￣￣￣￣￣￣￣￣￣￣￣￣￣￣／|
　　　　∇　∇　∇　∇　　　／.／|　　　でも、この提出を見たとき、君は、きっと言葉では言い表せない
　　　　┴　┴　┴　┴　／ ／　  |　　　「ときめき」みたいなものを感じてくれたと思う。
￣￣￣￣￣￣￣￣￣￣|／　　  |　　　殺伐としたコンテストの中で、そういう気持ちを忘れないで欲しい
￣￣￣￣￣￣￣￣￣￣　　　　 |　　　そう思って、この提出を投げたんだ。
　　　(⊆⊇)　(⊆⊇)　(⊆⊇)　　|
　    ||　　 ||　　||　　|　　　 じゃあ、判定を聞こうか。
　　.／|＼　／|＼ ／|＼
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define fst first
#define snd second
#define mp make_pair
#define ALL(obj) (obj).begin(),(obj).end()
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n) 
#define SIZE(x) ((int)(x).size())
#define debug(x) cerr << #x << " -> " << x << " (line:" << __LINE__ << ")" << '\n';
#define debugpair(x, y) cerr << "(" << #x << ", " << #y << ") -> (" << x << ", " << y << ") (line:" << __LINE__ << ")" << '\n';
typedef long long lint;
typedef pair<int, int> pint;
typedef pair<lint, lint> plint;
typedef vector<lint> vec;
typedef vector<vector<lint>> matrix;
typedef priority_queue<lint> p_que;
typedef priority_queue<lint, vector<lint>, greater<lint>> p_que_rev;
const lint INF = INT_MAX;
const lint LINF = LLONG_MAX;
const lint MOD = 1000000000 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const int di[]{0, -1, 0, 1, -1, -1, 1, 1};
const int dj[]{1, 0, -1, 0, 1, -1, -1, 1};

typedef int Weight;
struct Edge {  //src:辺の始点,dst:辺の終点,weight:辺の重さ
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : //辺は重さが重いものを"小さい"と定義する
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

//引数 Graph:隣接リスト,dist:各頂点から各頂点までの距離が入る,inter:最短路木の親頂点が入る
//戻値 負閉路が存在しない場合:true,そうでないとき:false
bool shortestPath(const Graph &g,vector<vector<Weight> > &dist,vector<vector<int> > &inter) {
  int n = g.size();
  dist.assign(n,vector<Weight>(n,INF));
  for(int i=0;i<n;i++){
    dist[i][i]=0;
  }
  for(int i=0;i<n;i++){
    for(auto f=g[i].begin();f!=g[i].end();f++){
      dist[i][f->dst]=f->weight;
    }
  }
  inter.assign(n, vector<int>(n,-1));
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(dist[i][k]<INF && dist[k][j]<INF && dist[i][j]>dist[i][k]+dist[k][j]){
          dist[i][j] = dist[i][k] + dist[k][j];
          inter[i][j] = k;
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    if(dist[i][i]<0){
      return false;
    }
  }
  return true;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int v, e;
    lint s, t, w;
    cin >> v >> e;
    Graph g;
    g.resize(v);
    for (int i=0; i<e; ++i){
        cin >> s >> t >> w;
        g[s].push_back(Edge(s, t, w));
    }
    vector<vector<Weight> > dist;
    vector<vector<int>> inter;
    bool hasNegCycle = shortestPath(g, dist, inter);
    if(!hasNegCycle){
        cout << "NEGATIVE CYCLE" << endl;
    }
    else {
        bool isFst = true;
        for (int i=0; i<v; ++i){
            isFst = true;
            for (int j=0; j<v; ++j){
                if(isFst){
                    isFst = false;
                    if(dist[i][j] == INF){
                        cout << "INF";
                    }
                    else {
                        cout << dist[i][j];
                    }
                }
                else {
                    if(dist[i][j] == INF){
                        cout << " INF";
                    }
                    else {
                        cout << " " << dist[i][j];
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}
