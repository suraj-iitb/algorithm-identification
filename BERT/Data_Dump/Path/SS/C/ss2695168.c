#include <bits/stdc++.h>
template<typename T>
struct edge{
    int f,t;
    T c;
    int id;
    edge(){};
    edge(int f,int t,T c,int id = 0):f(f),t(t),c(c),id(id){};
    bool operator< (const edge &s){
        return c < s.c;
    }
};

template<typename T>
struct graph{
    std::vector<std::vector<edge<T> > > data;
    graph(int v):data(v){};
    void add_edge(edge<T> &e){
        data[e.f].push_back(e);
    }
    void add_edge(int f,int t,T c){
        data[f].emplace_back(f,t,c);
    }
    size_t size(){
        return data.size();
    }
    std::vector<edge<T>> make_edges(){
        std::vector<edge<T>> r;
        for(auto &i:data)std::copy(i.begin(),i.end(),std::back_inserter(r));
        return r;
    }
};

template<typename T>
std::vector<T> dijkstra(graph<T> &g,int s){
    using state = std::pair<T,int>;
    //priority_queue
    std::priority_queue<state,std::vector<state>,std::greater<state>> q;
    q.emplace((T)0,s);
    //data init
    std::vector<T> data(g.size(),std::numeric_limits<T>::max()/4);
    data[s] = (T)0;
    //solve
    while(!q.empty()){
        state cur = q.top();q.pop();
        T c = cur.first; int pos = cur.second;
        if(data[pos] < c)continue;
        for(auto &e : g.data[pos]){
            if(c + e.c < data[e.t]){
                data[e.t] = c + e.c;
                q.emplace(c + e.c, e.t);
            }
        }
    }
    return data;
}

int main(){
    using namespace std;
    using i64 = long long int;
    int v,e,r;
    cin >> v >> e >> r;
    graph<i64> g(v);
    int f,t;i64 d;
    for(int i=0;i<e;++i){
        cin >> f >> t >> d;
        g.add_edge(f,t,d);
    }
    vector<i64> res = dijkstra(g,r);
    i64 INF = numeric_limits<i64>::max()/4;
    for(auto &x:res){
        if(x!=INF)cout << x << endl;
        else cout << "INF" << endl;
    }
}
