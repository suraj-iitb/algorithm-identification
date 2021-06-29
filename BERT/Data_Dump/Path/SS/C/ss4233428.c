#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

ll dis[100000];
vector<vector<pair<ll,ll> > > g(100000);
void dijkstra(ll start){
	for(int i=0;i<100000;i++)dis[i]=1e18;
	dis[start]=0;
    multiset<pair<ll,ll> > ms;
    ms.insert(make_pair(0,start));
    pair<ll,ll> p,niko;
    ll maki;
    while(!ms.empty()){
        p=*(ms.begin());
        ms.erase(ms.begin());
        if(dis[p.second]<p.first)continue;
        maki=g[p.second].size();
        for(int i=0;i<maki;i++){
            niko=g[p.second][i];
            if(dis[niko.first]>dis[p.second]+niko.second){
                dis[niko.first]=dis[p.second]+niko.second;
                ms.insert(make_pair(dis[niko.first],niko.first));
            }
        }
    }
    return;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,m,s,a,b,c;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
    	cin>>a>>b>>c;
    	g[a].pb(make_pair(b,c));
    }
    dijkstra(s);
    for(int i=0;i<n;i++){
    	if(dis[i]==1e18)cout << "INF"<<endl;
    	else cout <<dis[i]<<endl;
    }
    return 0;
}

