#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;
typedef uint64_t ui64;
#include <bits/stdc++.h>

class graph{
private:
    struct vrtx{
        int to;
        int64_t cost;
    };
    struct adj{
        int start;
        int to;
        int64_t cost;
    };
    int nd;
    int edg;
public:
    std::vector<vrtx> *node;
    std::vector<adj> edge;
    graph(int n,int m){
        nd=n;
        edg=m;
        node=new std::vector<vrtx>[nd];
    }
    void add_dir(int s,int t,int64_t c){
        node[s].push_back({t,c});
        edge.push_back({s,t,c});
    }
    void add_undir(int s,int t,int64_t c){
        node[s].push_back({t,c});
        node[t].push_back({s,c});
        edge.push_back({s,t,c});
    }
    void dlt_dir(int s,int t){
        for(int i=0;i<node[s].size();i++){
            if(node[s][i].to==t){
                node[s].erase(node[s].begin()+i);
                break;
            }
        }
    }
    void dlt_undir(int s,int t){
        for(int i=0;i<node[s].size();i++){
            if(node[s][i].to==t){
                node[s].erase(node[s].begin()+i);
                break;
            }
        }
        for(int i=0;i<node[t].size();i++){
            if(node[t][i].to==s){
                node[t].erase(node[t].begin()+i);
                break;
            }
        }
    }
    void refr(void){
        for(int i=0;i<nd;i++) std::vector<vrtx>().swap(node[i]);
        delete[] node;
        std::vector<adj>().swap(edge);
    }
    void dfs(int r,bool **vst);
    void bellford(int s,int64_t **d);
    void dijkstra(int s,int64_t **d);  // 負の閉路なし
    void bfs(int s,int64_t **d);  // 辺に重み無し or 木
    void cumulsum(int s,int64_t **d);  // 木
    void cumulprd(int s,int64_t **d);  // 木
};

void graph::dijkstra(int s,int64_t **d){
    for(int i=0;i<nd;i++) (*d)[i]=INT64_MAX/2;
    std::priority_queue<std::pair<int64_t,int>,std::vector<std::pair<int64_t,int>>,std::greater<std::pair<int64_t,int>>> que;
    (*d)[s]=0;
    que.push({0,s});
    while(!que.empty()){
        std::pair<int64_t,int> p=que.top();
        que.pop();
        if((*d)[p.second]<p.first) continue;
        for(vrtx i:node[p.second]){
            if((*d)[i.to]>(*d)[p.second]+i.cost){
                (*d)[i.to]=(*d)[p.second]+i.cost;
                que.push({(*d)[i.to],i.to});
            }
        }
    }
}

int main(void){
    int v,e;
    scanf("%i%i",&v,&e);
    graph g(v,e);
    int r;
    scanf("%i",&r);
    int s,t;
    i64 d;
    for(int i=0;i<e;i++){
        scanf("%i%i%lli",&s,&t,&d);
        g.add_dir(s,t,d);
    }
    i64 *dist=new i64[v];
    g.dijkstra(r,&dist);
    for(int i=0;i<v;i++){
        if(dist[i]==INT64_MAX/2) printf("INF\n");
        else printf("%lli\n",dist[i]);
    }
    return 0;
}

