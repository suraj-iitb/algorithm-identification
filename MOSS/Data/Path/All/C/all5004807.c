#include <bits/stdc++.h>
#define rep(i, N) for(int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VEC;
void invi(vector<int> *v, int n) { for(int i = 0; i < n; i++) scanf("%d", v[i]); }
void invl(vector<long long> *v, int n) { for(int i = 0; i < n; i++) scanf("%lld", v[i]); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = ((1 << 30) - (1 << 26))*2;      // > 10^9, 2*INF:ok
const ll LLINF = (1LL << 60);   // > 10^18 ll  2*LLINF:ok

int w[105][105];    //隣接行列


int main() {
    int V, E;
    cin >> V >> E;
    rep(i, V) rep(j, V) w[i][j] = INF;
    rep(i, V) w[i][i] = 0;              //自己ループを0で初期化

    int s, t, d;
    rep(i, E) {
        scanf("%d%d%d", &s, &t ,&d);
        w[s][t] = d;
    }

    //ワ―シャルフロイト
    rep(k, V) rep(i, V) rep(j, V) {
        if (w[i][k] != INF && w[k][j] != INF) chmin(w[i][j], w[i][k] + w[k][j]);
    }
    //負ループ検出
    bool neg_ch = false;
    rep(i, V) if (w[i][i] < 0) neg_ch = true;

    if (neg_ch) {
        cout << "NEGATIVE CYCLE";
        printf("\n");
    } else {
        rep(i, V) {
            rep(j, V) {
                if (j != 0) printf(" ");
                if (w[i][j] == INF) {
                    printf("INF");
                } else {
                    printf("%d", w[i][j]);
                }
            }
            printf("\n");
        }
    }
}

