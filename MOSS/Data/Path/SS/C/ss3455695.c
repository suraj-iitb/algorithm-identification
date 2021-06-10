#include<bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<int,ii>

using namespace std;

void file(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int n,e,r;
long long dist[1000006],inf=1000000009;
vector<ii>graph[500005];


void init(){
    cin>>n>>e>>r;
    for(int i=0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(ii(v,w));
        //graph[v].push_back(ii(u,w));
    }
}

void dijkstra(int source){
    queue<int>q;
    q.push(source);
    dist[source]=0;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        int len=graph[u].size();
        for(int i=0 ;i<len; i++){
            int v=graph[u][i].first,
                w=graph[u][i].second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                q.push(v);
            }
        }
    }
}

void Back(){
    for(int i=0; i<n+7; i++)dist[i]=inf;
}

int main(){
    //file();
    init();
    Back();
    dijkstra(r);
    for(int i=0; i<n; i++){
        if(dist[i]<inf)cout<<dist[i]<<endl;
        else cout<<"INF"<<endl;
    }

return 0;
}

