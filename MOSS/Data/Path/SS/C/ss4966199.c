//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;


int main()
{   ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll INF=INT_MAX;
    ll V,E,r;
    cin>>V>>E>>r;
    
    vector<vector<P>>edge(V);
    vector<bool>isHaveEdge(V);//そのノードから伸びるエッジがあるかどうか
     
    rep(i,E)
    {ll s,t,d;
    cin>>s>>t>>d;

    edge[s].push_back(make_pair(d,t));
    isHaveEdge[s]=true;
    }
    vector<ll>d(V,INF);
   
    priority_queue<P>que;//firstはスタートからそのノードまでのコスト|secondはノードの番号
    d[r]=0;
    que.push(make_pair(d[r],r));
    while(!que.empty())
    {
        P Pair=que.top();que.pop();
        ll v=Pair.second;//v=今何番にいるか

        if(isHaveEdge[v])
        for(ll i=0;i<edge[v].size();++i)
        {   //cout<<edge[v].size()<<endl;
            //costはエッジの先のノードに行くためのコスト,nvは辺の先のノードの番号 (new v)
            P p=edge[v][i];
            ll cost=p.first;
            ll nv=p.second;
            if(d[v]+cost<d[nv])
            {d[nv]=d[v]+cost; que.push(make_pair(-d[nv],nv));};
        }

    }
    
    for(ll i=0;i<V;++i)
    {
     if(d[i]==INF)cout<<"INF\n";
     else cout<<d[i]<<"\n";
    }



}
