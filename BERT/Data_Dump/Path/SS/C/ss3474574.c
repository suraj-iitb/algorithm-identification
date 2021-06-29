#include<iostream>
#include<vector>
#include<utility>
#include<climits>
using namespace std;

class MinHeap{
    vector<pair<int, int>> edges;
    int sz;
    int parent(int i){return (i-1)/2;}
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}
    void heapify(int i){
        int m = i, l = left(i), r = right(i);
        if(l < sz && edges[l].second < edges[i].second) m = l;
        if(r < sz && edges[r].second < edges[m].second) m = r;
        if(m != i){
            swap(edges[m], edges[i]);
            heapify(m);
        }
    }
public:
    MinHeap(): sz(0), edges(500000) {}
    pair<int, int> extractMin(){
        swap(edges[0], edges[sz-1]);
        sz--;
        heapify(0);
        return edges[sz];
    }
    void insert(pair<int, int> edge){
        int i = sz, p = parent(i);
        edges[i] = edge;
        sz++;
        while(p >= 0 && edges[p].second > edges[i].second){
            swap(edges[i], edges[p]);
            i = p;
            p = parent(i);
        }
    }
    bool empty(){
        return sz == 0;
    }
};

void dijkstra(vector<int>& dist, vector<vector<pair<int, int>>>& adjlist, MinHeap& heap, const int& r){
    heap.insert(make_pair(r, 0));
    while(!heap.empty()){
        pair<int, int> min_edge = heap.extractMin();
        int u = min_edge.first;
        for(int i = 0; i < adjlist[u].size(); i++){
            int v = adjlist[u][i].first, d = adjlist[u][i].second; 
            if(dist[v] > dist[u] + d){
                dist[v] = dist[u] + d;
                heap.insert(make_pair(v, d));
            }
        }
    }
}

int main(){
    int v, e, r, s, t, d;
    cin >> v >> e >> r;
    MinHeap heap = MinHeap();
    vector<vector<pair<int, int>>> adjlist(v);
    vector<int> dist(v, INT_MAX);
    dist[r] = 0;
    for(int i = 0; i < e; i++){
        cin >> s >> t >> d;
        adjlist[s].push_back(make_pair(t, d));
    }
    dijkstra(dist, adjlist, heap, r);
    for(int d : dist){
        if(d == INT_MAX) cout << "INF\n";
        else cout << d << endl;
    }
}

