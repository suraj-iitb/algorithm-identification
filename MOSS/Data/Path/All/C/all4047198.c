// AOJ GRL_1_C All Pairs Shortest Path
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define rep(i, n) for(int i = 0; i < (n); i++)
template<class T> istream& operator >> (istream& s, vector<T>& v)
{ for (T& x: v) { s >> x; } return s;}
template<class T> void cout_h(const vector<T>& c, int n=INT_MAX)
{ rep(i, min(n, (int)c.size())) cout << c[i] << (i==c.size()-1?"\n":" "); }
template<class T> inline bool chmin(T& a, T b) {return a>b?a=b,true:false;}

#define INF (int)(10e9)

int main() {
    int NV, NE; cin >>NV>>NE;
    vvi d(NV, vi(NV, INF));
    rep(i, NV) d[i][i] = 0;
    rep(i, NE) {
        int _s, _t, _d; cin >> _s >> _t >> _d;
        d[_s][_t] = _d;
    }

    rep(k, NV) rep(i, NV) rep(j, NV) {
        if (d[i][k] != INF && d[k][j] != INF)
            chmin(d[i][j], d[i][k] + d[k][j]);
    } 

    rep(i, NV) {
        if (d[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    rep(i, NV) {
        rep(j, NV) {
            if (d[i][j] == INF) {
                cout << "INF";
            } else {
                cout << d[i][j];
            }
            cout << (j==NV-1?"\n":" ");
        }
    }
}

