#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;

const int INF = 1000000010;

template<class T, class U>
class Dijkstra{
public:
    vector<U> d;
    vector<vector<pair<T,U>>> G;
    vector<T> prev;
    T s;
    priority_queue<pair<U,T>,vector<pair<U,T>>,greater<pair<U,T>>> q;
    Dijkstra (T n,T _s,U INF):d(n,INF),G(n),s(_s),prev(n,(T)(-1)){
        d[s]=0;
    }
    void solve(){
        q.push(make_pair((U)0,s));
        while(q.size()){
            pair<U,T> p=q.top();
            q.pop();
            T v=p.second;
            if(d[v]<p.first)continue;
            for(int i=0;i<G[v].size();i++){
                pair<T,U> e=G[v][i];
                if(d[e.first]>d[v]+e.second){
                    d[e.first]=d[v]+e.second;
                    prev[e.first]=v;
                    q.push(make_pair(d[e.first],e.first));
                }
            }
        }
    }
};

int main(){
    int V,E,r;
    cin >> V >> E >> r;

    Dijkstra<int,int> dijkstra(V, r, INF);

    for(int i = 0;i < E;i++){
        int s,t,d;
        cin >> s >> t >> d;
        dijkstra.G[s].push_back(make_pair(t,d));
    }

    dijkstra.solve();

    for(int i = 0;i < V;i++){
        if(dijkstra.d[i] != INF)cout << dijkstra.d[i] << endl;
        else cout << "INF" << endl;
    }
}

