#include <iostream>
#include <vector>

#define INF 999999999
#define V_MAX 100000
#define E_MAX 500000
using namespace std;

struct edge {
  int start;
  int end;
  int cost;
};

/*
void input_G(vector<edge> &G, int e) {
  edge E;
  for(int i = 0; i < e; i++) {
    cin >> E.start >> E.end >> E.cost;
    G.push_back(E);
  }
}
*/

int d[V_MAX];
bool flag;
void shortest_path(vector<edge> &G, int v, int e, int r) {
  int cnt = 0;
  fill(d, d + v, INF);
  d[r] = 0;
  while(cnt < v) {
    bool update = false;
    for(int i = 0; i < e; i++) {
      edge E = G[i];
      if(d[E.start] != INF && d[E.end] > d[E.start] + E.cost) {
        d[E.end] = d[E.start] + E.cost;
        update = true;
      }
    }
    if( !update ) break;
    cnt++;
  }
  if(cnt == v) 
    flag = true;
}

int main(void) {
  int v, e, r;
  cin >> v >> e >> r;
  edge E;
  vector<edge> G;

  for(int i = 0; i < e; i++) {
    cin >> E.start >> E.end >> E.cost;
    G.push_back(E);
  }
  flag = false;
  shortest_path(G, v, e, r);
  if( !flag ){
		for(int i = 0; i < v; i++) {
			if(d[i] == INF) {
				cout << "INF" << endl;
			} else {
				cout << d[i] << endl;
			}
		}
	} else {
		cout << "NEGATIVE CYCLE" << endl;
	}

}
