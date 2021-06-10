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
    bool islnk(void);
    void dfs(int r,bool **vst);  // vst[] は呼び出し前に 0 で初期化
    bool ispls(void);
    void bellford(int s,int64_t **d);
    void dijkstra(int s,int64_t **d);  // 負の閉路なし
    void bfs(int s,int64_t **d);  // 辺に重み無し or 木
    void waflo(bool isdir,int64_t ***d);
    void cumulsum(int s,int64_t **d);  // 木
    void cumulprd(int s,int64_t **d);  // 木
};

bool graph::ispls(void){
    int64_t *d=new int64_t[nd];
    for(int i=0;i<nd;i++) d[i]=0;
    for(int i=0;i<nd;i++){
        for(int j=0;j<edg;j++){
            if(d[edge[j].to]>d[edge[j].start]+edge[j].cost){
                d[edge[j].to]=d[edge[j].start]+edge[j].cost;
                if(i==nd-1) return 0;
            }
        }
    }
    return 1;
}

void graph::waflo(bool isdir,int64_t ***d){
    for(int i=0;i<nd;i++){
        for(int j=0;j<nd;j++){
            if(i==j) (*d)[i][j]=0;
            else (*d)[i][j]=INT64_MAX/2;
        }
    }
    if(isdir){
        for(int i=0;i<edg;i++){
            (*d)[edge[i].start][edge[i].to]=edge[i].cost;
        }
    }
    else{
        for(int i=0;i<edg;i++){
            (*d)[edge[i].start][edge[i].to]=edge[i].cost;
            (*d)[edge[i].to][edge[i].start]=edge[i].cost;
        }
    }
    for(int k=0;k<nd;k++){
        for(int i=0;i<nd;i++){
            for(int j=0;j<nd;j++){
                if((*d)[i][j]>(*d)[i][k]+(*d)[k][j]) (*d)[i][j]=(*d)[i][k]+(*d)[k][j];
            }
        }
    }
}

int main(void){
    int v,e;
    scanf("%i%i",&v,&e);
    graph g(v,e);
    int s,t;
    i64 d;
    for(int i=0;i<e;i++){
        scanf("%i%i%lli",&s,&t,&d);
        g.add_dir(s,t,d);
    }
    if(!g.ispls()){
        printf("NEGATIVE CYCLE\n");
        return 0;
    }
    i64 **dist=new i64*[v];
    for(int i=0;i<v;i++) dist[i]=new i64[v];
    g.waflo(1,&dist);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(dist[i][j]>=(INT64_MAX/2)/2) printf("INF");
            else printf("%lli",dist[i][j]);
            if(j<v-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}

