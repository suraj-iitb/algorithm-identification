#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll INF = 1010000000000000017LL;
const ll MOD = 1000000007LL;

#define REP(i, n) for(ll i = 0 ; i < n; i++)

//#define DEBUG(fmt, ...)
#define DEBUG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)

int main(){
    std::cout<<std::fixed<<std::setprecision(10);

    ll V, E, r;

    cin >> V >> E >> r;

    vector<vector<P>> graph(V);
    REP(i, E){
        ll s, t, d;
        cin >> s >> t >> d;
        graph[s].push_back(P(t,d));
    }

    vector<bool> visited(V, false);
    vector<ll>   shortest(V, INF);
    shortest[r] = 0;

    priority_queue<P, vector<P>, greater<P>> queue;
    queue.push(P(shortest[r], r) );

    while(!queue.empty()){
        P cur = queue.top();
        ll cur_dist = cur.first;
        ll cur_node = cur.second;
        queue.pop();
        if( visited[cur_node] ){
            continue;
        }
        visited[cur_node] = true;
        for(auto const& edge : graph[cur_node] ){
            ll next_node = edge.first;
            ll distance = edge.second;
            if( shortest[next_node] > cur_dist+distance ){
                shortest[next_node] = cur_dist+distance;
                queue.push(P(shortest[next_node],next_node));
            }
        }
    }

    REP(i, V){
        if( shortest[i] == INF ) cout << "INF" << endl;
        else cout << shortest[i] << endl;
    }
}

