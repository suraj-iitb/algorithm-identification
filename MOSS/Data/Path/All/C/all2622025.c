#include<bits/stdc++.h>
#define INF 1e18
#define int long long
using namespace std;

struct Graph{
    Graph(int n):d(n,vector<int>(n,INF)),N(n){
        for(int i=0;i<n;++i)d[i][i]=0;
    }
    vector<vector<int>>d;
    int N;
    void add_edge(int a,int b,int c){
        d[a][b]=c;
    }
    void warshallFloyd(){
        for(int k=0;k<N;++k)
            for(int i=0;i<N;++i)
                for(int j=0;j<N;++j)
                    if(d[i][k]!=INF && d[k][j]!=INF) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
};

main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V,E;
    cin>>V>>E;
    Graph G(V);
    for(int i=0;i<E;++i){
        int s,t,d;
        cin>>s>>t>>d;
        G.add_edge(s,t,d);
    }
    G.warshallFloyd();
    for(int i=0;i<V;++i)
        if(G.d[i][i]<0){
            cout<<"NEGATIVE CYCLE"<<endl;
            return 0;
        }
    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j)
            if(G.d[i][j]==INF) cout<<(j?" ":"")<<"INF";
            else cout<<(j?" ":"")<<G.d[i][j];
        cout<<endl;
    }
}
