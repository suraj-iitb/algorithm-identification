#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG
#define fi first
#define se second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

ll v,e,r;
vector<vector<pair<int,ll>>> vec(100000+1);

vll dijkstra(int s){
    vll d(v+1,1e10);
    d[s]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
    q.push({0,s});
    while(q.size()!=0){
        auto q1=q.top();
        q.pop();
        ll c=q1.fi;
        int num=q1.se;
        for (auto p:vec[num]){
            int n1=p.fi;
            ll c1=p.se;
            if (c1+c<d[n1]){
                q.push({c1+c,n1});
                d[n1]=c1+c;
            }
        }

    } 
    return d;

}

int main() {
    cin>>v>>e>>r;
    rep(i,e){
        int s,t;
        ll d;
        cin>>s>>t>>d;
        vec[s].push_back({t,d});
        //vec[t].push_back({s,d});
    }
    auto d=dijkstra(r);
    rep(i,v){
        if (d[i]!=1e10)cout<<d[i]<<endl;
        else cout<<"INF"<<endl;
    }
    


    return 0;
}
