#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define reps(i,a,b) for(int i=a;i<b;++i)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<typename T> inline bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<typename T> inline bool chmin(T &a,T b){if(b<a){a=b;return 1;}return 0;}
template<typename T> vector<T> make_vec(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>
auto make_vec(size_t a,Ts... ts){return vector<decltype(make_vec<T>(ts...))>(a,make_vec<T>(ts...));}
template<typename T,typename U,typename... V>
typename enable_if<is_same<T,U>::value>::type fill_v(U &u,const V... v){u=U(v...);}
template<typename T,typename U,typename... V>
typename enable_if<!is_same<T,U>::value>::type fill_v(U &u,const V... v){for(auto &e:u)fill_v<T>(e,v...);}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;
    auto dist = make_vec<ll>(v, v);
    const ll inf = 1LL<<60;
    fill_v<ll>(dist, inf);
    rep(i, v) dist[i][i] = 0;
    rep(i, e) {
        int s, t, d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }
    rep(k, v) rep(i, v) rep(j, v) chmin(dist[i][j], dist[i][k] + dist[k][j]);
    rep(i, v) if (dist[i][i] < 0) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    rep(i, v) rep(j, v) {
        if (dist[i][j] < inf/2) cout << dist[i][j];
        else cout << "INF";
        cout << (j == v-1 ? '\n' : ' ');
    }
}

