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

lint gcd(lint a, lint b) {
    lint r;
    while (b != 0) {
        r = a % b;
        a = b; 
        b = r;
    }
    return a;
}

lint lcm(lint a, lint b) {
    return (a / gcd(a, b)) * b;
}

lint power(lint x, lint n, lint mod = MOD) {
    lint ret = 1;
    while(n > 0) {
        if(n & 1){
            (ret *= x) %= mod;
        }
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

vector<lint> make_power(int n, lint base){
    lint num = 1;
    vector<lint> ret;
    for (int i=0; i<=n; ++i){
        ret.push_back(num);
        num *= base;
    }
    return ret;
}

// Graph Templates
using Weight = lint;
// using Flow = int;
struct Edge {
    int src, dst;
    Weight weight;
    // Flow cap;
    Edge() : src(0), dst(0), weight(0) {}
    Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;
//const Weight INF = numeric_limits<Weight>::max() / 8;

// add edge a <--(weight = w)--> b
void add_edge(Graph &g, int a, int b, Weight w) {
    g[a].push_back(Edge(a, b, w));
    g[b].push_back(Edge(b, a, w));
}

// add edge a --(weight = w)--> b
void add_arc(Graph &g, int a, int b, Weight w) { g[a].push_back(Edge(a, b, w)); }

struct uf_tree {
    std::vector<int> parent;
    int __size;
    uf_tree(int size_) : parent(size_, -1), __size(size_) {}
    void unite(int x, int y) {
        if ((x = find(x)) != (y = find(y))) {
            if (parent[y] < parent[x]) std::swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
            __size--;
        }
    }
    bool is_same(int x, int y) { return find(x) == find(y); }
    int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
    int size(int x) { return -parent[find(x)]; }
    int size() { return __size; }
};

// Kruskal
pair<Weight, Edges> kruskal(Graph const &g) {
    uf_tree uf(g.size());
    Edges es;
    for (auto &adj : g)
        for (auto &e : adj) es.emplace_back(e);
    sort(es.begin(), es.end(), [](const Edge &e, const Edge &f) { return e.weight < f.weight; });
    Weight total = 0;
    Edges T;
    for (auto &e : es)
        if (!uf.is_same(e.src, e.dst)) {
            T.push_back(e);
            total += e.weight;
            uf.unite(e.src, e.dst);
        }
    return make_pair(total, T);
}

void output(vector<int> &a, int n){
    bool isFirst = true;
    REP(i, n){
        if(isFirst){
            isFirst = false;
            cout << a[i];
        }
        else {
            cout << " " << a[i];
        }
    }
    cout << endl;
    return;
}

void insertionSort(vector<int> &a, int n){
    output(a, n);
    int v, j;
    for (int i=1; i<n; ++i){
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        output(a, n);
    }
    return;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n){
        cin >> a[i];
    }
    insertionSort(a, n);
    return 0;
}
