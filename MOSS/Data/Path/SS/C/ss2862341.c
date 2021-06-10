#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(i=0;i<(n);i++)
#define loop(i,a,n) for(i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

struct edge { int to, cost;};

//O(ElogV)

class Dijkstra{
private:
    vector< vector<edge> > g;

public:
    Dijkstra(){};
    Dijkstra(int size){
        g.resize(size);
    }

    vi dist;

    void add(int a, int b, int c){//無向辺
        edge e1 = {b, c}, e2 = {a, c};
        g[a].push_back(e1);
        //g[b].push_back(e2);//有向辺の場合はここをコメントアウトする
    }

    void calc(int s){
        priority_queue< pii, vector<pii>, greater<pii> > q;
        int n = g.size();
        dist = vi (n, INF);
        dist[s] = 0;
        q.push(pii(0, s));

        while(!q.empty()){
            pii p = q.top();
            q.pop();
            int v = p.second;
            if(dist[v] < p.first)continue; //更新されていたら何もしない
            for(int i = 0; i < g[v].size(); i++){
                edge e = g[v][i];
                if(dist[e.to] > dist[v] + e.cost){
                    dist[e.to] = dist[v] + e.cost;
                    q.push(pii(dist[e.to], e.to));
                }
            }
        }
    }

};


int main(void) {
    int i,j;
    int n;
    int v,e,r;
    cin >> v >> e >> r;

    Dijkstra g = Dijkstra(v);

    rep(i,e){
        int a,b,c;
        cin >> a >> b >> c;
        g.add(a,b,c);
    }

    g.calc(r);

    rep(i,v){
        if(g.dist[i] == INF)
            cout << "INF" << endl;
        else
            cout << g.dist[i] << endl;
    }

}

