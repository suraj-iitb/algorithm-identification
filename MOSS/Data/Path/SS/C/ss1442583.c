#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Vertex;

class Adjacent{
  double weight;
  Vertex* vertex;
public:
  Adjacent(double w,Vertex* v):weight(w),vertex(v){};
  bool operator>(const Adjacent &x)const{ return (weight>x.weight);}
  friend class Graph;
  friend class Vertex;
};

class Vertex{
  int value;
  bool flag;
  bool infinity;
  list<Adjacent> adj_list;
  Vertex():value(0),flag(false),infinity(true){}
  friend class Graph;
};

class Graph{
  vector<Vertex*> graph;
public:
  Graph(int size){
    graph.resize(size);
    for(int i=0;i<size;i++){
      graph[i]=new Vertex();
    }
  }

  ~Graph(){
    for(int i=0;i<(int)graph.size();i++){
      delete graph[i];
    }
  }

  void addEdge(int from,int to,int w){
    graph[from]->adj_list.push_back(Adjacent(w,graph[to]));
  }

  void dijkstra(int start){
    Vertex *v=graph[start];
    int n=0;
    bool check=false;
    priority_queue<Adjacent,vector<Adjacent>,greater<Adjacent> > pq;

    while(true){
      v->flag=true;
      n++;
      if(n==(int)graph.size())
	break;
      for(list<Adjacent>::iterator it=v->adj_list.begin();it!=v->adj_list.end();it++){
	Vertex* w=it->vertex;
	if(!w->flag){
	  if(w->infinity || w->value > v->value + it->weight){
	    w->infinity=false;
	    w->value = v->value + it->weight;
	    pq.push(Adjacent(w->value,w));
	  }
	}
      }

      while(true){
	if(pq.empty()){
	  check=true;
	  break;
	}
	v=pq.top().vertex;
	pq.pop();
	if(!v->flag) break;
      }

      if(check) break;

    }

    for(int i=0;i<(int)graph.size();i++){
      if(graph[i]->flag){
	cout<<graph[i]->value<<endl;
      }else{
	cout<<"INF"<<endl;
      }
    }

  }

};

int main(){
  int v=0;
  int e=0;
  int start = 0;
  cin>>v>>e>>start;
  Graph graph(v);
  for(int i=0;i<e;i++){
    int from,to,w;
    cin>>from>>to>>w;
    graph.addEdge(from,to,w);
  }
  graph.dijkstra(start);
  return 0;
}
