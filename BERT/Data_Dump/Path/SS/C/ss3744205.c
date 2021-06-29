#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001;
const ll INF=1LL<<60;

vector<pair<int,ll>> S[MAX];
ll dis[MAX];
int N;

void dijkstra(int u){
    priority_queue<pair<int,ll>> PQ;
    for(int i=0;i<N;i++){
        dis[i]=INF;
    }
    dis[u]=0;
    PQ.push(make_pair(u,0));

    while(!PQ.empty()){
        int a=PQ.top().first;
        ll b=PQ.top().second;
        PQ.pop();
        if(dis[a]<-b) continue;
        for(int i=0;i<S[a].size();i++){
            int c=S[a][i].first;
            ll d=S[a][i].second;
            if(dis[c]>dis[a]+d){
                dis[c]=dis[a]+d;
                PQ.push(make_pair(c,-dis[c]));
            }
        }
    }
}

int main(){
    
    int E,r;cin>>N>>E>>r;
    for(int i=0;i<E;i++){
        int a,b;
        ll c;cin>>a>>b>>c;
        S[a].push_back(make_pair(b,c));
    }

    dijkstra(r);

    for(int i=0;i<N;i++){
        if(dis[i]==INF) cout<<"INF"<<endl;
        else cout<<dis[i]<<endl;
    }
}

