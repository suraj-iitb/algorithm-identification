#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; (i) < (n); (i)++)
using namespace std;

long modpow(long a, long n, long mod) {
    long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
long modinv(long a, long mod) {
    return modpow(a, mod - 2, mod);
}

int GCD(int a, int b){
    if(b == 0) return a; 
    if(a < b) return GCD(b, a);
    else return GCD(b, a%b);
}

struct Edge{
    int to;
    long cost;
    Edge(int t, long c){
        to = t;
        cost = c;
    }
};
typedef pair<long, int> P;//距離、点

struct Dijkstra{
    int V;
    vector<vector<Edge>> G;
    vector<long> d;
    long inf = 1000000000000000000; // 10^18

    Dijkstra(int vv){
        V = vv;
        G.resize(V);
        d.resize(V);
    }

    void add_data(int a, int b, long c){
        Edge e1(b, c);
        G[a].push_back(e1);
    }

    void calc_dis(int s){
        priority_queue<P, vector<P>, greater<P>> que; //Pのfirstが小さい奴から取り出せる
        REP(i, V) d[i] = inf;
        d[s] = 0l;
        que.push(P(0, s));

        while(!que.empty()){
            P p = que.top(); que.pop();
            int v = p.second;
            if(d[v] < p.first) continue;
            for(int i=0;i<G[v].size();i++){
                Edge e = G[v][i];
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                }
            }
        }
    }


};

int main()
{   
    int V, E, r; cin >> V >> E >> r;
    Dijkstra ds(V);
    REP(i, E){
        int s, t; cin >> s >> t;
        long d; cin >> d;
        ds.add_data(s, t, d);
    }
    ds.calc_dis(r);
    REP(i, V){
        if(ds.d[i] == ds.inf) cout << "INF" << endl;
        else cout << ds.d[i] << endl;
    }
    
    return 0;
}


