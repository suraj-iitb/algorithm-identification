#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

const int inf=1e9;
const int64_t inf64=1e18;
const double eps=1e-9;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

template<class edge_type,class weight_type> std::pair<std::vector<weight_type>,bool> bellmanford(const int size,const std::vector<edge_type> &edges ,const int start){
    std::vector<weight_type> dist(size,std::numeric_limits<weight_type>::max());
    bool negative_cycle=false;
    dist[start]=0;
    for(int i=0; i<size; ++i){
        bool update=false;
        for(const edge_type &e:edges){
            const int u=e.from,v=e.to;
            if(dist[u]!=std::numeric_limits<weight_type>::max() and dist[v]>dist[u]+e.weight){
                dist[v]=dist[u]+e.weight;
                update=true;
            }
        }
        if(!update) break;
        if(i==size-1 and update) negative_cycle=true;
    }
    return std::make_pair(dist,!negative_cycle);
}

struct edge{
    int from,to,weight;
};

void solve(){
    int v,e,r;
    cin >> v >> e >> r;
    vector<edge> edges;
    rep(i,0,e){
        int s,t,d;
        cin >> s >> t >> d;
        edges.push_back(edge{s,t,d});
    }
    auto ans=bellmanford<edge,int>(v,edges,r);
    if(!ans.second){
        cout << "NEGATIVE CYCLE" << endl;
        return;
    }
    rep(i,0,v){
        if(ans.first[i]==std::numeric_limits<int>::max()) cout << "INF" << endl;
        else cout << ans.first[i] << endl;
    }
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}
