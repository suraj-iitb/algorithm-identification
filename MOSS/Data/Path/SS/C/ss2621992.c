#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
typedef pair<uint32_t,uint32_t> P;

int bitSearchReverse(uint32_t x){
    if(x==0)return -1;
    return 31-__builtin_clz(x);
}
struct RadixHeap{
    vector<P>v[33];
    uint32_t last,sz;
    RadixHeap(){
        last=sz=0;
    }
    void push(P p){
        assert(last<=p.first);
        sz++;
        v[bitSearchReverse(p.first^last)+1].push_back({p.first,p.second});
    }
    P top(){
        return pop(false);
    }
    P pop(bool f=true){
        assert(sz);
        if(!v[0].size()){
            int i=1;
            while(!v[i].size())++i;
            last=min_element(v[i].begin(),v[i].end())->first;
            for(P p:v[i])v[bitSearchReverse(p.first^last)+1].push_back(p);
            v[i].clear();
        }
        P r=v[0].back();
        if(f){
            sz--;
            v[0].pop_back();
        }
        return r;
    }
    int size(){
        return sz;
    }
    bool empty(){
        return sz==0;
    }
    void clear(){
        last=sz=0;
        for(auto a:v)a.clear();
    }
};
struct Graph{
    Graph(int n):E(n),d(n){}
    vector<vector<P>>E;
    vector<uint32_t>d;
    void add_edge(int a,int b,uint32_t c){
        E[a].emplace_back(b,c);
    }
    void dijkstra(int s){
        RadixHeap H;
        fill(d.begin(),d.end(),INF);
        H.push({d[s]=0,s});
        while(H.size()){
            P e=H.top();H.pop();
            if(e.first>d[e.second])continue;
            for(P& a:E[e.second]){
                uint32_t x=a.first,y=a.second+e.first;
                if(y<d[x])d[x]=y,H.push({y,x});
            }
        }
    }
};

main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    uint32_t V,E,r;
    cin>>V>>E>>r;
    Graph G(V);
    for(int i=0;i<E;++i){
        uint32_t s,t,d;
        cin>>s>>t>>d;
        G.add_edge(s,t,d);
    }
    G.dijkstra(r);
    for(int i=0;i<V;++i)
        if(G.d[i]==INF) cout<<"INF"<<endl;
        else cout<<G.d[i]<<endl;
}
