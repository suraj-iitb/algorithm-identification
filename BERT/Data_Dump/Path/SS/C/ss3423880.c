#include<cstdio>
#include<vector>
#include<queue>
#include<unordered_set>
long long const infty = 0x3fffffffffffff;
struct edge{
    long long weight;
    int to,rev;
};
//隣接リスト表現
class Graph{
protected:
    int numVertex,numEdge;
    std::vector<edge> *adj;
public:
    //---基本---

    //v頂点のグラフを作成する（頂点の番号は0-indexed）
    Graph(int v){
        numVertex=v;
        numEdge=0;
        adj=new std::vector<edge>[v];
    }
    ~Graph(){ delete[] adj; }
    int getNumVertex(){ return numVertex; }
    int getNumEdge(){ return numEdge; }
    void addEdge(int u,int v,long long w=1LL,bool isDirected=false){
        adj[u].push_back({w,v,-1});
        numEdge++;
        if(!isDirected){
            adj[v].push_back({w,u,-1});
            numEdge++;
        }
    }
    //ダイクストラ法（単一頂点を始点とする最短経路）O(E+VlogV)
    void dijkstra(long long l[],int s,int prev[]=NULL){
        for(int i=0;i<numVertex;i++)l[i]=infty;
        if(prev!=NULL)for(int i=0;i<numVertex;i++)prev[i]=-1;
        l[s]=0;
        auto cmp=[](const edge &a,const edge &b)->bool { return a.weight>b.weight; };
        std::priority_queue<edge,std::vector<edge>,decltype(cmp)> pq(cmp);
        pq.push({0,s,-1});
        while(!pq.empty()){
            int u=pq.top().to;
            pq.pop();
            for(auto i=adj[u].begin();i!=adj[u].end();i++){
                int v=(*i).to;
                long long w=(*i).weight;
                if(l[v]>l[u]+w){
                    l[v]=l[u]+w;
                    if(prev!=NULL)prev[v]=u;
                    pq.push({l[v],v,-1});
                }
            }
        }
    }
};
long long w[100000];
int main(){
    int v,e,r;
    scanf("%d%d%d",&v,&e,&r);
    Graph g(v);
    for(int i=0;i<e;i++){
        int s,t,d;
        scanf("%d%d%d",&s,&t,&d);
        g.addEdge(s,t,d,true);
    }
    g.dijkstra(w,r);
    for(int i=0;i<v;i++){
        if(w[i]==infty)printf("INF\n");
        else printf("%lld\n",w[i]);
    }
    return 0;
}
