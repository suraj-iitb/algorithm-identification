#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;

ll fact[3000001];
ll invfact[3000001];

int main(){
    ll v,e,r;
    cin >> v >> e >> r;
    vector<pair<int,ll> > edge[v+1];
    for(int i = 0; i < e; i++){
        ll s,t,d;
        cin >> s >> t >> d;
        edge[s].push_back(make_pair(t,d));
    }

    vector<ll> ans(v+1, INF);
    priority_queue<pair<ll, ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
    q.push(make_pair(0,r));
    while(q.size() > 0){
        auto tmp = q.top();
        q.pop();
        ll w = tmp.first;
        ll p = tmp.second;
        if(ans[p] == INF) ans[p] = w;
        else continue;
        for(int i = 0; i < edge[p].size(); i++){
            q.push(make_pair(w+edge[p][i].second,edge[p][i].first));
        }
    }

    for(int i = 0; i < v; i++){
        if(ans[i] == INF){
            cout << "INF" << endl;
        } else {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
