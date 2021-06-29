#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n ; i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x) // decltypeで型取得、引数があればva_argsのところに入れる
#define Fill(x, v, y) fill(x, x + v, y);
using namespace std;
typedef long long ll; // long longをllでかけるようにした
const int INF = 1e9;
const long long INFTY = (1LL<<32);
const double PI = 3.1415926535;
const int MOD = 1000000007; // 計算してからmodで割る ans = (ans * a) % mod
#define int long long
template <typename T = long long > T in () { T x; cin >> x; return(x);}
// int a = in() のように使うlong long以外の型の時はstirng s = in<string>()のように型を指定する

// 全点対最短経路（全ての二点間の最短路を求める）
// ここから

static const int MAX_V = 100; // Vによって変える
int V; // 頂点数
int d[MAX_V][MAX_V];

void WarshallFloyed(void){
    REP(k, V){
        REP(i, V){
            if(d[i][k] == INFTY) continue;
            REP(j, V){
                if(d[k][j] == INFTY) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}


signed main(void){
    int E; cin >> V >> E; // E -> 辺の数
    
    REP(i, V) REP(j, V) d[i][j] = ((i == j) ? 0 : INFTY);

    REP(i, E){
        int from, to, dist; cin >> from >> to >> dist;
        d[from][to] = dist;
        // d[to][from] = dist; // 無向グラフの時
    }

    WarshallFloyed();

    bool negative = false;
    REP(i, V) if(d[i][i] < 0) negative = true;

    if(negative){
        cout << "NEGATIVE CYCLE" << endl;
    }else{
        REP(i, V){
            REP(j, V){
                if(j) cout << " ";
                if(d[i][j] == INFTY) cout << "INF";
                else cout << d[i][j];
            }
            cout << endl;
        }
    }
}
