#include <bits/stdc++.h>
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
#define mp make_pair
#define pb push_back
#define ll __int64
#define __int64 long long
#define P pair<int,int>
#define PP pair<P,int>

int v,e;
ll g[111][111];
const ll INF=1e15;

ll dist[111][111];

int main(){
    cin>>v>>e;
    rep(i,v)rep(j,v)if(i!=j)dist[i][j]=INF;

    rep(i,e){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        dist[a][b]=c;
        //dist[b][a]=c;
    }
    rep(i,v){
        rep(j,v){
            rep(k,v)
                if(dist[j][i]!=INF&&dist[i][k]!=INF)dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
        }
    }
    rep(i,v){
        if(dist[i][i]<0){
            cout<<"NEGATIVE CYCLE"<<endl;
            return 0;
        }
    }
    rep(i,v){
        rep(j,v){
            if(dist[i][j]==INF)
                cout<<"INF";
            else cout<<dist[i][j];
            if(j==v-1)cout<<endl;
            else cout<<" ";
        }
    }

    return 0;
}

