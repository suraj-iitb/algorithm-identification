#include<stdio.h>
#include<assert.h>

namespace beet{
  
  template<typename T>
  struct Vector{
    int sz,cap;
    T *data;
    Vector():sz(0),cap(1){
      data = new T[cap];
    }    
    Vector(int sz):sz(sz),cap(sz<<1){
      data = new T[cap];
    }
    Vector(int sz,T t):sz(sz),cap(sz<<1){
      data = new T[cap];
      for(int i=0;i<sz;i++) data[i]=t;
    }
    ~Vector(){
      delete[] data;
    }
    void resolve(){
      T *tmp = new T[cap];
      for(int i=0;i<sz;i++) tmp[i]=data[i];
      delete[] data;
      data=tmp;
    }
    void push_back(T x){
      if(sz>=cap){
        cap<<=1;
        assert(sz<cap);
        resolve();
      }      
      data[sz++]=x;
    }
    void pop_back(){
      sz--;
    }
    int size() const{
      return sz;
    }
    const T operator[](int x) const{
      return data[x];
    }
    T& operator[](int x){
      assert(0<=x&&x<sz);
      return data[x];
    }
  };

  template<typename T>
  void swap(T &a,T &b){
    T x=a;
    a=b;
    b=x;
  }

  template<typename T>
  struct PriorityQueue{

    Vector<T> heap;
    PriorityQueue():heap(1){}
    
    void push(T t){
      heap.push_back(t);
      int v=heap.size()-1;
      while(v>>1){
        int p=v>>1;
        if(heap[v]<heap[p]) swap(heap[v],heap[p]);
        v=p;
      }
    }

    T top() const{
      return heap[1];
    }

    void dfs(int v){
      int l=(v<<1)|0;
      int r=(v<<1)|1;
      
      int nx=v;
      if(l<heap.size()&&heap[l]<heap[nx]) nx=l;
      if(r<heap.size()&&heap[r]<heap[nx]) nx=r;
      
      if(nx==v) return;
      swap(heap[v],heap[nx]);
      dfs(nx);
    }
    
    void pop(){
      assert(heap.size()>1);
      swap(heap[1],heap[heap.size()-1]);
      heap.pop_back();
      dfs(1);
    }

    bool empty() const{
      assert(heap.size()>=1);
      return heap.size()==1;
    }
  };
}
using namespace beet;

const int INF = 1e9;  
struct Node{
  int v,cost;
  Node(){}
  Node(int v,int cost):v(v),cost(cost){}
  bool operator<(const Node &a)const{
    return cost<a.cost;
  }
};
struct Edge{
  int to,cost;
  Edge(){}
  Edge(int to,int cost):to(to),cost(cost){}
};
  
int main(){
  int V,E,r;
  scanf("%d %d %d",&V,&E,&r);
  
  Vector<Vector<Edge> > G(V);
  for(int i=0;i<E;i++){
    int s,t,d;
    scanf("%d %d %d",&s,&t,&d);
    G[s].push_back(Edge(t,d));
  }
  
  PriorityQueue<Node> pq;
  Vector<int> dist(V,INF);
  dist[r]=0;
  pq.push(Node(r,dist[r]));
  while(!pq.empty()){
    Node res=pq.top();pq.pop();
    int v=res.v;
    
    if(dist[v]<res.cost) continue;
    for(int i=0;i<G[v].size();i++){
      int u=G[v][i].to,d=G[v][i].cost;
      if(dist[v]+d>=dist[u]) continue;
      dist[u]=dist[v]+d;
      pq.push(Node(u,dist[u]));
    }
  }
  
  for(int i=0;i<V;i++){
    if(dist[i]<INF) printf("%d\n",dist[i]);
    else printf("INF\n");
  }
  
  return 0;
}

