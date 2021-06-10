#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vbb;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair

#define loop(i,a,b) for(int i=(a);i<ull(b);++i)
#define rep(i,n) loop(i,0,n)

const double eps = 1e-10;
const double pi  = acos(-1.0);
const int MAX = 1000000;
const long long INF = 5e9+1;
int V;
typedef pair<int, int> pii; /*first: 距離 second: 接続先*/
vector<pii> G[MAX];
long long dist[MAX];
int prev[MAX];
bool used[MAX];
void dijkstra(int s){
    fill(dist, dist+MAX, INF);
    fill(used, used+MAX, false);
    fill(prev, prev+MAX, -1);
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push(pii(0, s));
    while(!q.empty()){
            int d; int t;
            pii p = q.top(); q.pop();
            d = p.first; t = p.second;
            if(used[t]) continue;
            used[t] = true; dist[t] = d;
            for(int i=0; i < G[t].size(); i++){
                        pii e = G[t][i];
                        if(dist[e.second] <= d+e.first) continue;
                        q.push(pii(d+e.first, e.second));
                        prev[e.second] = t;
                    }
        }
}

int main(){
    int E, S;
    cin >> V >> E >> S;
    for(int i=0; i< E; i++){
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back(make_pair(d, t));
    }
    dijkstra(S);
    int ans = 0;
    vector<int> v;
    for(int i=0; i< V; i++){
        if(dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}
