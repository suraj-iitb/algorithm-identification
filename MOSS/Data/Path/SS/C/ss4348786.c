#include <iostream>
#include <queue>
using namespace std;
#define MAX 100010
#define CLEAR 0
#define GRAY 1
#define OLD 2

vector<pair<int,int> > adj[MAX];


void ds(int n,int from){

  priority_queue<pair<int,int> >pq;
  int weight[MAX];
  int state[MAX];
  for(int i=0 ;i<n;i++){
    weight[i] = __INT_MAX__;;
    state[i] = CLEAR;
  }

  weight[from] = 0;
  state[from] = GRAY;
  pq.push(make_pair(0,from));

  while(!pq.empty()){
    pair<int,int> first = pq.top();
    pq.pop();

    int u = first.second;
    state[u] = OLD;
    if(weight[u]<first.first*(-1)) continue;

    for(int i=0; i<adj[u].size(); i++){
      int v = adj[u][i].first;
      if(state[v] == OLD)continue;
      if(weight[v] > weight[u] + adj[u][i].second){
	weight[v] = weight[u] + adj[u][i].second;
	pq.push(make_pair(weight[v] * -1, v));
	state[v] = GRAY;
      }
    }
  }

  for(int i=0; i<n; i++){
    if(weight[i] ==  __INT_MAX__){cout << "INF" << endl;}
    else{cout << weight[i] << endl;}
  }
}

int main(){
    int V,E,r;
    int s,t,d;
    cin >>V>>E>>r;
    for(int i=0; i<E;i++){
      cin >> s >> t >> d;
      adj[s].push_back(make_pair(t,d));
    }
    ds(V,r);
}
